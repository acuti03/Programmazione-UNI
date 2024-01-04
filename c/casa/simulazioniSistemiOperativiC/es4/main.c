#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX 128

typedef int pipe_t[2];
static volatile sig_atomic_t counter = 0;


void handler_count() {
	printf("handler_count: numero di richieste servite: %d\n", counter);
	exit(0);
}

void handler_start() {
	printf("handler_start\n");
}


int main(int argc, char **argv){

	pid_t pid1, pid2;
	int i, status, nread, fd, N;
	char buff[MAX], cognome[MAX], genere[MAX], path[MAX];
	pipe_t p1p2;


	if(argc != 2){
		fprintf(stderr, "Utilizzo: ./cerca <archivio>");
		exit(1);
	}

	if(argv[1][0] != '/'){
		fprintf(stderr, "%s deve essere un nome assoluto di directory", argv[1]);
		exit(2);
	}

	if((fd = open(argv[1], O_DIRECTORY)) < 0){
		fprintf(stderr, "%s non è una directory", argv[1]);
		exit(3);
	}

	close(fd);

	signal(SIGINT, handler_count);

	
	while(1) {
		
		printf("Inserire il cognome dell'autore da cercare:\n");
		scanf("%s", cognome);

		if(strcmp(cognome, "fine") == 0){
			break;
		}

		printf("Inserire il genere d'interesse:\n");
		scanf("%s", genere);
		
		if(strcmp(genere, "fine") == 0){
			break;
		}

		sprintf(path, "%s/%s", argv[1], genere);

		if((fd = open(path, O_RDONLY)) < 0){
			if(fd == ENOENT){
				printf("Non è possibile aprire il file: %s", path);
				perror("mancano i permessi di lettuta");
				exit(4);
			}
		}

		close(fd);

		printf("Inserire il numero di risultati da visualizzare:\n");
		scanf("%d", &N);

		if(N < 0){
			perror("N deve essere un intero positivo");
			exit(5);
		}

		if(pipe(p1p2) < 0){
			perror("Errore creazione pipe");
			exit(6);
		}

		if((pid1 = fork()) < 0){
			perror("Errore con creazione della fork");
			exit(7);
		}
		else if(pid1 == 0){
			signal(SIGINT, SIG_DFL);
			signal(SIGUSR1, handler_start);

			pause();

			close(p1p2[0]);

			close(1);
			dup(p1p2[1]);
			close(p1p2[1]);

			execlp("grep", "grep", cognome, path, NULL);
			perror("execlp");
			exit(8);
		}

		if((pid2 = fork()) < 0){
			perror("Errore con creazione della fork");
			exit(7);
		}
		else if(pid2 == 0){
			signal(SIGINT, SIG_DFL);

			close(p1p2[1]);

			close(0);
			dup(p1p2[0]);
			close(p1p2[0]);

			sprintf(buff, "%d", N);
			execlp("head", "head", "-n", buff, NULL);
			perror("execlp");
			exit(8);
		}

		close(p1p2[0]);
		close(p1p2[1]);

		sleep(1);
		kill(pid1, SIGUSR1);

		wait(&status);
		wait(&status);

		counter++;
	}
	
	printf("numero di richieste servite: %d\n", counter);

	return 0;
}
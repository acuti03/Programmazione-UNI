#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>

#define MAX 128
#define DATE 9

static volatile sig_atomic_t counter = 0;

typedef int pipe_t[2];

void handler(int s){
	printf("Numero di richieste servite: %d", counter);
	exit(0);
}


int main(int argc, char **argv){
	
	int fd, status, pid1, pid2;
	char path[MAX], argomento[MAX], data[DATE];
	pipe_t p1p2;

	if(argc != 2){
		fprintf(stderr, "Utilizzo: ./trova_news <dir>");
		exit(1);
	}

	if(argv[1][0] != '/'){
		fprintf(stderr, "<dir> deve essere un nome assoluto di directory");
		exit(2);
	}

	if((fd = open(argv[1], O_DIRECTORY)) < 0){
		fprintf(stderr, "La directory non esiste");
		exit(3);
	}

	close(fd);

	signal(SIGINT, handler);

	printf("Inserire l'argomento:\n");
	scanf("%s", argomento);

	printf("Inserire la data:\n");
	scanf("%s", data);

	while (strcmp(argomento, "fine")){

		if(atoi(data) == 0){
			fprintf(stderr, "Inserire una data valida. Formato: YYYYMMDD");
			exit(4);
		}

		sprintf(path, "%s/%s.txt", argv[1], data);

		if((fd = open(path, O_RDONLY)) < 0){

			if(errno == ENOENT){
				fprintf(stderr, "Mancano i permessi di lettura");
				exit(5);
			}

			fprintf(stderr, "Errore nell'apertura del file");
			exit(6);
		}

		if(pipe(p1p2) < 0){
			fprintf(stderr, "Errore creazione pipe");
			exit(7);
		}

		if((pid1 = fork()) < 0){
			fprintf(stderr, "Errore fork");
			exit(8);
		}
		else if(pid1 == 0){

			signal(SIGINT, SIG_DFL);

			close(p1p2[0]);

			close(1);
			dup(p1p2[1]);
			close(p1p2[1]);

			execlp("grep", "grep", argomento, path, NULL);
			fprintf(stderr, "Errore grep");
			exit(9);
		}

		if((pid2 = fork()) < 0){
			fprintf(stderr, "Errore fork");
			exit(8);
		}
		else if(pid2 == 0){

			signal(SIGINT, SIG_DFL);
			
			close(p1p2[1]);

			close(0);
			dup(p1p2[0]);
			close(p1p2[0]);

			execlp("sort", "sort", "-n" "-r", NULL);
		}

		close(p1p2[0]);
		close(p1p2[1]);
		wait(&status);
		wait(&status);
		counter++;

		printf("Inserire l'argomento:\n");
		scanf("%s", argomento);

		printf("Inserire la data:\n");
		scanf("%s", data);
	}
	
	printf("Numero di richieste servite: %d", counter);

	return 0;
}

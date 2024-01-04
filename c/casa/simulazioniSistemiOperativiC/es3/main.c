#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>

#define MAX 128

static volatile sig_atomic_t counter = 0;

void handler(int s){

	printf("ricevuto interrupt da tastiera, servite %u richieste", counter);
	exit(0);
}


int main(int argc, char  *argv[]){
	
	int i, status, p1p2[2], p2p0[2], pid, fd, nread;
	char nome_fornitore[MAX], nome_applicazione[MAX], file_path[MAX], result_str[MAX];

	if(argc != 2){
		fprintf(stderr, "Utilizzo: ./conta_vm <dir>");
		exit(1);
	}

	if(argv[1][0] != '/'){
		fprintf(stderr, "<dir> deve essere un direttorio assoluto");
		exit(2);
	}

	if((fd = open(argv[1], O_DIRECTORY)) < 0){
		fprintf(stderr, "<dir> non è una directory");
		exit(3);
	}

	close(fd);

	signal(SIGINT, handler);

	printf("Inserisci il nome di un fornitore di servizio: \n");
	scanf("%s", nome_fornitore);

	while (strcmp(nome_fornitore, "fine")){
		sprintf(file_path, "%s/%s.txt", argv[1], nome_fornitore);

		if((fd = open(file_path, O_RDONLY)) < 0){
			if(errno == ENOENT) {
				printf("Il file che contiene i dati relativi al Cloud Provider \"%s\" non esiste.\n", nome_fornitore);
				printf("Inserire il nome di un Cloud Provider, o \"fine\" per uscire:\n");
				scanf("%s", nome_fornitore);
				continue;
			}
			perror("Errore tentando di aprire il file che contiene i dati per il Cloud Provider specificato.\n");
			exit(4);
		}
		close(fd);

		printf("Inserire il nome dell'applicazione:\n");
		scanf("%s", nome_applicazione);

		if(pipe(p1p2) < 0){
			perror("pipe error");
			exit(5);
		}

		if((pid = fork()) < 0){
			perror("fork error");
			exit(6);
		}

		else if(pid == 0){
			signal(SIGINT, SIG_DFL);
			close(p1p2[0]);

			close(1);
			dup(p1p2[1]);
			close(p1p2[1]);
			execlp("grep", "grep", nome_applicazione, file_path, NULL);
			perror("P1; execlp");
			exit(7);
		}

		close(p1p2[1]);

		if(pipe(p2p0) < 0){
			perror("pipe error");
			exit(5);
		}

		if((pid = fork()) < 0){
			perror("fork error");
			exit(6);
		}
		else if(pid == 0){
			signal(SIGINT, SIG_DFL);

			close(p2p0[0]);

			close(0);
			dup(p1p2[0]);
			close(p1p2[0]);

			close(1);
			dup(p2p0[1]);
			close(p2p0[1]);

			execlp("grep", "grep", "-c", "operativa", NULL);
			perror("P2; execlp");
			exit(7);
		}

		close(p1p2[0]);
		close(p1p2[1]);
		close(p2p0[1]);


		nread = read(p2p0[0], result_str, MAX-1);
		close(p2p0[0]);
		result_str[nread] = '\0';

		printf("Cloud Provider: %s\nApplicazione: %s\nIstanze Operative: %s\n\n", nome_fornitore, nome_applicazione, result_str);
		counter++;

		wait(&status);
		wait(&status);

		printf("Inserire il nome di un Cloud Provider, o \"fine\" per uscire:\n");
		scanf("%s", nome_fornitore);
	}
	
	printf("Numero di richieste servite: %u\n", counter); 

	return 0;
}
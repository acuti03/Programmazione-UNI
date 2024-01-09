#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>

#define MAX 128

static volatile sig_atomic_t counter = 0;

typedef int pipe_t[2];

void handler(int s){

	printf("Numero di byte ricevuti: %d", counter);
	exit(0);
}


int main(int argc, char **argv){

	int status, fd, pid1, pid2, nread, nwrite;
	pipe_t p0p1, p0p2;
	char filepath[MAX], buff[128];

	if(argc != 3){
		fprintf(stderr, "Utilizzo: ./test_eseguiti <dir> <data>");
		exit(1);
	}

	if(argv[1][0] == '/'){
		fprintf(stderr, "<dir> deve essere un nome relativo di directory");
		exit(2);
	}

	if((fd = open(argv[1], O_DIRECTORY)) < 0){
		fprintf(stderr, "<dir> non è una directory");
		exit(3);
	}

	close(fd);

	sprintf(filepath, "%s/%s.txt", argv[1], argv[2]);

	if((fd = open(filepath, O_RDONLY)) < 0){
		if(errno == ENOENT){
			fprintf(stderr, "Mancano i permessi di lettura");
			exit(4);
		}
	}

	close(fd);

	signal(SIGINT, handler);

	if(pipe(p0p1) < 0){
		perror("Errore crezione pipe");
		exit(5);
	}

	if(pipe(p0p2) < 0){
		perror("Errore crezione pipe");
		exit(5);
	}

	if((pid1 = fork()) < 0){
		perror("Errore fork");
		exit(6);
	}
	else if(pid1 == 0){
		signal(SIGINT, SIG_DFL);

		close(p0p1[1]);
		close(p0p2[0]);

		while (1){
			nread = read(p0p1[0], buff, sizeof(buff)-1);

			if(nread < 0){
				perror("Errore read");
				exit(7);
			}

			buff[nread] = '\0';

			if((pid2 = fork()) < 0){
				perror("Errore fork");
				exit(6);
			}
			else if(pid2 == 0){
				signal(SIGINT, SIG_DFL);

				close(p0p1[0]);

				close(1);
				dup(p0p2[1]);
				close(p0p2[1]);

				execlp("grep", "grep", buff, filepath, NULL);
				perror("Errore execlp");
				exit(8);
			}

			wait(&status);
		}
		
	}

	close(p0p1[0]);
	close(p0p2[1]);

	while (1){
		printf("Inserire il nome del refartore:\n");
		scanf("%s", buff);

		nwrite = write(p0p1[1], buff, strlen(buff)+1);

		printf("prova");

		if(nwrite != (int)(strlen(buff) + 1)){
			perror("write error");
			exit(9);
		}

		nread = read(p0p2[0], buff, sizeof(buff)-1);

		if(nread < 0){
			perror("Errore read");
			exit(7);
		}

		buff[nread] = '\0';
		printf("%s", buff);
		counter += nread;
	}
	

	return 0;
}
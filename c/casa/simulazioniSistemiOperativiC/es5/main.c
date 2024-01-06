#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX 128
#define DIR "/var/local/ticket"

static volatile sig_atomic_t counter = 0;

void handler(int sig){
	printf("handler_count: numero di richieste servite: %d\n", counter);
	exit(0);
}


int main(int argc, char **argv){
	
	int i, nread, status, pid1, pid2, pid3, N, fd, giorno, mese, anno, p1p2[2], p2p3[2];
	char buff[MAX], path[MAX], data[MAX], nstr[MAX];


	if(argc != 3){
		fprintf(stderr, "Utilizzo: ./trova_biglietti <destinazione> <N>");
		exit(1);
	}

	if((N = atoi(argv[2])) == 0){
		fprintf(stderr, "<N> deve essere un intero positivo");
		exit(2);
	}

	sprintf(path, "%s/%s.txt", DIR, argv[1]);

	if((fd = open(path, O_RDONLY)) < 0){
		(errno == ENOENT) ? perror("Mancano i servizi di lettura") : 1;
		exit(3);
	}

	close(fd);

	printf("Inserire il giorno, il mese e l'anno:\n");
	scanf("%d%d%d", &giorno, &mese, &anno);

	if(giorno < -1 || mese < -1 || anno < -1 || giorno == 0 || mese == 0 || anno == 0){
		fprintf(stderr, "Il giorno, il mese e l'anno devono essere degli interi positivi o -1 per interrompere");
		exit(4);
	}
	else if(giorno > 31 || mese > 12){
		fprintf(stderr, "Il giorno deve essere compreso tra 1 e 31 e il mese tra 1 e 12");
		exit(5);
	}

	signal(SIGINT, handler);

	while (giorno != -1 && giorno != -1 && anno != -1) {
		
		sprintf(data, "%02d%02d%04d", giorno, mese, anno);

		if(pipe(p1p2) < 0){
			perror("Errore creazione pipe");
			exit(6);
		}

		if(pipe(p2p3) < 0){
			perror("Errore creazione pipe");
			exit(6);
		}

		if((pid1 = fork()) < 0){
			perror("Errore fork");
			exit(7);
		}
		else if(pid1 == 0){
			signal(SIGINT, SIG_DFL);

			close(p2p3[0]);
			close(p2p3[1]);
			close(p1p2[0]);

			close(1);
			dup(p1p2[1]);
			close(p1p2[1]);

			execlp("grep", "grep", data, path, NULL);
			perror("Errore grep");
			exit(8);
		}

		if((pid2 = fork()) < 0){
			perror("Errore fork");
			exit(7);
		}
		else if(pid2 == 0){
			signal(SIGINT, SIG_DFL);

			close(p1p2[1]);
			close(p2p3[0]);

			close(0);
			dup(p1p2[0]);
			close(p1p2[0]);

			execlp("sort", "sort", "-n", NULL);
			perror("Errore sort");
			exit(9);
		}

		if((pid3 = fork()) < 0){
			perror("Errore fork");
			exit(7);
		}
		else if(pid3 == 0){
			signal(SIGINT, SIG_DFL);

			close(p1p2[0]);
			close(p1p2[1]);
			close(p2p3[1]);

			close(0);
			dup(p2p3[0]);
			close(p2p3[0]);

			sprintf(nstr, "%d", N);

			execlp("head", "head", "-n", nstr, NULL);
			perror("Errore head");
			exit(10);
		}

		close(p1p2[0]);
		close(p1p2[1]);
		close(p2p3[0]);
		close(p2p3[1]);

		wait(&status);
		wait(&status);
		wait(&status);

		counter++;

		printf("Inserire il giorno, il mese e l'anno:\n");
		scanf("%d%d%d", &giorno, &mese, &anno);

		if(giorno < -1 || mese < -1 || anno < -1 || giorno == 0 || mese == 0 || anno == 0){
			fprintf(stderr, "Il giorno, il mese e l'anno devono essere degli interi positivi o -1 per interrompere");
			exit(4);
		}
		else if(giorno > 31 || mese > 12){
			fprintf(stderr, "Il giorno deve essere compreso tra 1 e 31 e il mese tra 1 e 12");
			exit(5);
		}
	}
	
	printf("Richieste servite: %u\n", counter);
	return 0;
}
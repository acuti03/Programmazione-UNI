#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SIZE 80


int timeout;

void gestore_ctrlc(int segnale){
	printf("Ricevuto cntrl-c, timeout e termino\n");
	alarm(timeout);
}

void gestore_alarm(int segnale){
	printf("Termino\n");
	kill(0, SIGKILL);
}


int main(int argc, char **argv){

	int i, j, status, Nproc, nread, p0pi[SIZE][2], pip0[SIZE][2];
	char buff[SIZE], nomeFile[SIZE];

	signal(SIGINT, gestore_ctrlc);
	signal(SIGALRM, gestore_alarm);

	if(argc < 3){
		fprintf(stderr, "Utilizzo: ./ricercaFile <timeout> <s1> <s1>...");
		exit(1);
	}

	Nproc = argc - 2;
	timeout = atoi(argv[1]);

	for(i = 0; i < Nproc; i++){
		pipe(p0pi[i]);
		pipe(pip0[i]);
	}

	for(i = 0; i < Nproc; i++){

		if(fork() == 0){ // Figlio
			signal(SIGINT, SIG_IGN);
			signal(SIGALRM, SIG_IGN);

			for(j = 0; j < Nproc; j++){

				if(j != i){
					close(p0pi[j][0]);
					close(p0pi[j][1]);
					close(pip0[j][0]);
					close(pip0[j][1]);
				}
				close(p0pi[i][1]);
				close(pip0[i][0]);
			}

			while(1) {
				nread = read(p0pi[i][0], nomeFile, SIZE);

				if(fork() == 0){
					close(1);
					dup(pip0[i][0]);

					close(p0pi[i][0]);
					close(pip0[i][1]);

					printf("%s", argv[i+2]);

					execl("/bin/grep", "grep", "-c", argv[i+2], nomeFile, NULL);
				}

				wait(&status);
			}
			exit(2);
		}
	}

	for(i = 0; i < Nproc; i++){
		close(p0pi[i][0]);
		close(pip0[i][1]);
	}

	while(1) {
		printf("Inserire il nome di un file:\n");
		scanf("%s", nomeFile);

		for(i = 0; i < Nproc; i++){
			write(p0pi[i][1], nomeFile, strlen(nomeFile) + 1);
			printf("prova");
		}

		for(i = 0; i < Nproc; i++){
			nread = read(pip0[i][0], buff, SIZE);
			buff[nread-1] = '\0';

			printf("Padre: la stringa %s compare nel file %s %s volte", argv[i+2], nomeFile, buff);
		}
	}

	return 0;
}
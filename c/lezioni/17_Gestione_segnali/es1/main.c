#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>

enum Bool {
	FALSE,
	TRUE
};

static volatile sig_atomic_t cnt = 0;

typedef struct sigaction Sigaction;

void gestore(int signo){
	printf("Il processo %d ha eseguito %d iterazioni per il segnale %d\n", getpid(), cnt, signo);
	exit(0);
}


int main(int argc, char **argv){

	pid_t *pid;
	int i, status;

//	Controllo degli argomenti
	if(argc != 3){
		fprintf(stderr, "Utilizzo: ./itercounter <num_processi> <secondi>\n");
		exit(1);
	}

	if(atoi(argv[1]) <= 0){
		fprintf(stderr, "<num_processi> deve essere positivo");
		exit(2);
	}

	if(atoi(argv[2]) <= 0){
		fprintf(stderr, "<secondi> deve essere positivo");
		exit(3);
	}

//	Alloco dinamicamente i byte a seconda del numero di processi
	pid = (int *)malloc(atoi(argv[1]) * sizeof(int));

//	Genero i figli
	for(i = 0; i < atoi(argv[1]); i++){
		pid[i] = fork();

		if(pid[i] < 0){
			perror("Errore nella fork\n");
			exit(4);
		}

//		Codice del figlio
		else if(pid[i] == 0){
			Sigaction sa;

			sigemptyset(&sa.sa_flags);
			sa.sa_flags = 0;
			sa.sa_handler = gestore;

			if(sigaction(SIGUSR1, &sa, NULL) < 0) {
				perror("sigaction");
				exit(-3);
			}

			while(TRUE){
				sleep(1);
				cnt++;
			}
		}
		sleep(atoi(argv[2]));
	}

//	Codice del padre
	sleep(atoi(argv[2]));

//	Invio SIGURS1 a tutti i processi figli
	for(i = 0; i < atoi(argv[1]); i++){
		kill(pid[i], SIGUSR1);
	}

//	Libero la memoria
	free(pid);

	for(i = 0; i < atoi(argv[1]); i++){
		wait(&status);
	}

	return 0;
}
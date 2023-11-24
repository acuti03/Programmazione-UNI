#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>
#include <time.h>

typedef struct sigaction Sigaction;

enum Bool {
	FALSE,
	TRUE,
};

static volatile sig_atomic_t cnt = 0;
static volatile sig_atomic_t child_index;
static volatile sig_atomic_t nChildren;
static volatile sig_atomic_t flag = FALSE;

void sigusr1_handler(int signo){
	printf("Child %d: incrementato il contatore\n", child_index);
	printf("Nuovo valore contatore child %d: %d\n", child_index, cnt);
	cnt++;
	exit(0);
}

void sigusr2_handler(int signo){
	printf("Child %d: decrementato il contatore\n", child_index);
	printf("Nuovo valore contatore child %d: %d\n", child_index, cnt);
	cnt--;
	exit(0);
}

void sigint_child_handler(int signo){
	printf("child %d: terminazione con valore counter: %d", child_index, cnt);
	exit(0);
}

void sigint_parent_handler(int signo){
	int status, i;

	printf("Ricevuto CTRL-C --> Attendo la sincronizzazione con i children\n");

	for(i = 0; i < nChildren; i++){
		wait(&status);
	}

	printf("Tutti i children terminati, chiudo il programma\n");
	flag = TRUE;
}



int main(int argc, char **argv){

	srand(time(NULL));
	Sigaction sigurs1, sigurs2, sigint, sigint_parent;
	pid_t pid;
	int i, *children;

//	Controllo dei parametri
	if(argc != 2){
		fprintf(stderr, "Utilizzo: ./figlicounter <nChildren>\n");
		exit(1);
	}

	if(atoi(argv[1]) <= 0){
		fprintf(stderr, "<nChildren> deve essere un intero positivo");
		exit(2);
	}

	nChildren = atoi(argv[1]);
	children = (int *)malloc(nChildren * sizeof(int));

	for(i = 0; i < atoi(argv[0]); i++){
		pid = fork();

		if(pid < 0){
			perror("Errore nella fork\n");
			exit(5);
		}
		else if(pid == 0){
			child_index = i;

			sigemptyset(&sigurs1.sa_flags);
			sigurs1.sa_flags = 0;
			sigurs1.sa_handler = sigusr1_handler;

			if(sigaction(SIGUSR1, &sigurs1, NULL) < 0) {
				perror("Errore nel gestore di sigurs1");
				exit(-3);
			}

			sigemptyset(&sigurs2.sa_flags);
			sigurs2.sa_flags = 0;
			sigurs2.sa_handler = sigusr2_handler;

			if(sigaction(SIGUSR2, &sigurs2, NULL) < 0) {
				perror("Errore nel ");
				exit(-3);
			}

			sigemptyset(&sigint.sa_flags);
			sigint.sa_flags = 0;
			sigint.sa_handler = sigint_child_handler;

			if(sigaction(SIGINT, &sigint, NULL) < 0) {
				perror("sigaction");
				exit(-3);
			}

			while (TRUE){
				pause();
			}
		}

		children[i] = pid;
	}

	sigemptyset(&sigint_parent.sa_flags);
	sigint_parent.sa_flags = 0;
	sigint_parent.sa_handler = sigint_parent_handler;

	if(sigaction(SIGUSR2, &sigint_parent, NULL) < 0) {
		perror("sigaction");
		exit(-3);
	}

	while (!flag){
		int random_index = rand() % atoi(argv[1]);
		int sig = ((rand() % 2) == 0 ? SIGUSR1 : SIGUSR2);
		kill(children[random_index], sig);
		sleep(2);
	}
	
	return 0;
}
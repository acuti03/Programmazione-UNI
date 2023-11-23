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

static volatile sig_atomic_t cnt = 0;
static volatile sig_atomic_t child_index = 0;
static volatile sig_atomic_t nChildren = 0;
static volatile sig_atomic_t flag = FALSE;

enum Bool {
	FALSE,
	TRUE,
};

void gestore1(int signo){
	printf("Child %d: incrementato il contatore\n", child_index);
	printf("Nuovo valore contatore child %d: %d\n", child_index, cnt);
	cnt++;
	exit(0);
}

void gestore2(int signo){
	printf("Child %d: decrementato il contatore\n", child_index);
	printf("Nuovo valore contatore child %d: %d\n", child_index, cnt);
	cnt--;
	exit(0);
}

void gestoreint(int signo){
	printf("child %d: terminazione con valore counter", child_index, cnt);
	exit(0);
}

void gestoreparent(int signo){
	int status;
}

int main(int argc, char **argv){
	srand(time(NULL));
	pid_t pid;
	int i, pid_index, *children;

	children = (int *)malloc(atoi(argv[0]) * sizeof(int));

	for(i = 0; i < atoi(argv[0]); i++){
		pid = fork();

		if(pid < 0){
			perror("Errore nella fork\n");
			exit(5);
		}
		else if(pid == 0){
			pid_index = i;

			Sigaction sa;

			sigemptyset(&sa.sa_flags);
			sa.sa_flags = 0;
			sa.sa_handler = gestore1;

			if(sigaction(SIGUSR1, &sa, NULL) < 0) {
				perror("sigaction");
				exit(-3);
			}

			sigemptyset(&sa.sa_flags);
			sa.sa_flags = 0;
			sa.sa_handler = gestore2;

			if(sigaction(SIGUSR2, &sa, NULL) < 0) {
				perror("sigaction");
				exit(-3);
			}

			sigemptyset(&sa.sa_flags);
			sa.sa_flags = 0;
			sa.sa_handler = gestoreint;

			if(sigaction(SIGINT, &sa, NULL) < 0) {
				perror("sigaction");
				exit(-3);
			}

			while (TRUE){
				pause();
			}
		}

		children[i] = pid;
	}

	Sigaction sa;
	sigemptyset(&sa.sa_flags);
	sa.sa_flags = 0;
	sa.sa_handler = gestore2;

	if(sigaction(SIGUSR2, &sa, NULL) < 0) {
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
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX 256
#define N 20

void handler(int s){
	int status;
	wait(&status);
}


int main(int argc, char *argv[]){

	int pid, pid_n1, pid_n2;
	int i, Nproc, nread;
	int pip0[N][2], n1n2[2], n2p1[2];
	char buff[MAX], buffer[MAX];
	
	if(argc < 2){
		fprintf(stderr, "Utilizzo: ./trova_vini <cantina1> ... <cantinaN>");
		exit(1);
	}

	signal(SIGINT, SIG_IGN);
	signal(SIGCHLD, handler); // utile per intercettare i figli che terminano cosi fanno la wait

	Nproc = argc - 1;

	if(Nproc > MAX){
		fprintf(stderr, "Inserire al massimo %d cantine", N);
		exit(2);
	}

	printf("Inserire il vino da cercare:\n");
	scanf("%s", buffer);

	while (strcmp(buffer, "fine")){

		for(i = 0; i <Nproc; i++){

			if(pipe(pip0[i]) < 0){
				perror("pipe error");
				exit(3);
			}

			if((pid = fork()) < 0){
				perror("fork error");
				exit(4);
			}

			if(pid == 0){
				if(pipe(n1n2) < 0){
					perror("pipe error");
					exit(3);
				}

				if(pipe(n2p1) < 0){
					perror("pipe error");
					exit(3);
				}

				if((pid_n1 = fork()) < 0){
					perror("fork error");
					exit(4);
				}

				if(pid_n1 == 0){
					close(n2p1[0]);
					close(n2p1[1]);

					close(1);
					dup(n1n2[1]);

					close(n1n2[0]);
					close(n1n2[1]);

					execlp("grep", "grep", "disponibile", argv[i+1], NULL);
					perror("Errore grep 1");
					exit(5);
				}

				if(pid_n1 > 0){
					if((pid_n2 = fork()) > 0){
						perror("fork error");
						exit(4);
					}

					if(pid_n2 == 0){
						close(0);
						dup(n1n2[0]);

						close(n1n2[0]);
						close(n1n2[1]);

						close(1);
						dup(n2p1[1]);

						close(n2p1[0]);
						close(n2p1[1]);

						execlp("grep", "grep", buffer, NULL);
					}

					if(pid_n2 == 0){
						close(n1n2[0]);
						close(n2p1[1]);

						close(1);
						dup(pip0[i][1]);
						close(pip0[i][0]);
						close(pip0[i][1]);

						close(0);
						dup(n2p1[0]);
						close(n2p1[0]);
						close(n2p1[1]);

						execlp("sort", "sort", "-n", NULL);
						perror("sort error");
						exit(6);
					}
				}
			}

			if(pid > 0){
				close(pip0[i][1]);
			}
		}

		for(i = 0; i < Nproc; i++){
			printf("%s: ", argv[i+1]);

			while ((nread = read(pip0[i][0], buff, MAX)) > 0){
				write(1, buff, nread);
			}
			close(pip0[i][0]);
		}

		printf("Inserire un nuovo vino da cercare:\n");
		scanf("%s", buffer);
	}

	return 0;
}

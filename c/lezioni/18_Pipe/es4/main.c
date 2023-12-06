#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>
#include <time.h>


static volatile sig_atomic_t count = 0;

void handler_sigusr1() {}

void handler_sigint() {
	printf("numero di richieste: %d\n", count);
	exit(0);
}

int main(int argc, char** argv){

	pid_t pid1, pid2, pid3;
	int i, n, status, fd, p1p2[2], p2p3[2], p3p0[2], n_read;
	char id_utente[10], path[100], buffer[100];

//	CONTROLLO DEGLI ARGOMENTI
	if(argc < 2){
		fprintf(stderr, "Utilizzo: libri_prestati <dir>");
		exit(1);
	}

	if(argv[1][0] != '/'){
		fprintf(stderr, "<dir> deve essere un direttorio assoluto");
		exit(2);
	}

	if ((fd=opendir(argv[1])) == NULL) {
		printf("errore: <dir> non esiste\n");
		exit(3);
	}

	close(fd);

//	IMPOSTO LA GESTIONE DI SIGINT
	signal(SIGINT, handler_sigint);

	while (1){
		printf("Inserire id utente: ");
		scanf("%s", id_utente);

		sprintf(path, "%s/%s.txt", argv[1], id_utente);

//		CONTROLLO CHE IL FILE ESISTA
		if((fd = open(path, O_RDONLY)) < 0){
			printf("Errore di apertura del file\n");
			continue;
		}

		close(fd);

		printf("Inserire il numero di risultati da visualizzare: ");
		scanf("%d", &n);

		if(n < 1){
			printf("Errore: %d deve essere un intero positivo", n);
			continue;
		}

//		CREO PIPE DI COMUNICAZIONE FRA P1 E P2
		if(pipe(p1p2) < 0){
			perror("P0: pipe p1p2");
			exit(4);
		}

//		CREO P1
		if((pid1 = fork()) < 0){
			perror("P0: fork P1");
			exit(5);
		}

		if(pid1 == 0){
// 			imposto la gestione di SIGINT
			signal(SIGINT, SIG_DFL);

// 			imposto la gestione di SIGUSR1
			signal(SIGUSR1, handler_sigusr1);

// 			aspetto segnale SIGUSR1
			pause();

// 			chiudo pipe non necessarie
			close(p1p2[0]);

// 			redirigo stdout
			close(1);
			dup(p1p2[1]);
			close(p1p2[1]);

//			ORDINO LE RIGHE IN MODO CRONOLOGICO
			execlp("sort", "sort", "-n", path, NULL);
			perror("P1: execlp");
			exit(6);
		}

//		CREO PIPE DI COMUNICAZIONE FRA P2 E P3
		if(pipe(p2p3) < 0){
			perror("P0: pipe p2p3");
			exit(7);
		}

//		CREO P2
		if((pid2 = fork()) < 0){
			perror("P0: fork P2");
			exit(8);
		}

		if(pid2 == 0){
// 			imposto la gestione di SIGINT
			signal(SIGINT, SIG_DFL);

//			chiudo le pipe non necessarie
			close(p1p2[1]);
			close(p2p3[0]);

// 			aspetto segnale SIGUSR1
			pause();

//			redirigo stdin
			close(0);
			dup(p1p2[0]);
			close(p1p2[0]);
			
// 			redirigo stdout
			close(1);
			dup(p2p3[1]);
			close(p2p3[1]);

//			ORDINO LE RIGHE PER DURATA
			execlp("grep", "grep", "NON RESITUITO", NULL);
			perror("P2: execlp");
			exit(9);
		}

//		chiudo pipe non necessarie
		close(p1p2[0]);
		close(p1p2[1]);

//		CREO PIPE DI COMUNICAZIONE FRA P3 E P0
		if(pipe(p3p0) < 0){
			perror("P0: pipe p3p0");
			exit(10);
		}

//		CREO P3
		if((pid3 = fork()) < 0){
			perror("P0: fork P3");
			exit(11);
		}

		if(pid3 == 0){
			char n_str[10];

//			imposto la gestione di SIGINT
			signal(SIGINT, SIG_DFL);

//			chiudo pipe non necessarie
			close(p2p3[1]);
			close(p3p0[0]);

//			redirigo stdin
			close(0);
			dup(p2p3[0]);
			close(p2p3[0]);

//			redirigo stdout
			close(1);
			dup(p3p0[1]);
			close(p3p0[1]);

//			visualizzo gli utlimi <n> risultati
			sprintf(n_str, "%d", n);
			execlp("tail", "tail", "-n", n_str, NULL);
			perror("P3: execlp");
			exit(12);
		}

//		chiudo pipe non necessarie
		close(p2p3[0]);
		close(p2p3[1]);
		close(p3p0[1]);

//		INVIO SEGNALE SIGURS1 A P1
		kill(pid1, SIGUSR1);

//		ASPETTO LA TERMINAZIONE DEI FIGLI
		for(i = 0; i < 3; i++){
			wait(NULL);
		}

//		LEGGO I RISULTATI DA P3
		while((n_read = read(p3p0[0], buffer, 100)) > 0) {
			buffer[n_read] = '\0';
			printf("%s", buffer);
		}

//		CHIUDO LE PIPE NON NECESSARIE
		close(p3p0[0]);
		count++;

	}

	return 0;
}
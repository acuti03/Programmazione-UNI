#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>
#include <time.h>

#define SEARCH_STR 100
#define ANS_STR 20
#define MAX_PIPES 5

typedef int pipe_t[2];

int main(int argc, char** argv){
	
	int i, j, status, n_ret;
	pid_t pid;
	pipe_t  *pipe_in, *pipe_out;
	char nome[SEARCH_STR], ret[ANS_STR];

//  CONTROLLO DEGLI ARGOMENTI
	if(argc < 2){
		fprintf(stderr, "Utilizzo: controlla_disponibilita <magazzino1>...<magazzinoN>");
		exit(1);
	}

	for (i = 1; i < argc; ++i) {
		if (argv[i][0] == '/') {
			fprintf(stderr, "%s non e' un path relativo\n", argv[i]);
			exit(2);
		}
	}

	pipe_in = (pipe_t *)malloc((argc - 1) * sizeof(pipe_t));
	pipe_out = (pipe_t *)malloc((argc - 1) * sizeof(pipe_t));

	for(i = 0; i < argc - 1; i++){
		if (pipe(pipe_in[i]) < 0) {
			perror("pipes_in");
			exit(3);
		}
		if (pipe(pipe_out[i]) < 0) {
			perror("pipes_out");
			exit(4);
		}

		if((pid = fork()) < 0){
			perror("fork padre");
			exit(5);
		}

//		FIGLIO
		else if(pid == 0){
//			CHIUDO LE PIPE NON UTILIZZATE
			for (j = 0; j <= i; ++j) {
				close(pipe_in[j][1]);
				close(pipe_out[j][0]);
			}

			while(read(pipe_in[i][0], nome, sizeof(nome)) > 0){
				/* genero un nipote per contare le righe in cui compare
					* l'elemento selezionato e comunicare al processo padre
					* il risultato. 
				*/

				if ((pid=fork()) < 0) {
					perror("fork figlio");
					exit(6);
				}
				if(pid == 0){
//					CHIUDO LA PIPE IN LETTURA DEL PADRE
					close(pipe_in[i][0]);

//					REDIREZIONO LO STDOUT SULLA PIPE DIRETTA AL PADRE
					close(1);
					dup(pipe_out[i][1]);
					close(pipe_out[i][1]);

					execlp("grep", "grep", "-c", nome, argv[i+1], (char*)0);
					perror("exec nipote");
					exit(7);
				}
//				ASPETTO LA TERMINAZIONE DI NIPOTE
				wait(&status);
			}
//		CHIUDO LE PIPE E TERMINO
			printf("Fine figlio: %d\n", i);
			close(pipe_in[i][0]);
			close(pipe_out[i][0]);

			free(pipe_in);
			free(pipe_out);
		}
//		CHIUDO LE ESTREMITA DELLE PIPE NON UTULIZZATE DAL PADRE
		close(pipe_in[i][0]);
		close(pipe_out[i][1]);
	}

	printf("\nInserisci il nome dell'oggetto da cercare:\n");
	scanf("%s", nome);

	while(strcmp(nome, "fine") != 0){
		for (i = 0; i < argc - 1; i++) {
			// ATTENZIONE: si deve inviare anche il carattere di terminazione stringa
			if (write(pipe_in[i][1], nome, strlen(nome) + 1) < 0){
				perror("write");
				exit(8);
			}
		}

		for (i = 0; i < (argc - 1); ++i) {
			/* reset della memoria ad ogni ciclo, per evitare output sporchi */
			memset(ret, 0, sizeof(ret));
			/* lettura da pipe i-esima */
			if ((n_ret = read(pipe_out[i][0], ret, sizeof(ret))) < 0){
				perror("read");
				exit(9);
			}
			printf("Nel file %s ci sono %d unità di stoccaggio per la materia prima %s\n",
				   argv[i+1], atoi(ret), nome);
		}
		printf("\nInserisci il nome dell'oggetto da cercare:\n");
		scanf("%s", nome);
	}

		printf("Sono il padre e ho ricevuto \"fine\"\n");
	
	/* faccio terminare i figli chiudendo gli estremi in scrittura
	 * sulle pipe pipes_in, quindi chiudo le altre pipe e pulisco
	 * la memoria aspettando tutti gli zombie.
	 * E' FONDAMENTALE chiudere l'estremo in scrittura di
	 * pipes_in PRIMA di effettuare la chiamata a wait(),
	 * per evitare DEADLOCK. */
	for (i = 0; i < (argc - 1); ++i){
		printf("Sono il padre e chiudo pipes_in[%d][1] e pipes_in[%d][1]\n",i,i);
		close(pipe_in[i][1]);
		close(pipe_out[i][0]);
		wait(&status);
	}
	
	/* Deallocazione memoria */
	free(pipe_in);
	free(pipe_out);

//	RITORNO SENZA ERRORI
	return 0;
}
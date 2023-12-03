#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

#define DIM 2
#define DIM_MATRICOLA 80

int main(int argc, char** argv){

	int p1p2[DIM], fd, status;
	char matricola[DIM_MATRICOLA];
	pid_t pid1, pid2;

//	CONTROLLO DEGLI ARGOMENTI
	if(argc != 2){
		fprintf(stderr, "Utilizzo: controlla_esami <file_dati>\n");
		exit(1);
	}

	if(argv[1][0] != '/'){
		fprintf(stderr, "<file_dati> deve essere un nome di direttorio assoluto");
		exit(2);
	}

	if((fd = open(argv[1], O_RDONLY)) < 0){
		fprintf(stderr, "Il file %s non esiste", argv[1]);
		exit(3);
	}

//	CHIUDO IL FILE
	close(fd);

//	RICHIEDO LA MODIFICA
	printf("Scrivi il nome della matricola: ");
	scanf("%s", matricola);


	while (strcmp(matricola, "fine") != 0){
		
//		CREAZIONE DELLA PIPE
		if(pipe(p1p2) <= 0){ // pipe tra p1 --> p2
			perror("pipe p1 --> p2");
			exit(4);
		}

//		GENERO P1
		if((pid1 = fork()) < 0){
			perror("fork p1");
			exit(5);
		}
		else if(pid1 == 0){ // figlio p1
			close(p1p2[0]); // chiudo i canali non necessari

//			REDIREZIONE STANDARD OUTPUT (STDOUT)
			close(1);
			dup(p1p2[1]);
			close(p1p2[1]);

//			EXEC
			execlp("grep", "grep", matricola, argv[1], NULL);
			perror("execlp");
			exit(6);
		}

//		GENERO P2
		if((pid2 = fork()) < 0){
			perror("fork p2");
			exit(7);
		}
		else if(pid2 == 0){ // figlio p2
			close(p1p2[1]); // chiudo i canali non necessari

//			REDIREZIONE SU STANDARD INPUT (STDIN)
			close(0);
			dup(p1p2[1]);
			close(p1p2[1]);

//			EXEC
			execlp("wc", "wc", "-l", NULL);
			perror("execlp wc");
			exit(8);
		}

//		PADRE: chiudo i canali non necessari prima delle wait
		close(p1p2[0]);
		close(p1p2[1]);

//		ATTENDO LA TERMINAZIONE DI P1 E P2
		wait(&status);
		wait(&status);

		printf("\nScrivi la tua matricola");
		scanf("%s", matricola);		
	}
	

	return 0;
}
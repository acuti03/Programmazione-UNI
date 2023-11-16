#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
	int fd, status;
	pid_t pid;

	// controllo degli argomenti
	if (argc < 3)
	{
		fprintf(stderr, "Usage: cerca <nomeFile> <stringa1> ... <stringaN>\n");
		exit(1);
	}

	// creo il file conteggi.txt
	fd = open("conteggi.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

	if (fd < 0)
	{
		perror("Errore nella creazione del file di conteggio, termino\n");
		exit(2);
	}

	close(fd);

	// creo i figli e li avvio in modo concorrente
	for (int i = 2; i < argc; i++)
	{
		pid = fork();

		if (pid < 0)
		{
			perror("fork fail");
			exit(3);
		}
		else if (pid == 0)
		{
			char log[256];
			fd = open("conteggi.txt", O_WRONLY | O_APPEND);

			sprintf(log, "%s %s\n", argv[1], argv[i]);

			write(fd, log, strlen(log));
			close(fd);

			printf("\nNum di righe in cui compare la stringa %s:\n", argv[i]);
			// chiamata a: grep -c stringa nomeFile
			execlp("grep", "grep", "-c", argv[i], argv[1], NULL);

			perror("exec");
			exit(4);
		}
	}

	for (int i = 2; i < argc; i++)
	{
		// attendo la terminazione di uno dei figli
		wait(&status);
	}

	return 0;
}
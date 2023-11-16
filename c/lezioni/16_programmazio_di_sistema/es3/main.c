#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char **argv)
{
	// controllo degli argomenti
	if (argc != 2)
	{
		perror("Usage: anteprima <num>");
		exit(1);
	}
	if (atoi(argv[1]) <= 0)
	{
		perror("Error with covnersion");
	}

	int num = atoi(argv[1]);
	int fd, status;
	char *file, str;
	pid_t pid;

	printf("Inserisci il nome del file: ");
	scanf("%s", file);

	// ciclo finche non ricevo la stringa fine
	while (strcmp(file, "fine") != 0)
	{
		if ((fd = open(file, O_RDONLY)) < 0)
		{

			if (errno == ENOENT)
			{
				perror("open");
				exit(3);
			}
		}
		else
		{
			close(fd);

			pid = fork();

			if (pid < 0)
			{
				perror("fork");
				exit(4);
			}
			else if (pid == 0)
			{
				printf("anteprima del file %s:\n", file);
				execlp("head", "head", "-n", argv[1], file, NULL);

				perror("exec");
				exit(5);
			}

			wait(&status);
		}

		printf("Inserisci il nome del file: ");
		scanf("%s", file);
	}
}
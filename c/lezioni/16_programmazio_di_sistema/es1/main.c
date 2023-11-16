#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	int fd;
	char buff[1024];

	//	controllo degli argomenti
	if (argc != 2)
	{
		fprintf(stderr, "Usage: copy_input filename\n");
		exit(1);
	}

	//	creo il file utilizzando la syscall open con flag e permessi rw-r--r--
	fd = open(argv[1], O_WRONLY | O_TRUNC | O_CREAT, 0644);

	if (fd < 0)
	{
		fprintf(stderr, "Error creating file %s\n", argv[1]);
		exit(2);
	}

	printf("Inserire una stringa: ");
	fgets(buff, 1024, stdin);

	while (strcmp(buff, "fine\n") != 0)
	{
		write(fd, buff, strlen(buff));
		printf("Inserisci un'altra stringa (fine per uscire):\n");
		fgets(buff, 1024, stdin);
	}

	return 0;
}
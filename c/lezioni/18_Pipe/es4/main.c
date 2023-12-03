#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>
#include <time.h>

int main(int argc, char** argv){

    pid_t pid1, pid2, pid3;
    int i, status, fd, pip2[2], p2p3[2], p3p0[2], n_read;
    char id_utente[10], path[100], buffer[100];

    if(argc < 2){
        fprintf(stderr, "Utilizzo: libri_prestati <dir>");
        exit(1);
    }

    if(argv[1][0] != '/'){
        fprintf(stderr, "<dir> deve essere un direttorio assoluto");
    }

    while (1){
        scanf("%s", id_utente);

        sprintf(path, "%s/%s.txt", argv[1], id_utente);
        fd = open(path, O_RDONLY);

        if(fd < 0){
            printf("Errore: %d non ");
        }
    }
    



    return 0;
}
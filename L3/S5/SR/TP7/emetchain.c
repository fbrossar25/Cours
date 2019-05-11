
/* EMETTEUR D'UNE CHAINE DE CARACTERES emetchain.c */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/* Includes necessaires aux sockets AF_UNIX */
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

/* Utilise pour les codes d'erreurs */
#include <errno.h>

extern int      errno;

/* Nom de la socket du recepteur */
#define NAME "/tmp/socket_udp2"

/* Chaine envoyee au recepteur */
#define CHAINE "Vive les vacances ! "

int main()
{
  int  sock,	/* descipteur de la socket locale */
       err;	/* code d'erreur */

  struct sockaddr_un nom;   /* adresse AF_UNIX de la socket */
  

  /* Creation de la socket, protocole UDP */
  sock = socket(AF_UNIX, SOCK_DGRAM, 0);
  if (sock < 0) {
    perror("Erreur a la creation de socket");
    exit(0);
  }

  /* Initialisation de l'adresse de la socket */
  nom.sun_family = AF_UNIX;
  strcpy(nom.sun_path, NAME);
  
  /* Envoi de la chaine */
  err = sendto(sock, CHAINE, (strlen(CHAINE) + 1), 0, (struct sockaddr *)&nom, sizeof(nom));
  if (err != strlen(CHAINE)+1) {
    perror("Erreur sur le sendto");
    exit(0);
  }

  /* Fermeture de la socket */
  close(sock);
  return EXIT_SUCCESS;
}

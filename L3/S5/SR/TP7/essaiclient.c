
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
#define NAME "/tmp/socket"

/* Chaine envoyee au recepteur */
#define CHAINE "Plop"

int main()
{
  int  sock,	/* descipteur de la socket locale */
       err;	/* code d'erreur */

  struct sockaddr_un nom;   /* adresse AF_UNIX de la socket */
  

  /* Creation de la socket, protocole TCP */
  sock = socket(AF_UNIX, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("Erreur a la creation de socket");
    return EXIT_FAILURE;
  }

  /* Initialisation de l'adresse de la socket */
  nom.sun_family = AF_UNIX;
  strcpy(nom.sun_path, NAME);
  
  /* Envoi de la chaine */
  err = connect(sock, (struct sockaddr *)&nom, sizeof(nom));
  if (err != 0) {
    perror("Erreur sur le connect");
    return EXIT_FAILURE;
  }

  int nb = write(sock, CHAINE, (sizeof(CHAINE) + 1));
  if(nb <= 0)
  {
    perror("Erreur sur le send");
    return EXIT_FAILURE;
  }

  /* Fermeture de la socket */
  close(sock);
  return EXIT_SUCCESS;
}


/* EMETTEUR emetrecoiChain.c  

   le client envoie une chaine de caractère et recoit la taille          */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

/* includes necessaires pour les sockets AF_UNIX */
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

/* Utilise pour les codes d'erreurs */
#include <errno.h>

extern int errno;

/* Nom de la socket du serveur-recepteur */
#define NAME_DIST "/tmp/socket_tcp_serv8"

/* Nom de la socket locale */
#define NAME_LOCAL "/tmp/socket_tcp_cli8"

/* Chaine envoyee au serveur-recepteur */
#define CHAINE "Hello world !"

int main()
{
  int sock,                 /* socket local */
      tailMsg,              /* retour de la taille */
      err;                  /* code d'erreur */

  unsigned int tailAddr;
  struct sockaddr_un nomLocal,   /* adresse locale */
                     nomDistant; /* adresse distante*/
  
  
  /* Creation de la socket, protocole UDP */
  sock=socket(AF_UNIX, SOCK_STREAM, 0);
  if (sock<0) {
    perror("Erreur a la creation de socket");
    exit(0);
  }
  
  /* Initialisation de l'adresse de la socket distante */
  nomDistant.sun_family=AF_UNIX;
  strcpy(nomDistant.sun_path, NAME_DIST);
  
  /* Initialisation de l'adresse de la socket locale */
  nomLocal.sun_family = AF_UNIX;
  strcpy(nomLocal.sun_path,NAME_LOCAL); 
  
  err = bind(sock, (struct sockaddr *)&nomLocal, sizeof(nomLocal));
  if (err<0) {
    perror("Erreur dans le bind");
    exit(0);
    } 
  
  /* Envoi de la chaine */
  err = connect(sock, (struct sockaddr *)&nomDistant, sizeof(nomDistant));
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
  
  /* Reception du retour */
  err = recvfrom(sock,( char *)&tailMsg, sizeof(int), 0, (struct sockaddr *)&nomDistant, 
		 &tailAddr);
  if ( err<0 ) {
    perror("Erreur sur le recvfrom");
    unlink( NAME_LOCAL );
    exit(0);
    }
  
  printf("Le retour: %d\n", tailMsg);
  
  /* Fermeture de la socket */
  close(sock);
  unlink(NAME_LOCAL);
  return EXIT_SUCCESS;
}



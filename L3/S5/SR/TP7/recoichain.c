
/* RECEPTEUR D'UNE CHAINE recoichain.c   */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* include necessaires aux socket AF_UNIX */
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

/* Utilise pour les codes d'erreurs */
#include <errno.h>

extern int      errno;

/* Nom de la socket du serveur-recepteur */
#define NAME "/tmp/socket_udp2"

int main()
{
  int   sock,	     /* descipteur de la socket locale */
        err;	     /* code d'erreur */
  char  chaine[100]; /* buffer de reception */
  
  struct sockaddr_un nom;       /* adresse donnee a la socket locale */
  struct sockaddr_un nomRecep;  /* adresse de la socket dont on recoit */  

  unsigned int tailNomRecep ; /* taille de l'adresse recue */

  /* Creation de la socket, protocole UDP */
  sock=socket(AF_UNIX,SOCK_DGRAM,0);
  if (sock < 0) {
    perror("Erreur a la creation de socket");
    exit(0);
  }

  /* Initialisation de l'adresse de la socket */
  nom.sun_family = AF_UNIX;
  strcpy(nom.sun_path,NAME);
  
  /* Association socket-adresse */
  err=bind(sock,(struct sockaddr *)&nom,sizeof(nom));

  if (err < 0) {
    perror("Erreur sur le bind");
    exit(0);
  }

  /* Reception du message */
  err=recvfrom(sock,chaine,sizeof(chaine),0,(struct sockaddr *)&nomRecep,&tailNomRecep ); 
  
  if (err < 0) {
    perror("Erreur dans le recv");
    unlink(NAME);
    exit(0);
  }

  /* Affichage de la chaine */
  printf("Voici la chaine recue: %s\n", chaine);
  
  /* Fermeture de la socket */
  unlink(NAME);
  close(sock);
  return EXIT_SUCCESS;
}

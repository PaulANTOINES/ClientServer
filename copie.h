#ifndef __COPIE_H
#define __COPIE_H

#define SRV_PORT htons(2345)

#define BUFF_SIZE 128

enum error_code {  // code d'erreur retourné par le serveur
  OK,                // fichier trouvé et accessible en lecture 
  KO,                // erreur non spécifiée
  NOFILE,            // fichier non trouvé
  NOAUTH             // accès au fichier refusé
};

struct srv_ans   // réponse du serveur à la demande de transmission d'un fichier
{
  enum error_code cd; // code d'erreur
  int size;           // taille du fichier à transférer
};
  
#endif // __COPIE_H

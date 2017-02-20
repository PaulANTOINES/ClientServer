#include "common.h"

/* send_msg send a message on socket sock
   sock: the socket
   code: message's protocol code
   size: message's size
   msg: message to be sent
*/
int send_msg(int sock, unsigned char code, unsigned char size, char *body) 
{
  msg_t msg;
  
  msg.code = code;
  msg.size = size;
  
  if ((send(sock, &msg, HEADSIZE, 0)) < 0) {
    PERROR("Envoie message head")
    return -1;}
    
  if ((send(sock, body, size, 0)) < 0) {
    PERROR("Envoie message body");
    return -1;}

  return 0;
}




/* recv_msg recv a message from the socket sock
   sock: the socket
   code: message's protocol code
   size: message's size
   msg: message to be received
*/
int recv_msg(int sock, unsigned char *code, unsigned char *size, char **body) 
{
  msg_t msg;
  
  if ((recv(sock, &msg, HEADSIZE, 0)) < 0) {
    PERROR("Reception message head");
    return -1;}
        
  *code = msg.code;
  *size = msg.size;
  
  *body = malloc((*size)*(sizeof(unsigned char)));
  
  if ((recv(sock, *body, *size + 1, 0)) < 0) {
    PERROR("Reception message body");
    return -1;}
        
  
  return 0;
}





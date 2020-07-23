#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <arpa/inet.h>

#define BACKLOG 10

int main()
{
 int n = 0;
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  struct sockaddr_in servAddr;
  servAddr.sin_family = AF_INET;
  servAddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);//loopback(ex 3)
  servAddr.sin_port = htons(6667);  //(ex 2)

  bind(sockfd, (struct sockaddr*)&servAddr, sizeof(servAddr));
  printf("[+] Bind\n");

  listen(sockfd, BACKLOG);
  printf("[+] Listening for the client\n");

  int i = 1;
  while(i){
    int client_sock = accept(sockfd, NULL, NULL);
    n++;
    time_t masa;
    time(&masa);
    printf("Client %d requested for time at %s", n, ctime(&masa));
    send(client_sock, ctime(&masa), 30, 0);
  }

  return 0;


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <time.h>

int main()
{
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  char response[30];
  struct sockaddr_in servAddr;
  servAddr.sin_family = AF_INET;
  servAddr.sin_addr.s_addr = INADDR_ANY;
  servAddr.sin_port = htons(6667);

  connect(sockfd, (struct sockaddr*)&servAddr, sizeof(servAddr));
  printf("[+]Connected to the server\n");

  recv(sockfd, response, 29, 0);
  printf("[+] The current time is : %s", response);

  return 0;

}
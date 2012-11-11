/*
** xfunc.c for  in /home/palmsnipe/scm/myftp-2015-2014s-morale_c/tp
**
** Made by cyril morales
** Login   <palmsnipe@epitech.net>
**
** Started on  Sat Apr  7 09:22:32 2012 cyril morales
** Last update Mon Jun 18 20:27:56 2012 Cyril Morales
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "xfunc.h"

int		xsocket(int domain, int type, int protocol)
{
  int		fd;

  fd = socket(domain, type, protocol);
  if (fd == -1)
    {
      perror("Error: socket()");
      exit(EXIT_FAILURE);
    }

  return (fd);
}

int		xbind(int sockfd, const struct sockaddr *addr,
		      socklen_t addrlen)
{
  int		b;

  b = bind(sockfd, addr, addrlen);
  if (b == -1)
    {
      perror("Error: bind()");
      close(sockfd);
      exit(EXIT_FAILURE);
    }

  return (b);
}

int		xlisten(int sockfd, int backlog)
{
  int		l;

  l = listen(sockfd, backlog);
  if (l == -1)
    {
      perror("Error: listen()");
      close(sockfd);
      exit(EXIT_FAILURE);
    }

  return (l);
}
int		xaccept(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
{
  int		a;

  a = accept(sockfd, addr, addrlen);
  if (a == -1)
    {
      perror("Error: accept()");
      close(sockfd);
      exit(EXIT_FAILURE);
    }

  return (a);
}

int		xconnect(int sockfd, const struct sockaddr *addr,
			 socklen_t addrlen)
{
  int		c;

  c = connect(sockfd, addr, addrlen);
  if (c == -1)
    {
      perror("Error: connect()");
      close(sockfd);
      exit(EXIT_FAILURE);
    }

  return (c);
}

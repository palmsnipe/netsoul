/*
** socket.c for  in /Users/cyrilmorales/Documents/netsoul/netsoul
**
** Made by Cyril Morales
** Login   <morale_c@epitech.net>
**
** Started on  Mon Jun 18 20:15:24 2012 Cyril Morales
** Last update Mon Jun 18 20:32:31 2012 Cyril Morales
*/

#include <netdb.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include "xfunc.h"
#include "socket.h"

char		*get_ip_with_hostname(char *hostname)
{
  struct hostent	*h;

  if ((h = gethostbyname(hostname)) == NULL)
    {
      herror("gethostbyname(): ");
      exit(EXIT_FAILURE);
    }

  return (inet_ntoa(*((struct in_addr *)h->h_addr)));
}

int    		init_client_socket(struct sockaddr_in *sin,
				   char *protocol, char *ip, int port)
{
  struct protoent	*pe;
  int			fd;

  pe = getprotobyname(protocol);
  fd = xsocket(AF_INET, SOCK_STREAM, pe->p_proto);
  sin->sin_family = AF_INET;
  sin->sin_port = htons(port);
  sin->sin_addr.s_addr = inet_addr(ip);

  return (fd);
}

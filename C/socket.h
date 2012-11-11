/*
** socket.h for  in /Users/cyrilmorales/Documents/netsoul/netsoul
**
** Made by Cyril Morales
** Login   <morale_c@epitech.net>
**
** Started on  Mon Jun 18 20:13:33 2012 Cyril Morales
** Last update Mon Jun 18 20:17:54 2012 Cyril Morales
*/

#ifndef __SOCKET_H__
#define __SOCKET_H__

/* trouve l'ip par le hostname */
char		*get_ip_with_hostname(char *hostname);
/* initialise le socket du client */
int    		init_client_socket(struct sockaddr_in *sin,
				   char *protocol, char *ip, int port);

#endif

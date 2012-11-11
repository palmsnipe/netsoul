/*
** xfunc.h for  in /Users/cyrilmorales/Documents/netsoul/netsoul
**
** Made by Cyril Morales
** Login   <morale_c@epitech.net>
**
** Started on  Mon Jun 18 20:22:28 2012 Cyril Morales
** Last update Mon Jun 18 20:30:52 2012 Cyril Morales
*/

#ifndef __XFUNC_H__
#define __XFUNC_H__

#include <netinet/in.h>

/* xsocket.c */
int		xsocket(int domain, int type, int protocol);
int		xbind(int sockfd, const struct sockaddr *addr,
		      socklen_t addrlen);
int		xlisten(int sockfd, int backlog);
int		xaccept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
int		xconnect(int sockfd, const struct sockaddr *addr,
			 socklen_t addrlen);
/* xfunc.c */
void		*xmalloc(int  size);
size_t		xread(int fd, void *buf, size_t count);
int		xclose(int fd);
int		xopen(const char *file_name, int flags);
ssize_t		xwrite(int fd, const void *buf, size_t count);

#endif

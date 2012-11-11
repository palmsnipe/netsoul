/*
** myftp.h for  in /home/palmsnipe/scm/myftp-2015-2014s-morale_c/tp
**
** Made by cyril morales
** Login   <palmsnipe@epitech.net>
**
** Started on  Sat Apr  7 09:30:41 2012 cyril morales
** Last update Tue Jun 19 01:13:16 2012 Cyril Morales
*/

#ifndef	__NETSOUL_H__
#define	__NETSOUL_H__

typedef struct		s_netsoul
{
  int			sockfd;
  struct sockaddr_in	sin;

  char			*md5;
  int			socket_number;
  char			*host_client;
  int			port_client;
  unsigned int	       	timestamp_server;
  int			run;
}			t_netsoul;

/* socket_io.c */
void			write_socket(int fd, char *str);
char			*read_socket(int fd);

/* netsoul.c */
t_netsoul		*netsoul_new();
void			netsoul_free(struct s_netsoul *this);
void			netsoul_connect(t_netsoul *this, char *login, char *pwd);
void			netsoul_disconnect(t_netsoul *this);

#endif

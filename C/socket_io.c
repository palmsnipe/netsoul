/*
** socket_io.c for  in /home/palmsnipe/scm/myftp-2015-2014s-morale_c
**
** Made by cyril morales
** Login   <palmsnipe@epitech.net>
**
** Started on  Sat Apr  7 18:33:21 2012 cyril morales
** Last update Mon Jun 18 21:34:26 2012 Cyril Morales
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "xfunc.h"
#include "netsoul.h"

#define BUFFER		1024

void			write_socket(int fd, char *str)
{
  xwrite(fd, str, strlen(str));
}

/* char			*read_socket(int fd) */
/* { */
/*   int			len; */
/*   char			buf[BUFFER]; */
/*   char			*tmp; */
/*   int			i; */

/*   tmp = xmalloc(1 * sizeof(char)); */
/*   tmp[0] = '\0'; */
/*   if((len = xread(fd, buf, BUFFER - 1)) > 0) */
/*     { */
/*       tmp = xmalloc((len + 1) * sizeof(char)); */
/*       i = 0; */
/*       while (i < len) */
/* 	{ */
/* 	  tmp[i] = buf[i]; */
/* 	  i++; */
/* 	} */
/*       tmp[i] = '\0'; */
/*     } */

/*   return (tmp); */
/* } */

char			*read_socket(int fd)
{
  int			len;
  char			buf[BUFFER];
  char			*tmp;
  int			i;

  tmp = xmalloc(1 * sizeof(char));
  tmp[0] = '\0';
  if((len = xread(fd, buf, BUFFER - 1)) > 0)
    {
      tmp = xmalloc((len + 1) * sizeof(char));
      i = 0;
      while (i < len)
	{
	  tmp[i] = buf[i];
	  i++;
	}
      tmp[i] = '\0';
    }

  return (tmp);
}

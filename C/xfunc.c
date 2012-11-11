/*
** xfunc.c for  in /home/palmsnipe/scm/myftp-2015-2014s-morale_c
**
** Made by cyril morales
** Login   <palmsnipe@epitech.net>
**
** Started on  Sat Apr  7 21:36:59 2012 cyril morales
** Last update Mon Jun 18 20:27:36 2012 Cyril Morales
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "xfunc.h"

ssize_t		xwrite(int fd, const void *buf, size_t count)
{
  ssize_t	re;

  re = write(fd, buf, count);
  if (re == -1)
    {
      perror("Error writing");
      exit(EXIT_FAILURE);
    }

  return (re);
}

void		*xmalloc(int  size)
{
  void		*ptr;

  ptr = malloc(size);
  if (ptr == NULL)
    exit(EXIT_FAILURE);

  return (ptr);
}

int		xopen(const char *file_name, int flags)
{
  int		tmp;

  tmp = open(file_name, flags);
  if (tmp == -1)
    {
      fprintf(stderr, "ERROR: bad file name\n");
      exit(-1);
    }
  return (tmp);
}

size_t		xread(int fd, void *buf, size_t count)
{
  int		ret;

  ret = read(fd, buf, count);
  if (ret == -1)
    exit(EXIT_FAILURE);

  return (ret);
}

int		xclose(int fd)
{
  int		ret;

  ret = close(fd);
  if (ret == -1)
    {
      perror("Error reading file");
      exit(EXIT_FAILURE);
    }

  return (ret);
}

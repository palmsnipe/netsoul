/*
** str_to_wordtab.c for  in /Users/cyrilmorales/Documents/netsoul/netsoul
**
** Made by Cyril Morales
** Login   <morale_c@epitech.net>
**
** Started on  Mon Jun 18 19:22:15 2012 Cyril Morales
** Last update Mon Jun 18 21:59:07 2012 Cyril Morales
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "xfunc.h"
#include "func.h"

static int	count_separators(char *str, char s);

static int	count_separators(char *str, char s)
{
  int		nb;
  int		i;

  nb = 1;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == s)
	{
	nb++;
	while (str[i] == ' ' && str[i] != '\0')
	  i++;
	}
      else
	i++;
    }

  return (nb);
}

char		**str_to_wordtab(char *str, char separator)
{
  char		**tab;
  int		word;
  int		i;
  int		len;

  tab = xmalloc(count_separators(str, separator) * sizeof(char*));
  word = 0;
  i = 0;
  while (str[i] != '\0')
    {
      len = 0;
      while (str[i] == ' ' && str[i] != '\0')
	i++;
      while (str[i + len] != separator && str[i + len] != '\n' && str[i + len] != '\0')
	len++;
      if (len == 0)
	break;
      tab[word] = xmalloc((len + 1) * sizeof(char));
      strncpy(tab[word], str + i, len);
      tab[word][len] = '\0';
      i += len;
      word++;
    }
  tab[word] = '\0';

  return (tab);
}

void		free_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != '\0')
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}

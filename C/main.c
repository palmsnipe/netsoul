/*
** main.c for  in /home/palmsnipe/scm/myftp-2015-2014s-morale_c/tp
**
** Made by cyril morales
** Login   <palmsnipe@epitech.net>
**
** Started on  Thu Apr  5 15:29:22 2012 cyril morales
** Last update Tue Jun 19 13:31:53 2012 Cyril Morales
*/

#include <stdlib.h>
#include <unistd.h>
#include "xfunc.h"
#include "netsoul.h"

int			main(int argc, char **argv)
{
  t_netsoul		*netsoul;

  netsoul = netsoul_new();

  netsoul_connect(netsoul, "morale_c", "password");
  if (argc > 1)
    {
      sleep(atoi(argv[1]));
    }
  netsoul_disconnect(netsoul);

  netsoul_free(netsoul);

  return (EXIT_SUCCESS);
}

/*
** netsoul.c for  in /Users/cyrilmorales/Documents/netsoul/netsoul
**
** Made by Cyril Morales
** Login   <morale_c@epitech.net>
**
** Started on  Mon Jun 18 20:15:07 2012 Cyril Morales
** Last update Tue Jun 19 12:19:41 2012 Cyril Morales
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "md5.h"
#include "xfunc.h"
#include "func.h"
#include "socket.h"
#include "netsoul.h"

char		*str2md5(char *str, int length)
{
  int		n;
  md5_state_t	c;
  unsigned char	digest[16];
  char		*out;
  unsigned char	*tmp;

  int		i;

  i = 0;
  tmp = xmalloc((strlen(str) + 1) * sizeof(unsigned char));
  while (str[i] != '\0')
    {
      tmp[i] = str[i];
      i++;
    }
  tmp[i] = '\0';
  out = xmalloc(33 * sizeof(char));
  md5_init(&c);
  while (length > 0) {
    if (length > 512) {
      md5_append(&c, tmp, 512);
    } else {
      md5_append(&c, tmp, length);
    }
    length -= 512;
    str += 512;
  }
  free(tmp);
  md5_finish(&c, digest);
  for (n = 0; n < 16; ++n) {
    snprintf(&(out[n*2]), 16*2, "%02x", (unsigned int)digest[n]);
  }

  return (out);
}

t_netsoul	*netsoul_new()
{
  t_netsoul    	*this;
  char	       	*ip;
  int	       	port;

  this = xmalloc(sizeof(struct s_netsoul));

  this->run = 0;
  this->md5 = NULL;
  this->host_client = NULL;

  ip = get_ip_with_hostname("ns-server.epita.fr");
  port = 4242;
  this->sockfd = init_client_socket(&this->sin, "TCP", ip, port);

  return (this);
}

void	       	netsoul_free(struct s_netsoul *this)
{
  if (this->run == 1)
    xclose(this->sockfd);

  if (this->md5 != NULL)
    free(this->md5);
  if (this->host_client != NULL)
    free(this->host_client);

  free(this);
}

void	       	netsoul_connect(t_netsoul *this, char *login, char *pwd)
{
  char	       	*tmp;
  char	       	**tab;
  char		*buffer;

  xconnect(this->sockfd, (const struct sockaddr*)&this->sin, sizeof(this->sin));
  tmp = read_socket(this->sockfd);
  tab = str_to_wordtab(tmp, ' ');
  free(tmp);
  this->socket_number = atoi(tab[1]);
  this->md5 = strdup(tab[2]);
  this->host_client = strdup(tab[3]);
  this->port_client = atoi(tab[4]);
  this->timestamp_server = atoi(tab[5]);
  free_tab(tab);
  write_socket(this->sockfd, "auth_ag ext_user none none\n");
  tmp = read_socket(this->sockfd);
  free(tmp);
  buffer = xmalloc(512 * sizeof(char));
  snprintf(buffer, 511, "%s-%s/%d%s", this->md5, this->host_client, this->port_client, pwd);
  tmp = str2md5(buffer, strlen(buffer));
  snprintf(buffer, 511, "ext_user_log %s %s netsoul%%20for%%20webOS somewhere%%20with%%20my%%20webOS%%20device\n", login, tmp);
  free(tmp);
  write_socket(this->sockfd, buffer);
  free(buffer);
  tmp = read_socket(this->sockfd);
  if (strcmp("rep 002 -- cmd end\n", tmp) != 0)
    {
      printf("Erreur d'authentification\n");
      netsoul_disconnect(this);
    }
  else
    {
      this->run = 1;
      printf("Authentifie :)\n");
    }
  free(tmp);
}

void			netsoul_disconnect(t_netsoul *this)
{
  if (this->run == 1)
    {
      this->run = 0;
      xclose(this->sockfd);
    }
  else
    printf("netsoul_disconnect() : Socket already closed.\n");
}

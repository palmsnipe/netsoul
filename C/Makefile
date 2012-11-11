##
## Makefile for  in /home/palmsnipe/scm/myftp-2015-2014s-morale_c/tp
## 
## Made by cyril morales
## Login   <palmsnipe@epitech.net>
## 
## Started on  Thu Apr  5 16:03:36 2012 cyril morales
## Last update Tue Jun 19 13:29:11 2012 Cyril Morales
##

NAME=	netsoul

# CC=	gcc
CC=	arm-none-linux-gnueabi-gcc-3.4.4

CFLAGS= -W -Wall

LDFLAGS = 

SRC=	main.c \
	netsoul.c \
	socket.c \
	socket_io.c \
	xsocket.c \
	xfunc.c \
	md5.c \
	str_to_wordtab.c

OBJ = $(SRC:.c=.o)

RM = rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
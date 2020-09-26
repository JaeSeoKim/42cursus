# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/24 20:10:49 by jaeskim           #+#    #+#              #
#    Updated: 2020/09/26 18:06:26 by jaeskim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = libft.a

AR = ar
ARFLAGS = cr

CC = gcc
CFLAG = -Wall -Wextra -Werror

RM = rm
RMFLAG = -f

INCLUDES = ./libft.h

SRCS = \
	./ft_memset.c	\
	./ft_bzero.c	\
	./ft_memcpy.c	\
	./ft_memccpy.c	\
	./ft_memmove.c	\
	./ft_memchr.c	\
	./ft_memcmp.c	\
	./ft_calloc.c	\
	./ft_strlen.c	\
	./ft_strlcpy.c	\
	./ft_strchr.c	\
	./ft_strrchr.c	\
	./ft_strncmp.c	\
	./ft_strnstr.c	\
	./ft_strdup.c	\
	./ft_isdigit.c	\
	./ft_atoi.c		\
	./ft_isalpha.c	\
	./ft_isalnum.c	\
	./ft_isprint.c	\
	./ft_toupper.c	\
	./ft_tolower.c
	
OBJS = $(SRCS:.c=.o)

all : $(TARGET)

clean :
	$(RM) $(RMFLAG) $(OBJS)

fclean : clean
	$(RM) $(RMFLAG) $(TARGET)

re : fclean all

.c.o : $(SRCS)
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(TARGET) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

.PHONY: all clean fclean re
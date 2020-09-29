# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/24 20:10:49 by jaeskim           #+#    #+#              #
#    Updated: 2020/09/28 04:32:12 by jaeskim          ###   ########.fr        #
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

SRC_PART1 = \
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
	./ft_strlcat.c	\
	./ft_strchr.c	\
	./ft_strrchr.c	\
	./ft_strncmp.c	\
	./ft_strnstr.c	\
	./ft_strdup.c	\
	./ft_isdigit.c	\
	./ft_atoi.c		\
	./ft_isalpha.c	\
	./ft_isalnum.c	\
	./ft_isascii.c	\
	./ft_isprint.c	\
	./ft_toupper.c	\
	./ft_tolower.c
	
SRC_PART2 = \
	./ft_substr.c	\
	./ft_strjoin.c	\
	./ft_strtrim.c	\
	./ft_split.c	\
	./ft_itoa.c		\
	./ft_strmapi.c	\
	./ft_putchar_fd.c	\
	./ft_putstr_fd.c	\
	./ft_putendl_fd.c	\
	./ft_putnbr_fd.c

SRC_BONUS = \
	./ft_lstnew.c	\
	./ft_lstadd_front.c	\
	./ft_lstsize.c	\
	./ft_lstlast.c	\
	./ft_lstadd_back.c	\
	./ft_lstdelone.c	\
	./ft_lstclear.c	\
	./ft_lstiter.c	\
	./ft_lstmap.c

	

SRCS = \
	${SRC_PART1}	\
	${SRC_PART2}	\
	${SRC_BONUS}
	
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

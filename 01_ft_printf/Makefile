# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/24 20:10:49 by jaeskim           #+#    #+#              #
#    Updated: 2020/10/16 18:27:43 by jaeskim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

AR = ar
ARFLAGS = crs

CC = gcc
# CFLAGS = -Wall -Wextra -Werror

RM = rm
RMFLAGS = -f

LIBFT = libft.a
LIBFT_DIR = ./lib/libft
LIBFT_FILE = $(LIBFT_DIR)/$(LIBFT)
LIBFT_INC_DIR = $(LIBFT_DIR)/include

INC_DIR = ./include

SRC_DIR = ./src
SRC_UTIL_DIR = $(SRC_DIR)/util
SRC_PARSE_DIR = $(SRC_DIR)/parse

OBJ_DIR = ./obj

vpath %.c \
	$(subst ./, , $(SRC_DIR))	\
	$(subst ./, , $(SRC_UTIL_DIR))	\
	$(subst ./, , $(SRC_PARSE_DIR))

SRCS = \
	$(wildcard $(SRC_DIR)/*.c)	\
	$(wildcard $(SRC_UTIL_DIR)/*.c)	\
	$(wildcard $(SRC_PARSE_DIR)/*.c)

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

all : $(NAME)

clean : $(LIBFT)_clean
	$(RM) $(RMFLAGS) $(OBJS)

fclean : $(LIBFT)_fclean clean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all 

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBFT_INC_DIR) -c $< -o $@

$(NAME) : $(LIBFT_FILE) $(OBJS)
	$(AR) $(ARFLAGS) $@ $(OBJS)
	@ranlib $(NAME)

# Libft

$(LIBFT) : $(LIBFT_FILE)

$(LIBFT_FILE) :
	make -C $(LIBFT_DIR)
	@cp $(LIBFT_FILE) $(NAME)

$(LIBFT)_clean :
	make -C $(LIBFT_DIR) clean

$(LIBFT)_fclean :
	make -C $(LIBFT_DIR) fclean

# Test Code

TEST_FILE = test.c

test : $(NAME) $(TEST_FILE)
	$(CC) -I $(INC_DIR) -I $(LIBFT_INC_DIR) $(TEST_FILE) -o $(TEST_FILE:.c=.out) -L. -lftprintf
	@echo "[TEST RESULT]"
	@./$(TEST_FILE:.c=.out)
	@rm $(TEST_FILE:.c=.out)

.PHONY : \
	all clean fclean re \
	$(LIBFT) $(LIBFT)_clean $(LIBFT)_fclean \
	test

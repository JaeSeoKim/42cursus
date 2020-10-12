# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/24 20:10:49 by jaeskim           #+#    #+#              #
#    Updated: 2020/10/12 21:29:44 by jaeskim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft.a

AR = ar
ARFLAGS = crs

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm
RMFLAGS = -f

LIBFT_DIR = ./lib/libft
LIBFT_INC_DIR = $(LIBFT_DIR)/include

INC_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = ./obj

SRCS = $(wildcard $(SRC_DIR)/*.c)

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

all : $(NAME)

clean : $(LIBFT)_clean
	$(RM) $(RMFLAGS) $(OBJS) $(OBJS_BONUS)

fclean : $(LIBFT)_fclean clean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all 

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(LIBFT)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBFT_INC_DIR) -c $< -o $@

$(NAME) : $(OBJS)
	@cp $(LIBFT_DIR)/$(LIBFT) ./$(NAME)
	$(AR) $(ARFLAGS) $@ $(OBJS)

# Libft

$(LIBFT) :
	make -C $(LIBFT_DIR)

$(LIBFT)_clean :
	make -C $(LIBFT_DIR) clean

$(LIBFT)_fclean :
	make -C $(LIBFT_DIR) fclean

# test

TEST_FILE = test.c

test : $(NAME) test.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBFT_INC_DIR) -L. -lftprintf $(TEST_FILE) -o $(TEST_FILE:.c=.o)
	@echo "[TEST RESULT]"
	@./$(TEST_FILE:.c=.o)
	@rm $(TEST_FILE:.c=.o)

.PHONY: all clean fclean re $(LIBFT)_clean $(LIBFT)_fclean $(LIBFT)_re

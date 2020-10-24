# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/24 20:10:49 by jaeskim           #+#    #+#              #
#    Updated: 2020/10/24 17:23:07 by jaeskim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

AR = ar
ARFLAGS = crs

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm
RMFLAGS = -f

LIBFT = libft.a
LIBFT_DIR = ./lib/libft
LIBFT_FILE = $(LIBFT_DIR)/$(LIBFT)
LIBFT_INC_DIR = $(LIBFT_DIR)/include

INC_DIR = ./include

SRC_DIR = ./src
SRC_UTIL_DIR = $(SRC_DIR)/util
SRC_UTIL_UTF8_DIR = $(SRC_UTIL_DIR)/utf8
SRC_PARSE_DIR = $(SRC_DIR)/parse
SRC_PRINT_DIR = $(SRC_DIR)/print

OBJ_DIR = ./obj

vpath %.c \
	$(subst ./, , $(SRC_DIR))	\
	$(subst ./, , $(SRC_UTIL_DIR))	\
	$(subst ./, , $(SRC_UTIL_UTF8_DIR))	\
	$(subst ./, , $(SRC_PARSE_DIR))	\
	$(subst ./, , $(SRC_PRINT_DIR))

SRCS = \
	$(wildcard $(SRC_DIR)/*.c)	\
	$(wildcard $(SRC_UTIL_DIR)/*.c)	\
	$(wildcard $(SRC_UTIL_UTF8_DIR)/*.c)	\
	$(wildcard $(SRC_PARSE_DIR)/*.c)	\
	$(wildcard $(SRC_PRINT_DIR)/*.c)

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

# Color
CL_BOLD   = \e[1m
CL_DIM    = \e[2m
CL_UDLINE = \e[4m

NO_COLOR = \e[0m

BG_TEXT = \e[48;2;45;55;72m
BG_BLACK = \e[48;2;30;31;33m

FG_WHITE = $(NO_COLOR)\e[0;37m
FG_TEXT = $(NO_COLOR)\e[38;2;189;147;249m
FG_TEXT_PRIMARY = $(NO_COLOR)$(CL_BOLD)\e[38;2;255;121;198m

LF = \e[1K\r$(NO_COLOR)
CRLF= \n$(LF)

all : $(NAME)

bonus : $(NAME)

clean : $(LIBFT)_clean
	@$(RM) $(RMFLAGS) $(OBJS)
	@printf "$(LF)🧹 $(FG_TEXT)Cleaning $(FG_TEXT_PRIMARY)$(NAME)'s Object files...\n"

fclean : $(LIBFT)_fclean clean
	@$(RM) $(RMFLAGS) $(NAME)
	@printf "$(LF)🧹 $(FG_TEXT)Cleaning $(FG_TEXT_PRIMARY)$(NAME)\n"

re : fclean all 

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBFT_INC_DIR) -c $< -o $@
	@printf "$(LF)🚧 $(FG_TEXT)Create $(FG_TEXT_PRIMARY)$@ $(FG_TEXT)from $(FG_TEXT_PRIMARY)$<"

$(NAME) : $(LIBFT_FILE) $(OBJS)
	@printf "$(LF)🚀 $(FG_TEXT)Successfully Created $(FG_TEXT_PRIMARY)$(NAME)'s Object files $(FG_TEXT)!"
	@printf "$(CRLF)📚 $(FG_TEXT)Archiving! $(FG_TEXT_PRIMARY)$@"
	@$(AR) $(ARFLAGS) $@ $(OBJS)
	@printf "$(LF)🎉 $(FG_TEXT)Successfully Archived $(FG_TEXT_PRIMARY)$@ $(FG_TEXT)!\n"

# Libft

$(LIBFT) : $(LIBFT_FILE)

$(LIBFT_FILE) :
	@make --no-print-directory -C $(LIBFT_DIR)
	@cp $(LIBFT_FILE) $(NAME)

$(LIBFT)_clean :
	@make --no-print-directory -C $(LIBFT_DIR) clean

$(LIBFT)_fclean :
	@make --no-print-directory -C $(LIBFT_DIR) fclean

# Test Code

TEST_FILE = test.c

test : $(NAME) $(TEST_FILE)
	@$(CC) -g -I $(INC_DIR) -I $(LIBFT_INC_DIR) $(TEST_FILE) -o $(TEST_FILE:.c=.out) -L. -lftprintf
	@printf "$(FG_TEXT_PRIMARY)$(BG_BLACK)🚧 [TEST RESULT]! 🚧$(CRLF)$(FG_TEXT)"
	@./$(TEST_FILE:.c=.out)
	@rm $(TEST_FILE:.c=.out)

.PHONY : \
	all clean fclean re \
	$(LIBFT) $(LIBFT)_clean $(LIBFT)_fclean \
	test

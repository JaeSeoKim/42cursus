# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/24 20:10:49 by jaeskim           #+#    #+#              #
#    Updated: 2020/10/18 22:21:50 by jaeskim          ###   ########.fr        #
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
SRC_PRINT_DIR = $(SRC_DIR)/print

OBJ_DIR = ./obj

vpath %.c \
	$(subst ./, , $(SRC_DIR))	\
	$(subst ./, , $(SRC_UTIL_DIR))	\
	$(subst ./, , $(SRC_PARSE_DIR))	\
	$(subst ./, , $(SRC_PRINT_DIR))

SRCS = \
	$(wildcard $(SRC_DIR)/*.c)	\
	$(wildcard $(SRC_UTIL_DIR)/*.c)	\
	$(wildcard $(SRC_PARSE_DIR)/*.c)	\
	$(wildcard $(SRC_PRINT_DIR)/*.c)

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

# Color
BG_BLACK   = \e[40m
BG_RED     = \e[41m
BG_GREEN   = \e[42m
BG_YELLOW  = \e[43m
BG_BLUE    = \e[44m
BG_MAGENTA = \e[45m
BG_CYAN    = \e[46m
BG_LGREY   = \e[47m
BG_DGREY   = \e[100m
BG_LRED    = \e[101m
BG_LGREEN  = \e[102m
BG_LYELLOW = \e[103m
BG_LBLUE   = \e[104m
BG_LMAGENTA= \e[105m
BG_LCYAN   = \e[106m
BG_WHITE   = \e[107m
 
FG_BLACK   = \e[30m
FG_RED     = \e[31m
FG_GREEN   = \e[32m
FG_YELLOW  = \e[33m
FG_BLUE    = \e[34m
FG_MAGENTA = \e[35m
FG_CYAN    = \e[36m
FG_LGREY   = \e[37m
FG_DGREY   = \e[90m
FG_LRED    = \e[91m
FG_LGREEN  = \e[92m
FG_LYELLOW = \e[93m
FG_LBLUE   = \e[94m
FG_LMAGENTA= \e[95m
FG_LCYAN   = \e[96m
FG_WHITE   = \e[97m
 
CL_BOLD   = \e[1m
CL_DIM    = \e[2m
CL_UDLINE = \e[4m
CL_BLINK  = \e[5m
CL_INVERT = \e[7m
CL_HIDDEN = \e[8m
 
NO_COLOR = \e[0m

LF = \033[1K\r

all : $(NAME)

clean : $(LIBFT)_clean
	$(RM) $(RMFLAGS) $(OBJS)

fclean : $(LIBFT)_fclean clean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all 

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBFT_INC_DIR) -c $< -o $@
	@printf "\033[38;5;214m$(LF)$(FG_LRED)Create \033[38;5;214m$@ $(FG_LRED)from \033[38;5;214m$<$(NO_COLOR) 🥑"
	@sleep 0.1

$(NAME) : $(LIBFT_FILE) $(OBJS)
	@printf "\n"
	@$(AR) $(ARFLAGS) $@ $(OBJS)
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
	@printf "[TEST RESULT]\n"
	@./$(TEST_FILE:.c=.out)
	@rm $(TEST_FILE:.c=.out)

.PHONY : \
	all clean fclean re \
	$(LIBFT) $(LIBFT)_clean $(LIBFT)_fclean \
	test

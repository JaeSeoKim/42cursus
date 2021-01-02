# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/24 20:10:49 by jaeskim           #+#    #+#              #
#    Updated: 2020/12/21 20:38:27 by jaeskim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

AR = ar
ARFLAGS = crs

CC = gcc
CFLAGS = -Wall -Wextra -Werror

ifeq ($(DEBUG),true)
	CDEBUG = -g
endif

RM = rm
RMFLAGS = -f

LIBFT = libft.a
LIBFT_DIR = ./lib/libft
LIBFT_FILE = $(LIBFT_DIR)/$(LIBFT)
LIBFT_INC_DIR = $(LIBFT_DIR)/include

INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj

HEADERS = $(addprefix $(INC_DIR)/, \
	ft_printf_parse.h	\
	ft_printf_util.h	\
	ft_printf.h	\
	ft_print.h	\
	ft_printf_type.h	\
	libftprintf.h	\
)

SRC_UTIL_DIR = $(SRC_DIR)/util
SRC_UTIL = $(addprefix $(SRC_UTIL_DIR)/, \
	ft_convert_base_custom.c	\
	ft_custom_dtoa.c	\
	ft_putstr_out.c	\
	ft_putchar_n_out.c	\
	ft_init_format.c	\
	ft_n_encoding_utf8.c	\
	ft_putwchar_out.c	\
	ft_putchar_out.c	\
)

SRC_PARSE_DIR = $(SRC_DIR)/parse
SRC_PARSE = $(addprefix $(SRC_PARSE_DIR)/, \
	ft_parse_flag.c	\
	ft_parse_type.c	\
	ft_parse_width.c	\
	ft_parse_precision.c	\
	ft_init_parsing.c	\
	ft_parse_extend_type.c	\
	ft_parse_check.c	\
)

SRC_PRINT_DIR = $(SRC_DIR)/print
SRC_PRINT = $(addprefix $(SRC_PRINT_DIR)/, \
	ft_print_char.c	\
	ft_print_number.c	\
	ft_write_cnt.c	\
	ft_print_percent.c	\
	ft_get_extend_num.c	\
	ft_print_float.c	\
	ft_print_unsigned_number.c	\
	ft_print_octal.c	\
	ft_print_float_nan.c	\
	ft_print_hex.c	\
	ft_print_string.c	\
	ft_get_extend_string.c	\
	ft_print_pointer.c	\
)

vpath %.c \
	$(SRC_DIR)	\
	$(SRC_UTIL_DIR)	\
	$(SRC_PARSE_DIR)	\
	$(SRC_PRINT_DIR)

SRCS = \
	$(SRC_DIR)/ft_print.c	\
	$(SRC_DIR)/ft_printf.c	\
	$(SRC_DIR)/ft_sprintf.c	\
	$(SRC_UTIL)	\
	$(SRC_PARSE)	\
	$(SRC_PRINT)

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
	@$(CC) $(CFLAGS) $(CDEBUG) -I $(INC_DIR) -I $(LIBFT_INC_DIR) -c $< -o $@
	@printf "$(LF)🚧 $(FG_TEXT)Create $(FG_TEXT_PRIMARY)$@ $(FG_TEXT)from $(FG_TEXT_PRIMARY)$<"

$(NAME) : $(LIBFT_FILE) $(HEADERS) $(OBJS)
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

debug_make : $(NAME) $(TEST_FILE)
	$(CC) -g -I $(INC_DIR) -I $(LIBFT_INC_DIR) $(TEST_FILE) -o $(TEST_FILE:.c=.out) -L. -lftprintf

test : $(NAME) $(TEST_FILE)
	@$(CC) -g -I $(INC_DIR) -I $(LIBFT_INC_DIR) $(TEST_FILE) -o $(TEST_FILE:.c=.out) -L. -lftprintf
	@printf "$(FG_TEXT_PRIMARY)$(BG_BLACK)🚧 [TEST RESULT]! 🚧$(CRLF)$(FG_TEXT)"
	@./$(TEST_FILE:.c=.out)
	@rm $(TEST_FILE:.c=.out)
	@rm -rf $(TEST_FILE:.c=.out.dSYM)

.PHONY : \
	all clean fclean re \
	$(LIBFT) $(LIBFT)_clean $(LIBFT)_fclean \
	test debug_make

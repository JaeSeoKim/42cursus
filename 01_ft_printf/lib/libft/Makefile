# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/24 20:10:49 by jaeskim           #+#    #+#              #
#    Updated: 2020/10/27 18:06:43 by jaeskim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

AR = ar
ARFLAGS = crs

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm
RMFLAGS = -f

INC_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = ./obj

SRC_LST_DIR = $(SRC_DIR)/lst
SRC_LST = $(addprefix $(SRC_LST_DIR)/, \
	ft_lstadd_back.c	\
	ft_lstadd_front.c	\
	ft_lstclear.c	\
	ft_lstdelone.c	\
	ft_lstiter.c	\
	ft_lstlast.c	\
	ft_lstmap.c	\
	ft_lstnew.c	\
	ft_lstsize.c	\
)

SRC_MATH_DIR = $(SRC_DIR)/math
SRC_MATH = $(addprefix $(SRC_MATH_DIR)/, \
	ft_pow.c	\
)


SRC_MEMORY_DIR = $(SRC_DIR)/memory
SRC_MEMORY = $(addprefix $(SRC_MEMORY_DIR)/, \
	ft_bzero.c	\
	ft_calloc.c	\
	ft_memccpy.c	\
	ft_memchr.c	\
	ft_memcmp.c	\
	ft_memcpy.c	\
	ft_memmove.c	\
	ft_memset.c	\
	ft_frees.c	\
)

SRC_STRING_DIR = $(SRC_DIR)/string
SRC_STRING = $(addprefix $(SRC_STRING_DIR)/, \
	ft_atoi.c	\
	ft_itoa.c	\
	ft_split.c	\
	ft_strchr.c	\
	ft_strdup.c	\
	ft_strjoin.c	\
	ft_strlcat.c	\
	ft_strlcpy.c	\
	ft_strlen.c	\
	ft_strmapi.c	\
	ft_strncmp.c	\
	ft_strndup.c	\
	ft_strnstr.c	\
	ft_strrchr.c	\
	ft_strtrim.c	\
	ft_substr.c	\
	ft_convert_base_unsigned.c	\
	ft_convert_base.c	\
	ft_dtoa.c	\
	ft_strjoin_with_frees.c	\
)

SRC_TYPE_DIR = $(SRC_DIR)/type
SRC_TYPE = $(addprefix $(SRC_TYPE_DIR)/, \
	ft_isalnum.c	\
	ft_isalpha.c	\
	ft_isascii.c	\
	ft_isdigit.c	\
	ft_isprint.c	\
	ft_tolower.c	\
	ft_toupper.c	\
)

SRC_UTF8_DIR = $(SRC_DIR)/utf8
SRC_UTF8 = $(addprefix $(SRC_UTF8_DIR)/, \
	ft_encoding_utf8.c	\
	ft_putwchar_fd.c	\
	ft_wchar_len.c	\
)

SRC_WRITE_DIR = $(SRC_DIR)/write
SRC_WRITE = $(addprefix $(SRC_WRITE_DIR)/, \
	ft_putchar_fd.c	\
	ft_putendl_fd.c	\
	ft_putnbr_fd.c	\
	ft_putstr_fd.c	\
)

SRCS = \
	$(SRC_LST)	\
	$(SRC_MATH)	\
	$(SRC_MEMORY)	\
	$(SRC_STRING)	\
	$(SRC_TYPE)	\
	$(SRC_UTF8)	\
	$(SRC_WRITE)

vpath %.c \
	$(subst ./, , $(SRC_DIR))	\
	$(subst ./, , $(SRC_LST_DIR))	\
	$(subst ./, , $(SRC_MATH_DIR))	\
	$(subst ./, , $(SRC_MEMORY_DIR))	\
	$(subst ./, , $(SRC_STRING_DIR))	\
	$(subst ./, , $(SRC_TYPE_DIR))	\
	$(subst ./, , $(SRC_WRITE_DIR))	\
	$(subst ./, , $(SRC_UTF8_DIR))

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

clean :
	@$(RM) $(RMFLAGS) $(OBJS) $(OBJS_BONUS)
	@printf "$(LF)🧹 $(FG_TEXT)Cleaning $(FG_TEXT_PRIMARY)$(NAME)'s Object files...\n"

fclean : clean
	@$(RM) $(RMFLAGS) $(NAME)
	@printf "$(LF)🧹 $(FG_TEXT)Cleaning $(FG_TEXT_PRIMARY)$(NAME)\n"
	
re : fclean all

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@
	@printf "$(LF)🚧 $(FG_TEXT)Create $(FG_TEXT_PRIMARY)$@ $(FG_TEXT)from $(FG_TEXT_PRIMARY)$<"

$(NAME) : $(OBJS)
	@printf "$(LF)🚀 $(FG_TEXT)Successfully Created $(FG_TEXT_PRIMARY)$(NAME)'s Object files $(FG_TEXT)!"
	@printf "$(CRLF)📚 $(FG_TEXT)Archiving! $(FG_TEXT_PRIMARY)$@"
	@$(AR) $(ARFLAGS) $@ $^
	@printf "$(LF)🎉 $(FG_TEXT)Successfully Archived $(FG_TEXT_PRIMARY)$@ $(FG_TEXT)!\n"

.PHONY: all clean fclean re

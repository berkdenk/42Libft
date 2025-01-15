# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdenk <bdenk@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/15 15:51:43 by bdenk             #+#    #+#              #
#    Updated: 2025/01/15 15:51:45 by bdenk            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
      ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
      ft_memchr.c ft_memcpy.c ft_memmove.c ft_memset.c \
      ft_strchr.c ft_strdup.c ft_toupper.c \
      ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
      ft_strnstr.c ft_strrchr.c ft_substr.c ft_tolower.c \
      ft_memcmp.c ft_strjoin.c ft_strtrim.c ft_split.c \
      ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
      ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BSRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
      ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c\
      ft_lstmap.c \

OBJS = ${SRC:.c=.o}
OBJSB = ${BSRCS:.c=.o}
LIBC = ar rcs
CC = cc
RM = rm -f

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} 

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

bonus: $(OBJS) $(OBJSB)
	$(LIBC) $(NAME) $(OBJSB)

all: $(NAME)

clean:
	${RM} $(OBJS) $(OBJSB)

fclean: clean
	${RM} $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re

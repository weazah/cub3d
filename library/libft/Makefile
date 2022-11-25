# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozahir <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/21 23:33:47 by ozahir            #+#    #+#              #
#    Updated: 2021/11/21 23:40:03 by ozahir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
	ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
OBJ = ${SRC:.c=.o}

CC = gcc
CFLAGS = -Wall -Werror -Wextra
HEADER = libft.h
NAME = libft.a

%.o: %.c $(HEADER) 
		@$(CC) $(CFLAGS)  -c -o $@ $<

${NAME} : ${OBJ} ${HEADER}
	@ar -rc ${NAME} ${OBJ}
	@echo "<libft compiled>" 
clean:
	@rm -f ${OBJ}
fclean : clean
	@rm -f ${NAME}
re : fclean all
all : ${NAME}

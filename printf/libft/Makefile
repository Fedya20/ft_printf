FLAG = -Wall -Wextra -Werror

NAME = libft.a

SRC = ft_isalpha.c ft_isdigit.c ft_isascii.c ft_isprint.c \
			ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
			ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c \
			ft_tolower.c ft_strchr.c ft_strncmp.c ft_memchr.c \
			ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c \
			ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
			ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_isalnum.c ft_strrchr.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "$(NAME) created"
	@ranlib $(NAME)
	@echo "$(NAME) indexed"

%.o: %.c
	@gcc $(FLAG) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "OBJ deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all 

.PHONY: all, clean, fclean, re

#PHONY sert a montrer a makefille que ce ne sont pas des fichiers.#
# $@ veut dire la target du fichier ou on l ecrit par exemple dans %.o le $@ veut dire "%.o"#
# @"fonction" dit a makefille de faire cette fonction dans le terminal#
# $< veut dire la premiere prerequisition dans le "%.o: %.c" il veut dire le %.c#
# Wildcard veut dire une liste de noms de fichiers existants, séparés par des espaces, qui correspondent à l'un des modèles de noms de fichiers donnés#

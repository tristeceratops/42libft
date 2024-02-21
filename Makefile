NAME := libft.a
FLAGS := -Wall -Wextra -Werror
FILES := ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
	ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
	ft_strchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
	ft_calloc.c ft_strdup.c ft_substrc.c ft_strjoin.c
all: $(NAME)

clean:
	rm *.o
fclean: clean
	rm $(NAME)
re: fclean all

obj:
	cc $(FLAGS) -c *.c
$(NAME): obj
	ar -rcs $(NAME) *.o
main.o:
	cc -c main.c -o main.o
main: main.o
	cc -o main main.o -L. libft.a
mclean:
	rm main.o main

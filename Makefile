flags :=-Wall -Wextra -Werror
files :=ft_isalpha.c
lib :=libft.h

all: libft.a

clean:
	rm *.o
fclean: clean
	rm libft.a
re: fclean all

obj:
	cc -c *.c
libft.a: obj
	ar -rcs libft.a *.o

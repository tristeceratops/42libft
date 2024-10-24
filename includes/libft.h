/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <ewoillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:31:38 by ewoillar          #+#    #+#             */
/*   Updated: 2024/10/23 14:01:18 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_alloc
{
	void			*adress;
	struct s_alloc	*next;
}	t_alloc;

int			ft_atoi(const char *nptr);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strrchr(const char *s, int c);
int			ft_tolower(int c);
int			ft_toupper(int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		*trim_left(char const *s, char const *set);
char		*trim_right(char const *s, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
// bonus
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
// ft_printf
int			ft_printf(const char *str, ...);
int			ft_printf_char(va_list arg);
int			ft_printf_dec(va_list arg);
int			ft_printf_unsigned_dec(va_list arg);
int			ft_printf_str(va_list arg);
int			ft_printf_hex(va_list arg, char *base);
int			ft_printf_ptr(va_list arg);
int			print_hex(char *base, unsigned long long u);
// get_next_line
char		*get_next_line(int fd);
char		*get_line(char **remainder);
int			has_newline(char *str);
char		*gnl_ft_strjoin(char *s1, char *s2);
char		*gnl_ft_strdup(const char *s);
char		*gnl_ft_substr(char const *s, unsigned int start, size_t len);
char		*get_line_null(char **remainder, char **line);
//gc
void		gc_free(void *adress, t_alloc **mem);
void		gc_free_all(t_alloc **mem);
void		insert_alloc(void *ptr, t_alloc **mem);
void		*gc_malloc(int size, t_alloc **mem);
void		*gc_calloc(size_t nmemb, size_t size, t_alloc **mem);
char		*gc_strjoin(char const *s1, char const *s2, t_alloc **mem);
char		**gc_split(char const *s, char c, t_alloc **mem);
char		*gc_strdup(const char *s, t_alloc **mem);
char		*gc_itoa(int n, t_alloc **mem);

//other
int			ft_isspace(char c);

#endif

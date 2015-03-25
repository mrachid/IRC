/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:38:45 by mrachid           #+#    #+#             */
/*   Updated: 2014/05/08 15:04:40 by mrachid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFT_H
# define _LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# define BLACK		ft_putstr("\033[30m")
# define RED		ft_putstr("\033[31m")
# define GREEN		ft_putstr("\033[32m")
# define YELLOW		ft_putstr("\033[33m");
# define BLUE		ft_putstr("\033[34m")
# define PURPLE		ft_putstr("\033[35m")
# define CYAN		ft_putstr("\033[36m")
# define GREY		ft_putstr("\033[37m")
# define HIGHLIGHT	ft_putstr("\033[1m")
# define UNDERLINE	ft_putstr("\033[4m")
# define CANCEL		ft_putstr("\033[0m")
# define BUFF_SIZE 4096

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_store
{
	void			*value;
	int				val;
	struct s_store	*prev;
	struct s_store	*next;
}					t_store;

void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putnbr(int n);
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
void				ft_strclr(char *s);
char				*ft_strcpy(char *s1, const char *s2);
char				*ft_strncpy(char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, int n);
int					ft_atoi(const char *str);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *s1, const void *s2, size_t n);
void				*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void				*ft_memmove(void *s1, const void *s2, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void(*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strreverse(char *s);
char				*ft_itoa(int n);
char				**ft_strsplit(char const *s, char c);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstrev(t_list **alst);
void				ft_lstaddend(t_list **alst, t_list *new);
void				ft_lst_db_add(t_store **alst, t_store *elem);
void				ft_lst_db_addend(t_store **alst, t_store *elem);
t_store				*ft_lst_db_new(char *value, int val);
int					get_next_line(int const fd, char **line);
#endif

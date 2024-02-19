/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:17:11 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/15 14:54:32 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

//			basic libc
int			ft_isalnum(int i);
int			ft_isalpha(int i);
int			ft_isascii(int i);
int			ft_isdigit(int i);
int			ft_isprint(int i);
int			ft_isspace(int c);
void		*ft_memset(void *b, int c, size_t len);
size_t		ft_strlcpy(char *dst, char *src, unsigned int size);
size_t		ft_strlen(const char *str);
int			ft_tolower(int c);
int			ft_toupper(int c);
size_t		ft_strlcat(char *dst, char *src, size_t dstsize);
void		ft_bzero(void *s, size_t n);
char		*ft_strchr(const char *s, int c);
void		ft_strdel(char **array);
char		*ft_strrchr(const char *s, int c);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strdup(const char *s1);
void		*ft_calloc(size_t count, size_t size);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strrncmp(const char *str, const char *str2, size_t n);
char		*ft_strnstr(const char *haystack, const char *ndl, size_t len);
int			ft_atoi(const char *str);
void		ft_putchar_fd(int c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_itoa(int n);
char		**ft_split(char const *s, char c);
//			lists
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
//			extras
int			ft_lstpos(t_list *lst, int *value);
void		*ft_cleanp(void *p);
int			ft_countdigit(long num);
long		ft_atol(const char *str);
size_t		ft_strnlen(const char *str, int n);
char		*ft_strndup(const char *s1, int n);
void		ft_free_string(void *ptr); // falta
void		ft_memdel(void **ap); // falta
char		*ft_strpbrk(const char *s, const char *charset);
char		*ft_strjoin_free_first(char *s1, char *s2);
int			ft_strcmp(char *s1, char *s2);
char		*ft_first_word(char *str);
int			ft_arrlen(char **str);

#endif

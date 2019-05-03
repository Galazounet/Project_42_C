/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 16:52:50 by afrangio          #+#    #+#             */
/*   Updated: 2019/03/15 21:29:31 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGFT_H
# define STRINGFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <wchar.h>

/*
** check
*/
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);
int				ft_isnumber(char *str);

/*
** comparaisons
*/
int				ft_strcmp(char const *s1, const char *s2);
int				ft_strequ(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strstr(const char *haystack, const char *needle);
/*
** conversions
*/
int				ft_atoi(const char *str);
long			ft_atol(const char *str);

char			*ft_itoa(intmax_t n);
char			*ft_itoa_base(intmax_t n, int b, int capslock);
char			*ft_uitoa_base(uintmax_t n, int b, int capslock);
/*
** search
*/
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *hay, const char *needle, size_t len);
void			ft_strclr(char *s);
int				ft_indexof(char *s, char c);

/*
** other
*/
char			*ft_strcpy(char *dst, const char *src);
void			ft_strdel(char **as);
char			*ft_strdup(const char *src);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(const char *s1, const char *s2);
size_t			ft_strlen(const char *str);
char			*ft_strmap(const char *s, char (*f)(char));
char			*ft_strmapi(const char *s, char(*f)(unsigned int, char));
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strnew(size_t size);
char			*ft_strrchr(const char *s, int c);
char			**ft_strsplit(const char *s, char c);
char			*ft_strsub(const char *s, unsigned int start, size_t len);
char			*ft_strtrim(const char *s);
int				ft_tolower(int c);
int				ft_toupper(int c);

#endif

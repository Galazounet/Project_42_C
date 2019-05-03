/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ioft.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 16:52:54 by afrangio          #+#    #+#             */
/*   Updated: 2019/03/15 21:29:15 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IOFT_H
# define IOFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <wchar.h>

void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl(const char *str);
void			ft_putendl_fd(const char *str, int fd);
void			ft_putnbr(intmax_t n);
void			ft_putunbr(uintmax_t n);
void			ft_putnbr_fd(intmax_t n, int fd);
void			ft_putunbr_fd(uintmax_t n, int fd);
void			ft_putstr(const char *str);
void			ft_putstrlen(const char *str, int len);
void			ft_putstr_fd(const char *str, int fd);
void			ft_putstrlen_fd(const char *str, int fd, int len);
void			ft_putwchar_fd(wchar_t chr, int fd);
void			ft_putwchar(wchar_t chr);

#endif

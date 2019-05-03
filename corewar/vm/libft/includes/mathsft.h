/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathsft.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 16:52:19 by afrangio          #+#    #+#             */
/*   Updated: 2019/03/15 21:29:22 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHSFT_H
# define MATHSFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <wchar.h>

uintmax_t		ft_log(intmax_t n, int b);
int				ft_max(int a, int b);
int				ft_min(int a, int b);
int				ft_pow(int a, int b);
uintmax_t		ft_ulog(uintmax_t n, uintmax_t b);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:20:58 by dygouasd          #+#    #+#             */
/*   Updated: 2018/01/27 16:32:48 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define ABS(Value) Value > 0 ? Value : -Value
# define ISDIGIT(x) (x >= '1' && x <= '9')
# define SIGNED 1
# define UNSIGNED 0
# define OPT_H  1
# define OPT_HH 1 << 1
# define OPT_L  1 << 2
# define OPT_LL 1 << 3
# define OPT_J  1 << 4
# define OPT_Z  1 << 5
# define OPT_0 1 << 6
# define OPT_NEG 1 << 7
# define OPT_POS 1 << 8
# define OPT_ASH 1 << 9
# define OPT_SPACE 1 << 10
# define OPT_PRECI 1 << 11
# define OPT_FIELD 1 << 12
# define BUFF_SIZE 4096

union					u_data
{
	intmax_t			integer;
	unsigned long long	uinteger;
	char				*string;
	char				*pointer;
	wchar_t				*wildchars;
	wchar_t				wildcharc;
};

typedef struct			s_tool
{
	va_list				list;
	const char			*format;
	unsigned int		i;
	unsigned int		i_buf;
	int					precision;
	int					champs;
	int					base;
	int					fill;
	long				wcharlen;
	int					mask;
	int					sign;
	char				buffer[BUFF_SIZE];
	union u_data		data;
}						t_tool;

typedef struct			s_conv
{
	char				conv;
	int					(*func)(t_tool *);
}						t_conv;

typedef struct			s_opts
{
	char				opt;
	int					(*func)(t_tool *);
}						t_opts;

int						ft_printf(const char *format, ...);
int						conv_d(t_tool *tl);
int						conv_x(t_tool *tl);
int						conv_big_x(t_tool *tl);
int						conv_o(t_tool *tl);
int						conv_big_o(t_tool *tl);
int						conv_u(t_tool *tl);
int						conv_big_u(t_tool *tl);
int						conv_s(t_tool *tl);
int						conv_big_s(t_tool *tl);
int						conv_c(t_tool *tl);
int						conv_big_c(t_tool *tl);
int						conv_p(t_tool *tl);
int						conv_i(t_tool *tl);
int						conv_big_d(t_tool *tl);
int						conv_b(t_tool *tl);
int						conv_percent(t_tool *tl);
int						conv_nothing(t_tool *tl);
int						set_flag(t_tool *tl);
int						set_hashtag(t_tool *tl);
int						set_zero(t_tool *tl);
int						set_sub(t_tool *tl);
int						set_add(t_tool *tl);
int						set_space(t_tool *tl);
int						set_point(t_tool *tl);
int						set_field(t_tool *tl);
int						my_args(t_tool *tl, int sign);
void					flag_z(t_tool *t, int is_unsigned);
void					flag_h(t_tool *t, int is_unsigned);
void					flag_l(t_tool *t, int is_unsigned);
void					flag_hh(t_tool *t, int is_unsigned);
void					flag_ll(t_tool *t, int is_unsigned);
void					flag_j(t_tool *t, int is_unsigned);
int						n_length(unsigned long long n, int base);
int						itoa_base_spec(t_tool *tl, intmax_t n, int len, int un);
int						put_neg(t_tool *tl);
int						write_buff(t_tool *tl);
int						my_atoi(t_tool *tl);
int						put_champ(t_tool *tl);
void					expuls_force(t_tool *tl, int next);
void					ft_putstr(char *str);
int						put_precision(t_tool *tl, int len);
int						conv_d_with_sub(t_tool *tl, int i);
int						conv_d_without_sub(t_tool *tl, int len, int sub);
int						flag_l_c(char *s, int i);
int						count_wcharlen(int i);
int						count_wcharl(wchar_t *s, t_tool *tl);
size_t					ft_strlen(const char *s);
int						printf_str(t_tool *tl);
int						printf_strwchar(wchar_t *s, t_tool *tl);
int						printf_strnull(t_tool *tl);
int						printf_b(intmax_t i, t_tool *tl);
int						count_b(intmax_t i);

#endif

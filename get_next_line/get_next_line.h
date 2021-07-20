/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:13:53 by dygouasd          #+#    #+#             */
/*   Updated: 2017/11/20 13:16:51 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# define BUFF_SIZE 1
# define BUFF_LEN 4096
# define BUFF_TOTAL (BUFF_SIZE + BUFF_LEN)
# include "./libft/libft.h"


typedef struct		s_box
{
	int				fd;
	int				indice;
	struct s_box	*next;
	char			*pos;
	char			*buff;
}					t_p;

int					get_next_line(const int fd, char **line);

#endif

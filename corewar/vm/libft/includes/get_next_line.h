/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 20:35:14 by afrangio          #+#    #+#             */
/*   Updated: 2018/11/23 19:57:59 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <limits.h>

# ifdef __linux__
#  define OPEN_MAX FOPEN_MAX
# endif

# define BUFF_SIZE 20

int	get_next_line(int fd, char **line);

#endif

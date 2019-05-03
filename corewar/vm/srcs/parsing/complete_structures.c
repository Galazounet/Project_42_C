/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_structures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 15:18:06 by afrangio          #+#    #+#             */
/*   Updated: 2019/02/21 04:50:33 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

static int	bytes_to_int(uint8_t *bytes, unsigned *integer)
{
	unsigned i;
	unsigned j;

	i = 0;
	j = 0;
	i = (bytes[0] | i) << 8;
	i = bytes[1] | i;
	j = (bytes[2] | j | i) << 8;
	j = bytes[3] | j;
	*integer = (i | j);
	if (*integer > CHAMP_MAX_SIZE)
		return (BIG_INSTRUCTION);
	return (SUCCESS);
}

static int	check_magic(int fd, t_warrior *warrior)
{
	static uint8_t	magic[4] = MAGIC;
	ssize_t			ret;

	if ((ret = read(fd, warrior->magic, 4)) != 4)
		return (WRONG_MAGIC);
	else if (ft_memcmp(warrior->magic, magic, 4))
		return (WRONG_MAGIC);
	else
		return (SUCCESS);
}

static int	complete_meta(int fd, t_warrior *warrior)
{
	ssize_t	ret;
	uint8_t	bytes[4];
	char	*buffer[200];

	if ((ret = read(fd, warrior->name, PROG_NAME_LEN)) != PROG_NAME_LEN)
		return (WRONG_FILE_FORMAT);
	else if ((ret = read(fd, bytes, 4)) != 4)
		return (WRONG_FILE_FORMAT);
	else if ((ret = read(fd, bytes, 4)) != 4)
		return (WRONG_FILE_FORMAT);
	else if (bytes_to_int(bytes, &(warrior->len)))
		return (BIG_INSTRUCTION);
	else if ((ret = read(fd, warrior->comment, COMMENT_LEN)) != COMMENT_LEN)
		return (WRONG_FILE_FORMAT);
	else if ((ret = read(fd, bytes, 4)) != 4)
		return (WRONG_FILE_FORMAT);
	else if ((ret = read(fd, (warrior->instructions), warrior->len))
			!= warrior->len)
		return (WRONG_FILE_FORMAT);
	else if (read(fd, buffer, 1) != 0)
		return (WRONG_FILE_FORMAT);
	else
		return (SUCCESS);
}

static int	complete(int fd, t_warrior *warrior)
{
	int			ret;

	if ((ret = check_magic(fd, warrior)) != 0)
		return (ret);
	else if ((ret = complete_meta(fd, warrior)) != 0)
		return (ret);
	else
		return (SUCCESS);
}

int			complete_structures(t_cv *env)
{
	int i;
	int ret;
	int fd;

	i = 0;
	while (i < env->nb_warriors)
	{
		if ((fd = open(env->warrior[i].file_name, O_RDONLY)) <= 0)
			return (ERRNO_CODE);
		if ((ret = complete(fd, &(env->warrior[i]))) != 0)
		{
			close(fd);
			return (ret);
		}
		close(fd);
		++i;
	}
	complete_colors(env);
	return (SUCCESS);
}

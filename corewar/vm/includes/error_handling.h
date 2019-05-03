/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 02:43:01 by afrangio          #+#    #+#             */
/*   Updated: 2019/02/22 23:59:27 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLING_H
# define ERROR_HANDLING_H

# define ERROR_LEN 9

# define SUCCESS 0
# define WRONG_MAGIC 1
# define WRONG_FILE_FORMAT 1
# define BIG_INSTRUCTION 2
# define TOO_MANY_WARRIORS 3
# define USAGE 4
# define WRONG_EXTENTION 5
# define ERRNO_CODE 6
# define DOUBLE_ASSIGN 7
# define NEGATIVE_OR_ZERO 8

/*
** Message handler
*/
int		errorhandler_parser(int error_code);

/*
** Error messages
*/
void	wrong_magic(void);
void	big_instruction(void);
void	too_many_warriors(void);
void	wrong_extention(void);
void	errno_error(void);
void	double_assign(void);
void	neg_or_zero(void);
void	show_usage(void);

#endif

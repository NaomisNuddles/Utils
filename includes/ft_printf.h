/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:55:58 by nleandro          #+#    #+#             */
/*   Updated: 2024/12/10 21:57:51 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

# define HEXMA "0123456789ABCDEF"
# define HEXMI "0123456789abcdef"
# define OCTA "01234567"
# define DECA "0123456789"
# define PTR_HU "0X"
# define PTR_HD "0x"
# define PTR_OC "0"
# define SIG_NEG "-"
# define SIG_POS "+"
# define SIG_SPC " "

typedef enum e_check
{
	TRUE = 1,
	FALSE = 0
}	t_check;

typedef enum e_type
{
	NONE = 0,
	CHAR = 1,
	STR = 2,
	INT = 3,
	UNS = 4,
	PTR = 5
}	t_type;

typedef enum e_flags
{
	FILLED = 1,
	EMPTY = 0
}	t_flags;

typedef struct s_arg
{
	char	*str;
	char	*at_s;
	char	*extra;
	char	*prc;
}	t_arg;

typedef struct s_format
{
	t_arg	*arg;
	int		width;
	int		precision;
	char	*base;
	t_type	type;
	t_flags	flags;
	t_check	neg;
	t_check	pos;
	t_check	space;
	t_check	zero;
	t_check	hash;
	t_check	quote;
}	t_format;

typedef struct s_data
{
	va_list		vars;
	t_format	*format;
	const char	*str;
	int			len;
	int			index;
}	t_data;

//		aux_itoas.c
char		*uns_itoa_base(unsigned int val, char *base);
char		*unsl_itoa_base(unsigned long val, char *base);
//		aux_checks.c
t_data		*flags_check(char c, t_data *data);
t_data		*type_check(char c, t_data *data);
t_data		*build_check(t_data *data);
//		aux_types.c
t_data		*is_int(t_data *data, int num);
t_data		*is_char(t_data *data, int num);
t_data		*is_str(t_data *data, char *str);
t_data		*is_uns(t_data *data, unsigned int val);
t_data		*is_ptr(t_data *data, unsigned long int val);
//		aux_builds.c
t_data		*precision_build(t_data *data);
t_data		*width_build(t_data *data);
t_data		*format_build(t_data *data);
//		aux_utils.c
t_data		*set_data(void);
t_data		*reset_data(t_data *data);
t_data		*free_build(t_data *data);
void		free_data(t_data *data);
//		ft_printf.c - static construct and data_format
int			ft_printf(const char *end, ...);

#endif //FT_PRINTF_H
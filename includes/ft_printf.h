/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:55:58 by nleandro          #+#    #+#             */
/*   Updated: 2025/01/01 00:59:53 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

# define HEXMA "0123456789ABCDEF"
# define HEXMI "0123456789abcdef"
# define OCTA "01234567"
# define BIN "01"
# define DECA "0123456789"
# define PTR_HU "0X"
# define PTR_HD "0x"
# define PTR_OC "0"
# define SIG_NEG "-"
# define SIG_POS "+"
# define SIG_SPC " "
# define PTR_POS "+0x"
# define PTR_SPC " 0x"

typedef enum e_check
{
	TRUE,
	FALSE
}	t_check;

typedef enum e_type
{
	NONE,
	CHAR,
	STR,
	INT,
	UNS,
	PTR,
	CEN
}	t_type;

typedef enum e_flags
{
	FILLED,
	EMPTY
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
	t_check	format;
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
void		flags_check(char c, t_data *data);
void		type_check(char c, t_data *data);

//		aux_types.c
void		is_int(t_data *data, int num);
void		is_char(t_data *data, int num);
void		is_str(t_data *data, char *str);
void		is_uns(t_data *data, unsigned int val);
void		is_ptr(t_data *data, unsigned long int val);

//		aux_builds.c
void		type_build(t_data *data);
void		precision_build(t_data *data);
void		width_build(t_data *data);

//		aux_data.c
//static t_data		*null_data(t_data *data);
t_data		*set_data(const char *str);
void		reset_data(t_data *data);
void		free_data(t_data *data);

//		aux_format.c
void		find_format(t_data	*data);
void		construct_format(t_data	*data);
void		print_format(t_data *data);

//		ft_printf.c
int			ft_printf(const char *end, ...);

#endif //FT_PRINTF_H
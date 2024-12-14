/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:26:41 by nleandro          #+#    #+#             */
/*   Updated: 2024/12/12 16:21:26 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	*flags_check(char c, t_data *data)
{
	if (c == 43)
		data->format->pos = TRUE;
	else if (c == 45)
		data->format->neg = TRUE;
	else if (c == 32)
		data->format->space = TRUE;
	else if (c == 48)
		data->format->zero = TRUE;
	else if (c == 39)
		data->format->quote = TRUE;
	else if (c == 35)
		data->format->hash = TRUE;
	else
		data->format->flags = FILLED;
	if (data->format->pos == TRUE)
		data->format->space = FALSE;
	if (data->format->neg == TRUE)
		data->format->zero = FALSE;
	return (data);
}

t_data	*type_check(char c, t_data *data)
{
	if (c == 'd' || c == 'i')
		data->format->type = INT;
	else if (c == 'c')
		data->format->type = CHAR;
	else if (c == 's')
		data->format->type = STR;
	else if (c == 'p')
		data->format->type = PTR;
	else if (c == 'u' || c == 'o' || c == 'x' || c == 'X')
		data->format->type = UNS;
	else
		data->format->type = NONE;
	if (c == 'o')
		data->format->base = OCTA;
	else if (c == 'p' || c == 'x')
		data->format->base = HEXMI;
	else if (c == 'X')
		data->format->base = HEXMA;
	else if (c == 'i' || c == 'd' || c == 'u')
		data->format->base = DECA;
	return (data);
}

t_data	*build_check(t_data *data)
{
	if (data->format->precision >= 0 && (data->format->type == INT || \
	data->format->type == UNS))
		data->format->zero = FALSE;
	if (data->format->type == INT)
		data = is_int(data, va_arg(data->vars, int));
	else if (data->format->type == CHAR)
		data = is_char(data, va_arg(data->vars, int));
	else if (data->format->type == STR)
		data = is_str(data, va_arg(data->vars, char *));
	else if (data->format->type == UNS)
		data = is_uns(data, va_arg(data->vars, unsigned int));
	else if (data->format->type == PTR)
		data = is_ptr(data, va_arg(data->vars, unsigned long int));
	else if (data->format->type == NONE)
	{
		while (data->str[data->index] != 37)
			data->index--;
	}
	return (data);
}

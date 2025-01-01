/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:26:41 by nleandro          #+#    #+#             */
/*   Updated: 2024/12/31 23:41:41 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flags_check(char c, t_data *data)
{
	if (c == '+')
		data->format->pos = TRUE;
	else if (c == '-')
		data->format->neg = TRUE;
	else if (c == ' ')
		data->format->space = TRUE;
	else if (c == '0')
		data->format->zero = TRUE;
	else if (c == '\'')
		data->format->quote = TRUE;
	else if (c == '#')
		data->format->hash = TRUE;
	else
		data->format->flags = FILLED;
	if (data->format->pos == TRUE)
		data->format->space = FALSE;
	if (data->format->neg == TRUE)
		data->format->zero = FALSE;
}

void	type_check(char c, t_data *data)
{
	if (c == 'd' || c == 'i')
		data->format->type = INT;
	else if (c == 'c')
		data->format->type = CHAR;
	else if (c == 's')
		data->format->type = STR;
	else if (c == 'p')
		data->format->type = PTR;
	else if (c == 'u' || c == 'o' || c == 'x' || c == 'X' || c == 'b')
		data->format->type = UNS;
	else if (c == '%')
		data->format->type = CEN;
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
	else if (c == 'b')
		data->format->base = BIN;
}

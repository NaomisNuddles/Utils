/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:26:59 by nleandro          #+#    #+#             */
/*   Updated: 2024/12/12 16:06:34 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_data	*construct(t_data *data)
{
	while (data->format->flags == EMPTY)
	{
		data->index++;
		data = flags_check(data->str[data->index], data);
	}
	if (ft_isdigit(data->str[data->index]))
		data->format->width = ft_atoi(&data->str[data->index]);
	while (ft_isdigit(data->str[data->index]))
		data->index++;
	if (data->str[data->index] == 46)
	{
		data->format->precision = ft_atoi(&data->str[data->index + 1]);
		data->index++;
	}
	while (ft_isdigit(data->str[data->index]))
		data->index++;
	if (data->str[data->index] == 37 && ++data->len)
	{
		ft_putchar_fd(data->str[data->index], 1);
		return (free_build(data));
	}
	type_check(data->str[data->index], data);
	data = build_check(data);
	data = format_build(data);
	return (free_build(data));
}

static t_data	*data_format(t_data	*data)
{
	if (data->str[data->index] != 37 || (data->str[data->index] == 37 && \
		data->str[data->index + 1] == 37))
	{
		ft_putchar_fd(data->str[data->index], 1);
		data->len++;
		if (data->str[data->index] == 37)
			data->index++;
	}
	else if (data->str[data->index] == 37)
		data = construct(reset_data(data));
	return (data);
}

int	ft_printf(const char *str, ...)
{
	t_data	*data;
	int		len;

	data = set_data();
	if (!data)
		return (0);
	if (!str)
		return (-1);
	data->len = 0;
	data->index = 0;
	data->str = str;
	va_start(data->vars, str);
	while (data->index < (int)ft_strlen(str))
	{
		data = data_format(data);
		data->index++;
	}
	va_end(data->vars);
	len = data->len;
	free_data(data);
	return (len);
}

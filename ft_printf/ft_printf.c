/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:26:59 by nleandro          #+#    #+#             */
/*   Updated: 2024/12/15 15:56:37 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	t_data	*data;
	int		len;

	if (!str)
		return (-1);
	data = set_data(str);
	if (!data)
		return (0);
	va_start(data->vars, str);
	while (data->index < (int)ft_strlen(str))
	{
		find_format(data);
		if (data->format->format == TRUE)
		{
			construct_format(data);
			print_format(data);
			reset_data(data);
		}
		data->index++;
	}
	va_end(data->vars);
	len = data->len;
	free_data(data);
	return (len);
}

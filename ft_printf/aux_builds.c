/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_builds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:26:52 by nleandro          #+#    #+#             */
/*   Updated: 2024/12/12 16:17:48 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	*precision_build(t_data *data)
{
	size_t	size;

	size = (size_t)data->format->precision - ft_strlen(data->format->arg->str);
	if (ft_strlen(data->format->base) == 8)
		size -= 1;
	data->format->arg->prc = ft_calloc(1, size + 1);
	if (!data->format->arg->prc)
		return (data);
	data->format->arg->prc = \
	ft_memset(data->format->arg->prc, 48, size);
	if (data->format->width < (int)(ft_strlen(data->format->arg->at_s) + \
	ft_strlen(data->format->arg->str) + ft_strlen(data->format->arg->prc)))
		data->format->width = 0;
	return (data);
}

t_data	*width_build(t_data *data)
{
	size_t	size;

	size = (size_t)data->format->width - \
	(ft_strlen(data->format->arg->at_s) + ft_strlen(data->format->arg->str) \
	+ ft_strlen(data->format->arg->prc));
	if (data->format->type == CHAR && !data->format->arg->str[0])
		size -= 1;
	data->format->arg->extra = ft_calloc(1, size + 1);
	if (!data->format->arg->extra)
		return (data);
	data->format->arg->extra = ft_memset(data->format->arg->extra, 32, size);
	if (data->format->zero == TRUE && (data->format->type == INT || \
	data->format->type == UNS))
		data->format->arg->extra = \
		ft_memset(data->format->arg->extra, 48, size);
	return (data);
}

t_data	*format_build(t_data *data)
{
	if (data->format->precision >= 0)
		data = precision_build(data);
	if (data->format->width)
		data = width_build(data);
	data->len += (int)(ft_strlen(data->format->arg->at_s) + \
	ft_strlen(data->format->arg->str) + ft_strlen(data->format->arg->extra) + \
	ft_strlen(data->format->arg->prc));
	if (data->format->zero == FALSE && data->format->neg == FALSE)
		ft_putstr_fd(data->format->arg->extra, 1);
	ft_putstr_fd(data->format->arg->at_s, 1);
	if (data->format->zero == TRUE)
		ft_putstr_fd(data->format->arg->extra, 1);
	ft_putstr_fd(data->format->arg->prc, 1);
	if (data->format->type == CHAR && !data->format->arg->str[0] && ++data->len)
		write(1, "\0", 1);
	else
		ft_putstr_fd(data->format->arg->str, 1);
	if (data->format->neg == TRUE)
		ft_putstr_fd(data->format->arg->extra, 1);
	return (data);
}

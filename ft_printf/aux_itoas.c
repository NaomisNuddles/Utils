/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_itoas.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:19:52 by nleandro          #+#    #+#             */
/*   Updated: 2024/12/10 13:54:28 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*uns_itoa_base(unsigned int val, char *base)
{
	char			*str;
	size_t			i;
	unsigned int	n;

	i = 0;
	n = val;
	while (ft_strlen(base) >= 2 && ft_strlen(base) <= 16 && n && ++i)
		n /= ft_strlen(base);
	if (val == 0)
		i = 1;
	str = ft_calloc(1, i + 1);
	while (str && i--)
	{
		str[i] = base[val % ft_strlen(base)];
		val /= ft_strlen(base);
	}
	return (str);
}

char	*unsl_itoa_base(unsigned long val, char *base)
{
	char				*str;
	size_t				i;
	unsigned long		n;

	i = 0;
	n = val;
	while (ft_strlen(base) >= 2 && ft_strlen(base) <= 16 && n && ++i)
		n /= ft_strlen(base);
	str = ft_calloc(1, i + 1);
	while (str && i--)
	{
		str[i] = base[val % ft_strlen(base)];
		val /= ft_strlen(base);
	}
	return (str);
}

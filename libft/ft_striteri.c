/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:23:01 by nleandro          #+#    #+#             */
/*   Updated: 2024/11/26 14:19:43 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *src, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	while (src && f && src[i] && ++i)
		f(i - 1, &src[i - 1]);
}

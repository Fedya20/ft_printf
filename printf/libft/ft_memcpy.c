/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpopadin <fpopadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:13:56 by fpopadin          #+#    #+#             */
/*   Updated: 2022/12/08 18:34:19 by fpopadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dest;
	char	*surc;
	size_t	i;

	dest = (char *)dst;
	surc = (char *)src;
	if (!(src || dst))
		return ((void *)(0));
	i = 0;
	while (i < n)
	{
		dest[i] = surc[i];
		i++;
	}
	return (dst);
}

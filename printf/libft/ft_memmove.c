/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpopadin <fpopadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:14:14 by fpopadin          #+#    #+#             */
/*   Updated: 2022/12/08 18:31:47 by fpopadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*surc;
	size_t			i;

	if (!(dst || src))
		return ((void *)(0));
	i = 0;
	dest = (unsigned char *)dst;
	surc = (unsigned char *)src;
	if (dest > surc)
	{
		while (len > 0)
		{
			dest[len -1] = surc[len -1];
			len--;
		}
	}
	else if (surc >= dest)
	{
		ft_memcpy(dest, surc, len);
	}
	return ((void *)(dst));
}
/*L'utilisation de la fonction « sizeof » permet de retourner 
 * la taille du réceptacle (en octets associé à un type. Si on 
 * multiplie ensuite par une 
 * valeur positive entière, nous avons une valeur entière qui 
 * correspond à un 
 * nombre d'octets. La fonction « malloc » demande alors au 
 * gestionnaire (fictif) 
 * de la mémoire centrale de lui réserver le nombre d'octets 
 * consécutifs demandés 
 * en mémoire.*/

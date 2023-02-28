/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpopadin <fpopadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:17:00 by fpopadin          #+#    #+#             */
/*   Updated: 2022/12/06 19:17:00 by fpopadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>

int	ft_strlen(char *nb)
{
	int	a;

	a = 0;
	while (nb[a] != '\0')
	{
		a++;
	}
	return (a);
}
/*int	main(void)
{
	char nb[] = "asdsfdsfsdf";

	printf("%d", ft_strlen(nb));
	return (0);
}*/

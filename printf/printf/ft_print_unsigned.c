/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpopadin <fpopadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:08:22 by fpopadin          #+#    #+#             */
/*   Updated: 2023/02/22 14:08:22 by fpopadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include "../libft/libft.h"
/*
Cette fonction sera utilise dans le ft_uitoa pour calculer la longuer
de notre chiffre
*/
int	ft_num_len(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

/*
Comme itoa ft_uitoa mais elle traite les valeurs d'entree que comme non signee
elle convertit une valeur entière en une chaîne terminée par un caractère nul 
en utilisant la base spécifiée et stocke le résultat dans le tableau pointé 
par le paramètre vstring. base peut prendre n'importe quelle valeur entre 
2 et 16 ; où 2 = binaire, 8 = octal, 10 = décimal et 16 = hexadécimal.

On va utiliser ft_uitoa dans la ft_print_unsigned
*/
char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_num_len(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

/*
On va utiliser ft_print_unsigned dans le ft_printf pour le format %u qui doit 
sortir un deciaml unsigned
*/
int	ft_print_unsigned(unsigned int n)
{
	int		print_length;
	char	*num;

	print_length = 0;
	if (n == 0)
		print_length += write(1, "0", 1);
	else
	{
		num = ft_uitoa(n);
		print_length += ft_printstr(num);
		free(num);
	}
	return (print_length);
}

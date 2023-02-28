/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpopadin <fpopadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:08:09 by fpopadin          #+#    #+#             */
/*   Updated: 2023/02/22 14:08:09 by fpopadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

/*Ce code est une implémentation de l'affichage d'une valeur de pointeur en 
 * hexadécimal. Il définit trois fonctions :

ft_ptr_len : cette fonction prend un nombre entier num de type uintptr_t et 
retourne sa longueur en termes de nombre de chiffres hexadécimaux.

ft_put_ptr : cette fonction prend un nombre entier num de type uintptr_t et 
l'affiche sur la sortie standard (file descriptor 1) en utilisant un algorithme 
de conversion récursive.

ft_print_ptr : cette fonction prend un nombre entier ptr de type unsigned 
long long et l'affiche sur la sortie standard en format hexadécimal précédé 
de "0x". Elle retourne la longueur totale des caractères affichés.

ces 3 fonctions sont utilises pour envoyer e resultat de %p qui doit envoyer 
l addresse*/
int	ft_ptr_len(uintptr_t num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_ptr(unsigned long num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}
/*L'ajout de :"a" dans le else est necessaire car la fonction convertit
 * une valeur numeriqueen une chaine hexadecimale representant catte valeur.
 * En hexadecimal, les chiffres de 10 a 15 sont representes par des lettres
 * de A a F. En utilisant a + (num - 10), le code garantit que les 
 * caracteres corrects seront affiches pour les nombres superieurs a 9.
 */

int	ft_print_ptr(unsigned long long ptr)
{
	int	print_length;

	print_length = 0;
	print_length += write(1, "0x", 2);
	if (ptr == 0)
		print_length += write(1, "0", 1);
	else
	{
		ft_put_ptr(ptr);
		print_length += ft_ptr_len(ptr);
	}
	return (print_length);
}

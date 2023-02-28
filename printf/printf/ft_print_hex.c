/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpopadin <fpopadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:07:16 by fpopadin          #+#    #+#             */
/*   Updated: 2023/02/22 14:07:16 by fpopadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Ce code en C implémente une fonction pour imprimer un nombre hexadécimal.

La fonction ft_hex_len calcule la longueur (nombre de chiffres) d'un nombre 
hexadécimal en divisant le nombre par 16 jusqu'à ce qu'il atteigne 0.

La fonction ft_put_hex imprime récursivement le nombre hexadécimal en divisant 
le nombre par 16 et en imprimant le dernier chiffre en utilisant ft_putchar_fd.
Si le dernier chiffre est compris entre 0 et 9, il est imprimé en utilisant 
l'opération '0' + nombre. Si le dernier chiffre est supérieur à 9, il est 
imprimé en utilisant l'opération 'a' ou 'A' + nombre - 10, en fonction de 
si format est 'x' ou 'X'.

Enfin, la fonction ft_print_hex utilise les fonctions précédentes pour imprimer 
le nombre hexadécimal. Si le nombre est 0, il est simplement imprimé avec write. 
Sinon, la fonction ft_put_hex est appelée pour imprimer le nombre hexadécimal. 
La longueur du nombre imprimé est retournée en utilisant la fonction ft_hex_len.
*/
#include "ft_printf.h"
#include "../libft/libft.h"

int	ft_hex_len(unsigned	int num)
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
/*
 * Dans le code en haut, ft_hex_len, la division par 16 sert à convertir 
 * un nombre entier non signé en hexadécimal. En hexadécimal, chaque position 
 * représente une puissance de 16. En divisant un nombre par 16, on détermine 
 * le nombre de positions nécessaires pour représenter ce nombre en hexadécimal. 
 * Le nombre de divisions nécessaires pour arriver à 0 détermine la longueur
 * (len) du nombre hexadécimal.
 */

void	ft_put_hex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, format);
		ft_put_hex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((num - 10 + 'a'), 1);
			if (format == 'X')
				ft_putchar_fd((num - 10 + 'A'), 1);
		}
	}
}
/*
La fonction d'en haut permet d'afficher un nombre entier non signé en 
hexadécimal sur la sortie standard (descripteur de fichier 1). La fonction 
utilise la récursion pour convertir le nombre en hexadécimal.

Lorsque le nombre donné est supérieur ou égal à 16, la fonction appelle 
elle-même deux fois avec les deux valeurs suivantes :

num / 16 : qui représente la partie entière de la division par 16
num % 16 : qui représente le reste de la division par 16
Lorsque le nombre est inférieur ou égal à 9, il est simplement affiché en 
utilisant la fonction ft_putchar_fd avec '0' comme base pour obtenir 
le caractère correspondant.

Si le nombre est supérieur à 9, le format ('x' ou 'X') détermine si le caractère 
doit être en minuscules ou en majuscules. Le caractère correspondant est obtenu 
en utilisant ft_putchar_fd et en ajoutant 10 à 'a' ou 'A' pour obtenir les 
caractères hexadécimaux correspondants.
*/

int	ft_print_hex(unsigned int num, const char format)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex(num, format);
	return (ft_hex_len(num));
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

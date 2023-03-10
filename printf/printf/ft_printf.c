/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpopadin <fpopadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:08:41 by fpopadin          #+#    #+#             */
/*   Updated: 2023/02/22 14:08:41 by fpopadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/libft.h"
#include "ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}
/*le ft_printchar va pour ecrire le caracter %c*/

/*
On utilise ft_printchar pour ecrire un seul charactere comme %c

On utilise ft_printstr pour ecrire une chaine de caractere %s

On utilise ft_print_ptr pour ecrire l addresse %p

On utilise ft_printnbr pour ecrire les chiffres. %d specifie un entier deciaml
signe tandis que %i specifie un entiers

On utilise ft_print_unsigned pour ecrire un decimal unsigned %u

On utilise ft_print_hex pour ecrire un integer hexadecimal (base 16)
*/
int	ft_formats(va_list args, const char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += ft_printchar(va_arg(args, int));
	else if (format == 's')
		print_length += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		print_length += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		print_length += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		print_length += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_length += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		print_length += ft_printpercent();
	return (print_length);
}

/*ft_printf est une fonction variadique ca veut dire que elle peut prendre 
a l'infini de valeurs differente parceque a la fin elle a (...).
 *
 * Une fonction variadique consiste de au moins d'une variable fixe et apres
d'un elipsis (...) comme dernier paramentre.
 *
 * --On doit mettre le header <stdarg.h> pour faire des fonctions variadique
 *
 * --On doit mettre un parametre fixe comme int n ou int args pour compter 
le nombre de variables qu'on veut faire passer.
 *
 *  --On doit mettre un elipsis (...) pour dire a la fonction qu'on accepte
une fonction variadique.
 *
 *  --On doit definir un macro va_list. Va_list est un type d'objet complet 
adapt?? pour contenir les informations n??cessaires aux macros va_start, 
va_copy, va_arg et va_end.
Si une instance va_list est cr????e, transmise ?? une autre fonction et utilis??e 
via va_arg dans cette fonction, toute utilisation ult??rieure dans la fonction 
appelante doit ??tre pr??c??d??e d'un appel ?? va_end.
Il est l??gal de passer un pointeur vers un objet va_list ?? une autre fonction, 
puis d'utiliser cet objet apr??s le retour de la fonction.
 *
 *  --On doit utiliser va_arg aussi.
 *
 *  --On doit utiliser va_start au debut et va_end a la fin.*/
int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		print_length;

	i = 0;
	print_length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_length += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			print_length += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (print_length);
}

/*
 En C, la ligne "print_length  += ft_formats(argc, str[i + 1]);" signifie
 que la valeur de la fonction ft_formats est additionnee a la valeur actuelle 
 de la fonction print_length,et que le resultat est stocke a nouveau dans 
 la fonction print_length.

 L'expression "ft_formats(args, str[i + 1]" appelle la fonction ft_formats 
 avec les argumentsargs et str[i + 1] et retourne sa valeur de retour

 l'operateur += est un operateur d affectation qui ajoute la valeur de sa 
 droite a celle desa gauche et stocke le resultat a gauche.

 Ce code est une impl??mentation personnalis??e de la fonction "printf" en C.
 La fonction "ft_printf" prend en argument une cha??ne de format et une liste 
 variable d'arguments. Elle parcourt la cha??ne de format et, lorsqu'elle 
 rencontre un signe de pourcentage "%", elle d??termine le type de format ?? 
 imprimer en utilisant le caract??re suivant, puis appelle une fonction 
 sp??cifique pour imprimer ce type de format. Les types de format support??s 
 sont: 'c' pour imprimer un caract??re, 's' pour imprimer une cha??ne 
 de caract??res, 'p' pour imprimer un pointeur, 'd' ou 'i' pour imprimer 
 un nombre entier, 'u' pour imprimer un nombre entier non sign??, 'x' ou 
 'X' pour imprimer un nombre hexad??cimal. Les fonctions appel??es sont 
 "ft_printchar", "ft_printstr", "ft_print_ptr", "ft_printnbr", 
 "ft_print_unsigned", "ft_print_hex" et "ft_printpercent". La fonction 
 "ft_printf" utilise la fonction "write" pour imprimer les caract??res 
 sur la sortie standard. Elle retourne la longueur totale de la cha??ne imprim??e.
 */

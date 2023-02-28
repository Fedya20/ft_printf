/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpopadin <fpopadin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:08:31 by fpopadin          #+#    #+#             */
/*   Updated: 2023/02/22 14:08:31 by fpopadin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"
#include <stdlib.h>

/*
Ce code est une implémentation de fonctions de formatage de chaînes de 
caractères et d'affichage dans la console en utilisant la fonction write 
de stdlib.h. Il comporte les fonctions suivantes :

ft_putstr: affiche une chaîne de caractères sur la console.
ft_printstr: affiche une chaîne de caractères sur la console et renvoie la 
longueur de la chaîne.
ft_printnbr: affiche un nombre entier sur la console en le convertissant en 
chaîne de caractères avec la fonction ft_itoa de libft.h et renvoie la 
longueur de la chaîne.ft_printpercent: affiche le caractère '%' sur 
la console et renvoie 1.Le code inclut les en-têtes ft_printf.h et libft.h,
qui définissent peut-être des types et des fonctions supplémentaires 
utilisées dans le code.
*/
void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

/*
On utilise ft_printstr pour ecrire l addresse %s
Le but de cette fonction est de renvoyer la longueur de la chaîne affichée 
sur la console, afin que l'appelant puisse savoir combien de caractères ont 
été écrits. En cas où la chaîne passée en argument est NULL, la fonction 
affiche la chaîne "(null)" et renvoie sa longueur, qui est 6.
*/
int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

/*cette fonction sert a ecrire %i, %d*/
int	ft_printnbr(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len = ft_printstr(num);
	free(num);
	return (len);
}

/*la fonction d en dessus sert a ecrire un % soit %%*/
int	ft_printpercent(void)
{
	write(1, "%", 1);
	return (1);
}

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#define BUFFER_SIZE 1000

char	*get_next_line(int fd)
{
	static  t_list	*stash;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read (fd, &line, 0) < 0) /*la verification de rea sert a voir si fd est un bon descripteur de fichier*/
		return (NULL);
	line = NULL;
	stash = NULL;
	read_and_stash(fd, &stash);/*ici on prend &stash parceque on veut modifier la lise chainee si on aurai mis que stash on aurait pas pue modifier la liste chainee*/
	if(stash == NULL)
		return (NULL);
	extract_stash(stash, &line);/*ici on veut pas modifier la liste chainee de stash on veut juste l'utiliser donc on prend pas &stash mais que stash*/
	if(line == NULL)
		return (NULL);
	clean_stash(&stash);
	if (stash != NULL)
		return (NULL);
	if (line[0] == '\0')
	{
		free_stash(stash);/*apres avoir fait ca la stash sera pas egale a NULL parceque free_stash modifie pas le pointeur en lui meme mais ces noeuds de la liste chainee*/
		stash = NULL;/*apres avoit fait free_stash le pointeur pointera toujours vers l'emplacement  memoire ou se trouvait le remier noeud de la liste chainee*/
		free(line);
		line = NULL;/*== est l operateur de comparaison et = est l opperateur d affection*/
		return (NULL);
	}
	return (line);
}
read_and_stash(int fd, t_list **&stash)/*ici on prend l adresse du pointeur stash "&stash" donc c est un pointeur d un pointeur donc **stash*/
{
	char	*buf;
	int		readed;

	readed = 1;/*on doit mettre que readed = 1 comme ca la boucle principale se fera au moin une fois et aussi comme ca on peut mettre '\0' a la fin sans perdre un caracterte*/
	while (!found_newline(*stash) && readed != 0)/*la boucle continuera tant que found_newline renvoie 0 et si elle envoie 1 elle s arrete*/
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));/*on malloc la taille d un char 1 octet multiplie par le BUFFER_SIZE pour avoir la place d un texte de la taille de SIZE*/
		if	(buf == NULL)/*on verifie si malloc a marcher*/
			return;
		readed = (int)read(fd, buf, BUFFER_SIZE)/*normalelment read renvoie un size_t mais la on le change manuellement en int qui est readed*/
		if ((*stash == NULL && readed == 0) || readed == -1)/*&& = les deux conditions doivent etre faux pour arreter la boucle, || elle peut arreter la boucle toute seule*/
		{
			free (buf);
			return;
		}
		buf[readed] = '\0';/*on rejoute le caractere de fin et on a une place pour lui parceque readed etait egale a 1 et pas 0*/
		add_to_stash(stash, buf, readed);/*on va rajouter tout ce qu on a dans notre buf a stash*/
		free (buf);/*on libere notre buf parce que son contenu a ete ajouter a stash et on a plus besoin de se contenu*/
	}
}

void	add_to_stash(t_list	**stash, char *buf, int readed)
{
	int				i;
	t_list 	*new_node;
	t_list		*last;

	i = 0;
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return;
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char) * (readed + 1));/*le +1 a readed sert a donner de la place pour le caractere '\0'*/
	if (new_node->content == NULL)/*on verifie si malloc a marcher*/
		return;
	while (buf[i] && i < readed)/*on va copier les texte qui est dans le buf dans le new_node->content*/
	{
		new_node->content[i] = buf[i];
		i++;
	}
	new_node->content[i] = '\0';/*on ajoute le caractere de la fin au quelle on a donner de l espace dans le malloc avec readed+1*/
	if (*stash == NULL)
	{
		*stash = new_node;
		return;
	}
	last = ft_lst_get_last(*stash);/*ces deux lignes de code ne vont pas etre utilise dans ce code normal parceque stash sera toujours NULL parceque il va etre nettoyer*/
	last->next = new_node;
}

void	extract_line(t_list **stash, char **line)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	if (stash == NULL)
		return;
	generate_line(line, stash);
	if (*line == NULL)
		return;
	while (stash)/*parcours tous les noeuds de la liste chainees*/
	{
		while (stash->content[i])/*parcourt tous les caracteres dans ce noeud*/
		{
			if (stash->content == '\n')/*si dans ce noeud il y a le signe de la fin de ligne on arrete cette fonction*/
			{
				(*line)[j++] = stash->content[i++];/*on copie le caractere de la fin de la fin de la ligne \n*/
				break;
			}
			(*line)[j++] = stash->content[i++];/*copie le contenu de stash tant que on ne trouve pas le caractere de fin '\0'*/
		}
		stash = stash->next;
	}
	(*line)[j] = '\0';/*on ajoute le caractere de fin de chaine nul a la fin de la chaine de caractere*/
}

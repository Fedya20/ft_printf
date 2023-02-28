# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fpopadin <fpopadin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 14:09:21 by fpopadin          #+#    #+#              #
#    Updated: 2023/02/22 14:09:21 by fpopadin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

NAME		= libftprintf.a
LIBFT		= libft
INCLUDE		= -I. -Ilibft/
SRC_DIR		= printf/
OBJ_DIR		= obj/
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
VPATH		= %.h libft
VPATH		= printf
#Le -I dans cette ligne de commande est utilisé pour spécifier un répertoire d'inclusion 
#pour les fichiers d'en-tête (header files) utilisés dans le programme compilé.

#-Wall : active tous les avertissements du compilateur.
#-Werror : traite tous les avertissements comme des erreurs.
#-Wextra : active des avertissements supplémentaires qui ne sont pas activés par -Wall.
#-I : spécifie un répertoire d'inclusion pour les fichiers d'en-tête.
#L'option -I est suivie du chemin du répertoire contenant les fichiers d'en-tête. Lorsque le 
#compilateur rencontre une instruction #include dans le code source, il recherche les fichiers 
#d'en-tête dans les répertoires spécifiés par les options -I ou par les variables d'environnement 
#telles que C_INCLUDE_PATH et CPLUS_INCLUDE_PATH.

#Par exemple, si vous utilisez -I/path/to/header/files, le compilateur cherchera les fichiers 
#d'en-tête dans /path/to/header/files en plus des répertoires d'en-tête standard. Cela peut 
#être utile si vous avez des fichiers d'en-tête personnalisés qui ne se trouvent pas dans les 
#répertoires standard.
RM			= rm -f
AR			= ar rcs

# Colors

#Ces lignes définissent des variables de couleurs ANSI utilisées pour afficher des messages 
#colorés dans la console lors de l'exécution de certaines règles du Makefile.

#Les codes de couleurs ANSI sont des séquences d'échappement de caractères spéciaux qui sont 
#interprétées par la console pour afficher du texte coloré. Les codes d'échappement ANSI commencent 
#par le caractère d'échappement \033 suivi d'un ou plusieurs paramètres qui définissent la couleur 
#ou le style de texte.

#Dans ce cas, les variables sont nommées en fonction de leur couleur, et chaque variable contient 
#une séquence d'échappement ANSI pour définir la couleur correspondante. Par exemple, la variable 
#YELLOW contient la séquence d'échappement \033[0;93m qui affichera le texte en jaune.

#La variable DEF_COLOR est définie pour réinitialiser la couleur du texte à la couleur par défaut, 
#ce qui est utile pour s'assurer que le texte suivant ne sera pas affiché dans une couleur inattendue.

#Ces variables peuvent ensuite être utilisées dans les règles du Makefile pour afficher des messages colorés
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#Sources

SRC_FILES	=	ft_printf ft_printf_utils ft_print_ptr ft_print_unsigned ft_print_hex

# addprefix est utilise ici pour donner le chemin de nos fichier .c et .o pour que l ordinateur sait
# ou aller les chercher.
#
# addsufix sert a mettre quelque chose a la fin du nom de nos fichier ici on ajoute .c et .o sur nos
# fichiers qui se nomme SRC_FILES.
SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

# le cache est l espace memoire rapide qui est utilise a l instant par exemple dans yt ca sera 
# les photo des videos

OBJF		=	.cache_exists

all:		$(NAME)

# le @ au debut des commandes indique de ne de ne pas afficher la commande elle-meme lorsqu'elle
# est execute
# 
# La commande "make -C" est utilisée pour spécifier le répertoire dans lequel la commande 
# "make" doit être exécutée. Elle est souvent utilisée dans un Makefile pour appeler une 
# autre Makefile située dans un répertoire différent
$(NAME):	$(OBJ)
			@make -C $(LIBFT)
			@cp libft/libft.a .
			@mv libft.a $(NAME)
			@$(AR) $(NAME)  $(OBJ)
			@echo "$(GREEN)ft_printf compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			@mkdir -p $(@D)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) -c $(INCLUDE) -o $@ $<

$(OBJF):
			@mkdir -p $(OBJ_DIR)

clean:
			@$(RM) -rf $(OBJ_DIR)
			@make clean -C $(LIBFT)
			@echo "$(BLUE)ft_printf object files cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) -f $(NAME)
			@$(RM) -f $(LIBFT)/libft.a
			@echo "$(CYAN)ft_printf executable files cleaned!$(DEF_COLOR)"
			@echo "$(CYAN)libft executable files cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(GREEN)Cleaned and rebuilt everything for ft_printf!$(DEF_COLOR)"

norm:
			@norminette $(SRC) $(INCLUDE) $(LIBFT) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re norm

# la directive .PHONY dans un Makefile permet de définir des cibles factices qui ne correspondent 
# pas à des fichiers réels, mais plutôt à des actions à exécuter
#
#  le terme "factice" est utilisé pour décrire quelque chose qui est simulé ou artificiel, 
#  et qui n'a pas de fonctionnalité réelle ou concrète. Dans un Makefile, une cible factice 
#  est une cible qui ne correspond pas à un fichier réel, mais plutôt à une action à exécuter.

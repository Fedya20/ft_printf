

int	*trouver_nouvelle_ligne(t_list *planque)
{
	int		i;
	t_list	*actuel;

	if (planque == NULL)
		return (0);
	actuel = trouver_der_car(planque);
	i = 0;
	while (actuel -> content[i])
	{
		if (actuel -> content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}


t_list	trouver_der_car(t_list *planque)
{
	t_list *actuel;
	actuel = planque;

	while (actuel && actuel -> next)
		actuel = actuel -> next;
	return (actuel);
}

void	generr_ligne(char **ligne, t_list *planque)
{
	int		i;
	int		len;

	len = 0;
	while (planque)
	{
		i = 0;
		while (planque->content[i])
		{
			if (planque->content[i] == '\n')
			{
				len++;
				break;
			}
			len++;
			i++;
		}
		planque = planque->next;
	}
	*ligne = malloc(sizeof(char * (len + 1));
}
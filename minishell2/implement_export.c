/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implement_export.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stemsama <stemsama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 00:17:23 by stemsama          #+#    #+#             */
/*   Updated: 2023/07/07 18:29:19 by stemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	affiche_export(t_env **env)
{
	t_env	*cur;

	cur = *env;
	while (cur)
	{
		printf("declare -x %s", get_name(cur->n_v));
		if (cur->value)
			printf("=\"%s\"", get_value1(cur->n_v) + 1);
		else if (ft_strchr(cur->n_v, '='))
			printf("=\"\"");
		printf("\n");
		cur = cur->next;
	}
}

int	*execute_export(t_env **exp, t_env **env, char **argv)
{
	t_env	*cur;
	int		i;

	cur = *exp;
	if (argv[1] == NULL)
	{
		while (cur)
		{
			printf("declare -x %s", get_name(cur->n_v));
			if (cur->value)
				printf("=\"%s\"\n", get_value1(cur->n_v) + 1);
			else
				printf("\n");
			cur = cur->next;
		}
	}
	i = 0;
	while (argv[++i])
	{
		if (pars_export(argv[i]) == 1)
			printf("minishell: export: `%s': not a valid identifier\n", argv[i]);
		else
			go_to_export(exp, env, argv[i]);
	}
	return (0);
}

void	go_to_export(t_env **exp, t_env **env, char *argv)
{
	(void) env;
	t_env	*tmp;
	
	tmp = *exp;

	if (!check_existe(exp, argv))
		ft_lstadd_back2(exp, ft_lstnew_ind2(argv));
	else if (ft_strchr(argv, '=') != 0 && ft_strncmp((ft_strchr(argv, '=') + 1), "+", 1) == 0)//ff=+po
	{
		printf("1 ---> :\n");
		while (tmp != NULL)
		{
			if (!ft_strcmp(get_name(argv), tmp->name))
			{
				tmp = (t_env *)malloc(sizeof(t_env));
				tmp->value = ft_strjoin(tmp->value, get_value1(argv) + 2);
				(*exp)->value = ft_strjoin(tmp->value, get_value1(argv) + 2);
				printf("%s 1.1:\n", tmp->value);
				exp = &tmp;
				return ;
			}
			*exp = (*exp)->next;
		}	
	}
	else if (ft_strchr(argv, '=') != 0)// ff=kk
	{
		printf("2 ---> :\n");
		while (tmp != NULL)
		{
			if (!ft_strcmp(get_name(argv), tmp->name))
			{
				tmp = (t_env *)malloc(sizeof(t_env));
				tmp->value = get_value1(argv) + 1;
				(*exp)->value = get_value1(argv) + 1;
				printf("%s 2.1:\n", tmp->value);
				printf("%s 2.1:\n", (*exp)->value);
				exp = &tmp;
				return ;
			}
			*exp = (*exp)->next;
		}
	}
	exp = &tmp;
	// return (exp);
}

// ss ; ss=+d --> ss="+d"
int check_existe(t_env **env, char *new)
{
	t_env	*tmp;

	tmp = *env;
	while (tmp != NULL)
	{
		if (!ft_strcmp(get_name(new), tmp->name))
			return (1);
		tmp = tmp->next;
	}
	return 0;
}

int	pars_export(char *av)
{
	int	a[2];
	int	i;

	i = 0;
	a[0] = 0;
	a[1] = 0;
	if ((av[0] > 64 && av[0] < 91)
		|| (av[0] > 96 && av[0] <= 122) || av[0] == '_')
		a[0] = 1;
	while (av[i] && av[i] != '=')
	{
		//il ya d'autre condition
		if ((av[i] >= '0' && av[i] <= '9' && i == 0)
			|| ((av[i] >= 'z' && av[i] <= 'a') && (av[i] != '+' && av[i] != '_'))
			|| ((av[i] >= 'Z' && av[i] <= 'A') && (av[i] != '+' && av[i] != '_'))
			|| (av[i] == '+' && av[i + 1] != '='))
		{
			a[1] = 1;
			break ;
		}
		i++;
	}
	if (a[0] == 0 || a[1] == 1)
		return (1);
	return (0);
}

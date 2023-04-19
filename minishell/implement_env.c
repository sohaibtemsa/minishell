/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implement_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stemsama <stemsama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 23:13:51 by stemsama          #+#    #+#             */
/*   Updated: 2023/04/19 00:20:28 by stemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*execute_env(t_env **env)
{
	t_env	*tmp;

	tmp = *env;
    while (tmp)
	{
		printf("name %s\n", tmp->name);
		printf("value %s\n", tmp->value);
		printf("||||||||||||||||||||||>\n");
		tmp = tmp->next;
	}
	return (*env);
}

t_env	*creat_env(char **env)
{
	int 	i;
	t_env	*lst;

	i = -1;
	lst = NULL;
    while (env[++i])
		ft_lstadd_back2(&lst, ft_lstnew_ind2(env[i], 1));
	return (lst);
}

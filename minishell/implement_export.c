/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implement_export.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stemsama <stemsama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 00:17:23 by stemsama          #+#    #+#             */
/*   Updated: 2023/04/19 00:24:37 by stemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*execute_export(t_env **env)
{
	t_env *cur;

	cur = *env;
	while (cur)
	{
		printf("declare -x %s = ", cur->name);
		if (cur->value)
		{
			printf("%s", cur->value);
			
		}
		
	}
}

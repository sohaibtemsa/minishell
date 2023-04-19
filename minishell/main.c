/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stemsama <stemsama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:35:42 by stemsama          #+#    #+#             */
/*   Updated: 2023/04/19 00:15:57 by stemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **env) 
{
	t_env *lst_env;

	lst_env = creat_env(env);
	// execute_env(&lst_env);
	// execute_pwd(&lst_env);
	// execute_cd(&lst_env, argv);
	// execute_pwd(&lst_env);
	// execute_echo(++argv);
	// execute_exit(++argv);
	return 0;
}
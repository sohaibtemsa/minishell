/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stemsama <stemsama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:35:42 by stemsama          #+#    #+#             */
/*   Updated: 2023/05/06 19:09:36 by stemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_env	*lst_env;
	char	*line;
	char	**cmd;

	(void) argv;
	(void) argc;
	lst_env = creat_env(env);
	lst_env = sort_env(&lst_env);
	sig_nals();
	while (1)
	{
		line = readline("minishell$");
		cmd = ft_split(line, ' ');
		parsing(cmd);
		add_history(line);
		if (is_builting(cmd))
			go_to_builting(cmd, lst_env);
		else
			go_to_execve(&lst_env, cmd, env);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stemsama <stemsama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 23:35:48 by stemsama          #+#    #+#             */
/*   Updated: 2023/07/07 14:22:39 by stemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builting(char **cmd)
{
	if (cmd && cmd[0])
	{
		if (ft_strcmp(cmd[0], "echo") == 0 || ft_strcmp(cmd[0], "cd") == 0
			|| ft_strcmp(cmd[0], "pwd") == 0 || ft_strcmp(cmd[0], "export") == 0
			|| ft_strcmp(cmd[0], "unset") == 0 || ft_strcmp(cmd[0], "env") == 0
			|| ft_strcmp(cmd[0], "exit") == 0)
			return (1);
	}
	return (0);
}

void	go_to_builting(char **cmd, t_env *lst_env, t_env *lst_exp)
{
	write(1, "--> Builtings\n", 14);
	if (ft_strcmp(cmd[0], "echo") == 0)
		execute_echo(++cmd);
	else if (ft_strcmp(cmd[0], "cd") == 0)
		execute_cd(&lst_env, cmd);
	else if (ft_strcmp(cmd[0], "pwd") == 0)
		execute_pwd(&lst_env);
	else if (ft_strcmp(cmd[0], "export") == 0)
		execute_export(&lst_exp, &lst_env, cmd);
	else if (ft_strcmp(cmd[0], "unset") == 0)
		execute_unset(++cmd);
	else if (ft_strcmp(cmd[0], "env") == 0)
		execute_env(&lst_env);
	else if (ft_strcmp(cmd[0], "exit") == 0)
		execute_exit(++cmd);
}

void	go_to_execve(t_env **lst_env, char **cmd, char **env)
{
	char	*path;
	char	**all_path;
	int		i;
	int		pid;

	pid = fork();
	if (pid == 0)
	{
		i = 0;
		path = get_value(lst_env, "PATH");
		all_path = ft_split(path, ':');
		while (all_path[i])
		{
			all_path[i] = ft_strjoin(all_path[i], "/");
			all_path[i] = ft_strjoin(all_path[i], cmd[0]);
			if (access(all_path[i], F_OK) == 0)
				execve(all_path[i], cmd, env);
			i++;
		}
		printf("Command not found\n");
	}
	wait(0);
}

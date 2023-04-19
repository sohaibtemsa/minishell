/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stemsama <stemsama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:35:44 by stemsama          #+#    #+#             */
/*   Updated: 2023/04/19 00:18:38 by stemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#define ERROR 1

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include "libft/libft.h"

typedef struct env
{
	char		*name;
	char		*value;
	struct env	*next;
	
}	t_env;

//-----------------------------------------------> implement_cd:
int		execute_cd(t_env **env, char **argv);
char	*get_path(t_env **env, char **argv);
char	*get_value(t_env **env, char *name);
void	go_to_home(t_env **env, char **argv);
int		upd_oldpwd(t_env **env, char *pwd);

//-----------------------------------------------> implement_env:
t_env	*execute_env(t_env **env);
t_env	*creat_env(char **env);

//-----------------------------------------------> implement_pwd:
void	execute_pwd(t_env **env);

//-----------------------------------------------> implement_echo:
int		execute_echo(char **argv);
void	pars_echo(char **argv, int *is_n, int *i);

//-----------------------------------------------> implement_exit:
int		execute_exit(char **argv);
int		ft_isnumber(char *str);

//-----------------------------------------------> tools1:
void	ft_lstadd_back2(t_env **lst, t_env *new);
t_env	*ft_lstnew_ind2(char *content, int index);
char	*get_name(char *str);
char	*get_value1(char *str);

//-----------------------------------------------> main:

#endif
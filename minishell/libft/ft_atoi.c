/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stemsama <stemsama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 10:01:01 by stemsama          #+#    #+#             */
/*   Updated: 2023/01/29 23:17:09 by stemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_atoi(char *str)
{
	int			res;
	long long	cas;
	int			sin;

	res = 0;
	sin = 1;
	if (ft_strcmp(str, "-2147483648") == 0)
		return (-2147483648);
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sin = -1;
		str++;
	}
	while (*str && *str <= '9' && *str >= '0')
	{
		cas = res;
		res = res * 10 + *str++ - 48;
		if (cas != res / 10)
			ft_atoi_trois();
	}
	return (res * sin);
}

void	ft_atoi_trois(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

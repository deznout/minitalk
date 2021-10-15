/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrent <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 00:57:35 by hbrent            #+#    #+#             */
/*   Updated: 2021/10/15 00:57:43 by hbrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sgn;

	i = 0;
	sgn = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sgn = -sgn;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * sgn);
}

static void	convert_str(char *str, int pid)
{
	int	t;

	while (*str)
	{
		t = 128;
		while (t > 0)
		{
			if (t & *str)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			t /= 2;
			usleep(60);
		}
		str++;
	}
}

int	main(int ac, char **ag)
{
	if (ac == 3)
	{
		convert_str(ag[2], ft_atoi(ag[1]));
		convert_str("\nMessage is received!\n", ft_atoi(ag[1]));
	}
	return (0);
}

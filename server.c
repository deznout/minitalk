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

void	ft_putnbr_fd(int n, int fd)
{
	long	num;
	char	str[12];
	int		i;

	num = n;
	i = 0;
	if (num == 0)
		write(fd, "0", 1);
	if (num < 0)
	{
		write(fd, "-", 1);
		num = -num;
	}
	while (num > 0)
	{
		*(str + i) = num % 10 + 48;
		num = num / 10;
		i++;
	}
	i--;
	while (i >= 0)
		write(fd, &(str[i--]), 1);
}

static void	print_sig(int signal)
{
	static char	symb = 0;
	static int	count = 128;

	if (SIGUSR1 == signal)
		symb += count;
	count /= 2;
	if (count == 0)
	{
		write(1, &symb, 1);
		count = 128;
		symb = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	write(1, "The process ID is ", 18);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_handler = print_sig;
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhorefto <lhorefto@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:37:12 by lhorefto          #+#    #+#             */
/*   Updated: 2021/06/17 13:06:29 by lhorefto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	g_signal;

static void	ft_init_server(t_server *data)
{
	if (signal(SIGUSR1, ft_signal_catcher) == SIG_ERR
		|| signal(SIGUSR2, ft_signal_catcher) == SIG_ERR)
		exit(EXIT_FAILURE);
	g_signal = 0;
	data->i = 0;
	ft_putnbr(getpid());
}

static void	ft_print(t_server *data, int *tmp)
{
	char	c;

	c = ft_getchar(data);
	if (c != EOT)
		ft_putchar(c);
	else
	{
		*tmp = 1;
		g_signal = 0;
	}
}

int	main(void)
{
	t_server	data;
	int			tmp;

	ft_init_server(&data);
	while (1)
	{
		tmp = ft_wait_for_signal();
		data.bin[data.i] = ft_getbit(&tmp, &data.i);
		if (data.i == 8)
			ft_print(&data, &tmp);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhorefto <lhorefto@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:18:48 by lhorefto          #+#    #+#             */
/*   Updated: 2021/06/09 10:54:04 by lhorefto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ft_signal_catcher(int signal)
{
	g_signal = signal;
}

char	ft_wait_for_signal(void)
{
	int	sig;

	if (g_signal != SIGUSR2 && g_signal != SIGUSR1)
		pause();
	sig = g_signal;
	g_signal = 0;
	return (sig);
}

char	ft_getchar(t_server *data)
{
	char	c;
	int		bit;

	data->i = 0;
	bit = 0;
	c = 0;
	while (bit < 8)
	{
		c *= 2;
		if (data->bin[bit])
			c++;
		bit++;
	}
	return (c);
}

char	ft_getbit(int *tmp, int *i)
{
	int	res;

	if (*tmp == SIGUSR1)
		res = 0;
	else
		res = 1;
	*i += 1;
	*tmp = 0;
	return (res);
}

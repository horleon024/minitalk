/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhorefto <lhorefto@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 18:49:21 by lhorefto          #+#    #+#             */
/*   Updated: 2021/06/17 13:34:14 by lhorefto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	ft_send_char(char c, pid_t pid_server)
{
	char	signal;
	int		bit;

	bit = 7;
	while (bit >= 0)
	{
		if (((c >> bit) & 1) == 0)
			signal = SIGUSR1;
		else
			signal = SIGUSR2;
		if (kill(pid_server, signal) == -1)
			exit (EXIT_FAILURE);
		usleep(1000);
		bit--;
	}
}

static int	ft_atoi(const char *str)
{
	int	i;
	int	val;
	int	multiply;

	i = 0;
	val = 0;
	multiply = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		multiply = -1;
	if (str[i] == '+' || multiply == -1)
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		val = val * 10 + (str[i] - '0');
		i++;
	}
	return (val * multiply);
}

static bool	ft_checkstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == EOT)
			return (false);
		i++;
	}
	return (true);
}

static void	ft_checkargs(int argc, char **argv)
{
	if (argc != 3)
		exit(EXIT_FAILURE);
	if (!ft_str_isnum(argv[1]))
		exit(EXIT_FAILURE);
	if (ft_atoi(argv[1]) == 0)
		exit(EXIT_FAILURE);
	if (!ft_checkstr(argv[2]))
		exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	pid_t	pid_server;
	size_t	i;
	
	ft_checkargs(argc, argv);
	pid_server = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		ft_send_char(argv[2][i], pid_server);
		//usleep(1000);
		i++;
	}
	ft_send_char(EOT, pid_server);
	usleep(100);
	return (EXIT_SUCCESS);
}

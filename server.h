#ifndef SERVER_H
# define SERVER_H

# include <sys/types.h>
# include <signal.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>

# define EOT 4
# define PIDBITS 16

extern char	g_signal;

typedef struct s_server
{
	char	bin[7];
	int		i;
}			t_server;

char	ft_getbit(int *tmp, int *i);
char	ft_getchar(t_server *data);
char	ft_wait_for_signal(void);
void	ft_signal_catcher(int signal);
void	ft_putnbr(int nb);
void	ft_putchar(char c);

#endif

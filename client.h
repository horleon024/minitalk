/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhorefto <lhorefto@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 18:42:43 by lhorefto          #+#    #+#             */
/*   Updated: 2021/06/17 13:35:06 by lhorefto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <sys/types.h>
# include <limits.h>
# include <signal.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# define EOT 4
# define PIDBITS 16

int		ft_str_isnum(char *str);

#endif

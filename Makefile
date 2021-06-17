# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhorefto <lhorefto@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/13 13:48:05 by lhorefto          #+#    #+#              #
#    Updated: 2021/06/17 13:34:28 by lhorefto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					= server
NAME_CLIENT				= client
NAME_BONUS				= server_bonus
NAME_CLIENT_BONUS		= client_bonus

SRCS_SERVER				= server.c server_utils.c utils.c

OBJS_SERVER				= $(SRCS_SERVER:.c=.o)

SRCS_SERVER_BONUS		= server_bonus.c server_utils_bonus.c utils_bonus.c

OBJS_SERVER_BONUS		= $(SRCS_SERVER_BONUS:.c=.o)

SRCS_CLIENT				= client.c utils.c

OBJS_CLIENT				= $(SRCS_CLIENT:.c=.o)

SRCS_CLIENT_BONUS		= client_utils_bonus.c client_bonus.c utils_bonus.c

OBJS_CLIENT_BONUS		= $(SRCS_CLIENT_BONUS:.c=.o)


CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

$(NAME):	$(OBJS_SERVER)
				$(CC) -o $(NAME) $(OBJS_SERVER)
				
$(NAME_CLIENT):	$(OBJS_CLIENT)
				$(CC) -o $(NAME_CLIENT) $(OBJS_CLIENT)

$(NAME_BONUS):	$(OBJS_SERVER_BONUS)
				$(CC) -o $(NAME_BONUS) $(OBJS_SERVER_BONUS)
				
$(NAME_CLIENT_BONUS):	$(OBJS_CLIENT_BONUS)
				$(CC) -o $(NAME_CLIENT_BONUS) $(OBJS_CLIENT_BONUS)

all:			$(NAME) $(NAME_CLIENT)

clean:
				$(RM) $(OBJS_CLIENT) $(OBJS_SERVER) $(OBJS_CLIENT_BONUS) $(OBJS_SERVER_BONUS)

fclean:			clean
				$(RM) $(NAME) $(NAME_CLIENT) $(NAME_BONUS) $(NAME_CLIENT_BONUS)

re:				fclean all

bonus:			$(NAME_BONUS) $(NAME_CLIENT_BONUS)

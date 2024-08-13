# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvalimak <tvalimak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/10 19:16:14 by tvalimak          #+#    #+#              #
#    Updated: 2024/08/13 18:01:03 by tvalimak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= miniRT
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
SRCDIR		= srcs
OBJDIR		= object_files

MAKE 	 	= make
LIBFTDIR 	= libft
GNLDIR	 	= $(LIBFTDIR)/GNL
LIBFT 		= $(LIBFTDIR)/libft.a
GNL 		= $(LIBFTDIR)/GNL/gnl.a

SRCS = 	parse.c \
		validate_ambient.c \
		parsing_utils.c 

OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(GNL)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(GNL)

$(LIBFT):
	@$(MAKE) -C $(LIBFTDIR)

$(GNL):
	@$(MAKE) -C $(GNLDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	make fclean -C $(LIBFTDIR)
	rm -rf $(OBJDIR)

# @rm -rf $(OBJDIR) $(NAME)
# @$(MAKE) clean -C $(LIBFTDIR) $(GNLDIR)

fclean: clean
	rm -rf $(NAME)
#	@rm -f $(NAME)
#	@$(MAKE) fclean -C $(LIBFTDIR) $(GNLDIR)

re: fclean all

.PHONY: all clean fclean re
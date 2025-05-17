# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: root <root@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/14 21:01:27 by root              #+#    #+#              #
#    Updated: 2025/05/17 11:25:52 by root             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = philo

LIBFT = ../libft
CFLAGS = -Wextra -Wall -Werror 
HEADERS := -I ./include -I $(LIBFT)/include
LIBS = -L$(LIBFT) -lft
SRCS := $(shell find . -maxdepth 1 -iname "*.c")
OBJS := $(SRCS:.c=.o)

GREEN  := \033[1;32m
YELLOW := \033[1;33m
BLUE   := \033[1;34m
RED    := \033[1;31m
RESET  := \033[0m

all: banner loading libft $(NAME) fun_msg

banner:
	@echo "$(BLUE)"
	@echo "██████╗ ██╗  ██╗██╗██╗      ██████╗ "
	@echo "██╔══██╗██║  ██║██║██║     ██╔═══██╗"
	@echo "██████╔╝███████║██║██║     ██║   ██║"
	@echo "██╔═══╝ ██╔══██║██║██║     ██║   ██║"
	@echo "██║     ██║  ██║██║███████╗╚██████╔╝"
	@echo "╚═╝     ╚═╝  ╚═╝╚═╝╚══════╝ ╚═════╝ "
	@echo "$(RESET)"


libft:
	@echo "$(YELLOW)🔧 Building libft...$(RESET)"
	@make -C $(LIBFT)
loading:
	@echo -n "Building"; for i in {1..3}; do sleep 0.3; echo -n "."; done; echo " 🚀"

fun_msg:
	@echo "$(GREEN)$(shell shuf -n 1 -e 'The table is set! 🚀' 'Time to philosophize! 🎮' 'Philosophers is ready! ✅')$(RESET)"

$(NAME): $(OBJS)
	@echo "$(GREEN)🔗 Linking $(NAME)...$(RESET)"
	cc $(OBJS) -o $(NAME) $(LIBS)


clean:
	@echo "$(YELLOW)🧹 Cleaning object files...$(RESET)"
	@rm -rf $(OBJS)
fclean: clean
	@echo "$(RED)🔥 Full clean in progress...$(RESET)"
	@rm -rf $(NAME)	
re: fclean all

.PHONY: all bonus clean fclean re libft
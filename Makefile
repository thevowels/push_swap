NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I includes

SRC_FILES = errors.c ft_printf.c inits.c \
			stack_aux.c stack_commands.c stack_primitives.c \
			test_helper.c turk.c turk_moves.c \
			ft_maths.c costs.c \

			

SRCS = $(addprefix ./srcs/, $(SRC_FILES))

OBJS = $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) srcs/main.c
	$(CC) $(CFLAGS) srcs/main.c $(OBJS) $(INCLUDES) -o $(NAME)

test:  $(OBJS)
	$(CC) $(CFLAGS) srcs/test.c $(OBJS) $(INCLUDES) -o $(NAME)

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean test
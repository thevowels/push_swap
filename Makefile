NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror


LIBFT	= ./libft/libft.a
LIBFT_PATH = ./libft/

INCLUDES = -I includes -I $(LIBFT_PATH)includes


SRC_FILES = errors.c ft_printf.c inits.c \
			stack_aux.c stack_commands.c stack_primitives.c \
			test_helper.c turk.c turk_moves.c \
			ft_maths.c ft_strings.c costs.c \

			

SRCS = $(addprefix ./srcs/, $(SRC_FILES))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

.c.o: 
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@make -sC $(LIBFT_PATH)

$(NAME): $(OBJS) srcs/main.c $(LIBFT)
	$(CC) $(CFLAGS) srcs/main.c $(OBJS) $(LIBFT) $(INCLUDES) -o $(NAME)

test:  $(OBJS)
	$(CC) $(CFLAGS) srcs/test.c $(OBJS) $(INCLUDES) -o $(NAME)

clean: 
	rm -f $(OBJS)
	make clean -sC $(LIBFT_PATH)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all

.PHONY: all re clean fclean test
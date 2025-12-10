NAME			= push_swap
CC				= cc
CFLAGS			= -Wall -Wextra -Werror

LIBFT_DIR		= libft
LIBFT_FLAGS 	= -lft -L $(LIBFT_DIR)

INCLUDES_DIR	= includes
INCLUDES_FLAG	= -I$(INCLUDES_DIR) -I$(LIBFT_DIR)/includes
INCLUDES		= $(wildcard $(INCLUDES_DIR)/*.h) $(LIBFT_DIR)/includes/libft.h

SRCS_DIR		= srcs
SRCS			= $(wildcard $(SRCS_DIR)/*.c)
OBJS_DIR		= objs
OBJS			= $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

MAKE			= make -sC
MKDIR			= mkdir -p
RM				= rm -rf

all : $(NAME)

$(NAME) : $(OBJS)
	@echo "objs creating ? "
	@$(MAKE) $(LIBFT_DIR)
	@echo "aaaaaaaaaaa"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_FLAGS) -o $(NAME)
	@echo "hello?"

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c $(INCLUDES) | $(OBJS_DIR)
	@echo "compiling $<"
	@$(CC) $(CFLAGS) $(INCLUDES_FLAG) -c $< -o $@

$(OBJS_DIR)	:
	@$(MKDIR) $(OBJS_DIR)

clean :
	@$(RM) $(OBJS_DIR)

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re 
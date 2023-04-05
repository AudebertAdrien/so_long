NAME		= so_long

CC			= gcc -g 
CFLAGS		= -Wall -Wextra -Werror 

MLX_FLAG	= -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz

SRCS		= src/main.c \
			  src/so_long_utils.c \
			  src/get_file.c \
			  src/check_map.c \
			  src/is_exit_reachable.c \
			  src/open_window.c \
			  src/setup_images.c \
			  src/initialize_data.c \
			  src/initialize_images.c \
			  src/key_press.c \
			  src/duplicate_map.c \

INC			= -I ./include -I ./libft -I ./mlx

OBJ			= $(SRCS:src/%.c=obj/%.o)

make_lft: 
	@echo "\nMake libft\n"
	@make re -s -C ./libft
	@echo "\n==END==\n"

make_mlx:
	@echo "\nMake mlx\n"
	@make re -s -C ./mlx
	@echo "\n==END==\n"

obj/%.o: src/%.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

all: make_mlx make_lft $(NAME) 

$(NAME): $(OBJ)
	@echo "\nMake so_long\n"
	@$(CC) $^ -o $@ -Llibft -lft $(MLX_FLAG)
	@echo "\n==END==\n"

clean_mlx:
	@make clean -s -C ./mlx

clean_lft:
	@make fclean -s -C ./libft

clean:
	@rm -rf $(OBJ)

fclean: clean clean_mlx clean_lft 
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

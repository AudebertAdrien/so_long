NAME		= so_long

CC			= gcc 
CFLAGS		= -Wall -Wextra -Werror 

MLX_FLAG	= -Lmlx -lmlx -Imlx -lXext -lX11 -lm -lz

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
	@echo ✅ "Compile libft\n"
	@make re -s -C ./libft

make_mlx:
	@echo ✅ "Compile mlx\n"
	@make re -s -C ./mlx

create_directory :
	@mkdir -p obj

obj/%.o: src/%.c create_directory
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

all: make_mlx make_lft $(NAME) 

$(NAME): $(OBJ)
	@echo ✅ "Compile so_long\n"
	@$(CC) $^ -o $@ -Llibft -lft $(MLX_FLAG)

clean_mlx:
	@make clean -s -C ./mlx

clean_lft:
	@make fclean -s -C ./libft

clean:
	@rm -rf $(OBJ)
	@rm -rf obj/

fclean: clean clean_mlx clean_lft 
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re \
	make_lft \
	make_mlx \
	create_directory \
	clean_mlx \
	clean_lft \

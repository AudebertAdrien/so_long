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

obj/%.o: src/%.c create_obj_dir
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

all: $(NAME) 

create_obj_dir :
	@mkdir -p obj

$(NAME): $(OBJ)
	@echo ✅ "Compile libft\n"
	@make re -s -C ./libft
	@echo ✅ "Compile so_long\n"
	@$(CC) $^ -o $@ -Llibft -lft $(MLX_FLAG)

clean_lft:
	@echo ✅ "Clean libft\n"
	@make fclean -s -C ./libft

clean:
	@rm -rf $(OBJ)
	@rm -rf obj/

fclean: clean clean_lft 
	@echo ✅ "Clean so_long\n"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re \
	create_directory \
	clean_lft \

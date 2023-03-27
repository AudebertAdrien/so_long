NAME		= a.out

CC			= gcc -g
CFLAGS		= -Wall -Wextra 

MLX_FLAG	= -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz

SRCS		= src/main.c \
			  src/so_long_utils.c \
			  src/get_file.c \
			  src/open_window.c \
			  src/setup_image.c \
			  src/display_image.c \
			  src/key_press.c \
			  src/handle_map.c \

INC			= -I ./include -I ./libft -I ./mlx

OBJ			= $(SRCS:src/%.c=obj/%.o)

lft: 
	@echo "\nMake libft\n"
	@make re -s -C ./libft
	@echo "\n==END==\n"
	
obj/%.o: src/%.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

all: $(NAME) 

$(NAME): $(OBJ)
	@echo "\nCompile\n"
	@$(CC) $^ -o $@ -Llibft -lft $(MLX_FLAG)
	@echo "\n==END==\n"

clean:
	@rm -rf $(OBJ)
	@rm -rf libft/*.o
	@rm -rf mlx/*.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

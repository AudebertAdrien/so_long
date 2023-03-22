NAME		= a.out

CC			= gcc -g
CFLAGS		= -Wall -Wextra 

SRC			= main.c \
			  so_long_utils.c \
			  get_file.c \
			  open_window.c \
			  setup_image.c \
			  display_image.c \
			  key_press.c \
			  libft/ft_split.c \
			  libft/ft_calloc.c \
			  libft/ft_bzero.c \
			  libft/ft_substr.c \
			  libft/ft_strlen.c \
			  libft/ft_strjoin.c \
			  libft/ft_strdup.c \

OBJ			= $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ)  -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	#$(CC) $(OBJ) -fsanitize=address -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

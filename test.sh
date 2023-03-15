
NAME		= a.out

CC			= gcc
CFLAGS		= -Wall -Wextra 

DIR_SRC		= src
SRCS		= main.c \
			  display_pixel.c \
			  display_image.c \
			  key_press.c \

DIR_OBJ		= ./obj

OBJS		= $(addprefix $(DIR_OBJ),$(SRC:.c=.o))

$(DIR_OBJ)%.o: $(DIR_SRC)%.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

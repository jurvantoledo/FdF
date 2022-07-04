NAME = fdf
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LFLAGS = -framework OpenGL -framework AppKit
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx.dylib
INC = -I ./includes

SRC =	./src/main.c \
		./src/parse_map.c \
		./src/draw.c \
		./src/render_map.c \
		./src/hooks.c \
		./src/center_map.c \
		./src/utils.c \
		./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c

OBJ = ${SRC:%.c=%.o}

all: $(NAME)

$(NAME): $(MLX_LIB) $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L. -lmlx $(LIBFT) $(LFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)
	cd $(MLX_DIR) && cp ./libmlx.dylib ../

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) clean -C $(MLX_DIR)
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
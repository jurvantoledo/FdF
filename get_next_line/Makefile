NAME = gnl.a
CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC =	get_next_line.c \
		get_next_line_utils.c \

OBJ_FILES = ${SRC:%.c=%.o}

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rc $(NAME) $(OBJ_FILES)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean: rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
NAME = ./fdf

FILES = main.c \
        loop.c \
        read_map.c \
        draw.c

SRC = $(addprefix src/,$(FILES))

OBJ = $(addprefix obj/,$(FILES:.c=.o))

FLAGS = 

all : $(NAME)

$(NAME) : $(OBJ)
		@gcc -o $(NAME) -I libft $(OBJ) libft/libftprintf.a -lmlx -framework OpenGL -framework AppKit

obj/%.o: src/%.c
		@mkdir -p obj/
		@gcc $(FLAGS) -I src/ -o $@ -c $<

clean :
		@make clean -C libft/
		@rm -rf obj/

fclean : clean
		@make fclean -C libft
		@rm -f $(NAME)

re : fclean all

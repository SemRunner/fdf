NAME = ./fdf

FILES = main.c \
        read_map.c \
        loop.c \
        draw.c \
        edit_coordinates.c \
        menu.c \
        draw_full.c \
        test/calculations.c \
        test/extrapolation.c

SRC = $(addprefix src/,$(FILES))

OBJ = $(addprefix obj/,$(FILES:.c=.o))

LIB = libft/libft.a

LIB2 = libft/libftprintf.a

FLAGS = 

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C libft/
	@gcc -o $(NAME) $(OBJ) $(LIB) $(LIB2) -lmlx -framework OpenGL -framework AppKit

obj/%.o: src/%.c
	@mkdir -p obj/
	@gcc $(FLAGS) -Iinc -o $@ -c $<

clean :
	@make clean -C libft/
	@rm -rf obj/

fclean : clean
	@make fclean -C libft
	@rm -f $(NAME)

re : fclean all

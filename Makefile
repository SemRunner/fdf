NAME = ./fdf

FILES = main.c \
        read_map.c \

SRC = $(addprefix src/,$(FILES))

OBJ = $(addprefix obj/,$(FILES:.c=.o))

LIB = libft/libft.a

FLAGS = 

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C libft/
	@gcc -o $(NAME) -Ilibft $(OBJ) libft/libftprintf.a $(LIB) -lmlx -framework OpenGL -framework AppKit

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

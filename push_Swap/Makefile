SRCS	=  checker.c push_swap.c lst_funcs.c moves.c sort_list.c small_sort.c moves2.c

OBJS	= $(SRCS:.c=.o)

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

NAME	= push_swap

LIB		= libftprintf.a

all: $(NAME)
	

$(NAME): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

$(LIB):
	make -C ./ft_printf
	cp ./ft_printf/libftprintf.a .

clean:
	rm -rf $(OBJS) $(LIB)
	make clean -C ./ft_printf 

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./ft_printf 

re: fclean all
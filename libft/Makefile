CC = gcc
FLAGS = -Wall -Werror -Wextra
NAME = libft.a

SRCS = 
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf *.o

fclean: clean
	rm -rf libft.a

re: fclean all
NAME = philo
FLAGS = -Wall -Werror -Wextra
SRCS =
SRCSDEST = $(addprefix ./srcs/, $(SRCS))

all: $(NAME)

$(NAME): $(SRCSDEST) main.c
	cc $(FLAGS) -o $(NAME) main.c $(SRCSDEST) -lpthread

clean:
	rm -f *.o

fclean:
	rm -f $(NAME)

re: fclean all


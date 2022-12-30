NAME = philo
FLAGS = -Wall -Werror -Wextra
SRCS = get_info.c utils.c check_validity.c philo_init.c
SRCSDEST = $(addprefix ./srcs/, $(SRCS))

all: $(NAME)

$(NAME): $(SRCSDEST) main.c
	cc $(FLAGS) -o $(NAME) main.c $(SRCSDEST) -lpthread

clean:
	rm -f *.o

fclean:
	rm -f $(NAME)

re: fclean all


NAME = philo_bonus
FLAGS = -Wall -Werror -Wextra
SRCS = get_info.c utils.c check_validity.c simulation.c philo_life.c
SRCSDEST = $(addprefix ./srcs/, $(SRCS))

$(NAME): $(SRCSDEST) main.c
	cc $(FLAGS) -o $(NAME) main.c $(SRCSDEST) -lpthread

clean:
	rm -f *.o

fclean:
	rm -f $(NAME)

re: fclean all


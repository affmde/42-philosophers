NAME = philo
FLAGS = -Wall -Werror -Wextra
SRCS = get_info.c utils.c check_validity.c philo_init.c philo.c messages.c philo_actions.c clean.c death.c
SRCSDEST = $(addprefix ./srcs/, $(SRCS))
OBJ = $(SRCS:.c=.o)
OBJDST = $(addprefix ./srcs/, $(OBJ))

all: $(NAME)

$(NAME): $(SRCSDEST) main.c
	cc $(FLAGS) -o $(NAME) main.c $(SRCSDEST) -lpthread

clean:
	rm -f OBJDST

fclean:
	rm -f $(NAME)

re: fclean all


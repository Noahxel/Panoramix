##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## compile main.c and u.t
##

SRCTEST			=		test/test_project.c

SRC				=		src/main.c			\
						src/panoramix.c		\
						src/init_struct.c	\
						src/run_druid.c		\
						src/run_villager.c	\

TEST			=		unit_tests

NAME			=		panoramix

OBJ				=		$(SRC:.c=.o)

INCLUDESPATH	=		./include/
CFLAGS			=		-Wall -Wextra -I$(INCLUDESPATH) -pthread
TFLAGS			=		--coverage -lcriterion

all:	$(NAME)

$(NAME):		$(OBJ)
		gcc $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)

tests_run:
		gcc $(CFLAGS) $(SRCTEST) $(SRC) -o $(TEST) $(LDFLAGS) $(TFLAGS)
		./unit_tests
clean:
		rm -f *.o
		rm -f src/*.o
		rm -f $(NAME)

fclean: clean
		rm -f *.gcno
		rm -f *.gcda
		rm -f $(TEST)

re: fclean all

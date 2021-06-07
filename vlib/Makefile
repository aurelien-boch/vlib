##
## EPITECH PROJECT, 2021
## vlib
## File description:
## unit tests makefile
##

CPPFLAGS	+= 	-Wall -Wextra -I . -Wno-type-limits
CFLAGS		+=	-fprofile-arcs -ftest-coverage
LDFLAGS		+=	-lcriterion -lgcov

RM			=	rm -rf
CC			=	gcc

SRC			=	vector_emplace.c			\
				vector_emplace_back.c		\
				vector_front.c				\
				vector_back.c				\
				vector_foreach.c			\
				vector_reversed_foreach.c	\
				vector_emplace_elem.c		\
				vector_clear.c				\
				vector_empty.c				\
				vector_pop.c				\
				vector_pop_back.c			\
				vector_pop_elem.c			\
				vector_find.c

SRC_C		=	$(addprefix tests/, $(SRC))
OBJ			=	$(SRC_C:.c=.o)

NAME		=	unit_tests

tests_run: $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)
	./unit_tests

clean:
	$(RM) tests/*.gcno
	$(RM) tests/*.gcda
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean tests_run
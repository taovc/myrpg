##
## EPITECH PROJECT, 2020
## mk
## File description:
## mk
##

SRCS	=	$(shell find src -name '*.c')\
			main.c			\

SRCS_unit = src/json_parser/free_parser/free_parser.c	\
			src/json_parser/parser/get_data/check_type.c	\
			src/json_parser/parser/get_data/count_data.c	\
			src/json_parser/parser/get_data/get_id.c	\
			src/json_parser/parser/get_data/get_json_data.c	\
			src/json_parser/parser/parser_json.c	\
			src/json_parser/parser/read_file/read_file.c	\
			tests/parser_test/test_parser.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	my_rpg

RM	=		rm -f

CPPFLAGS	=		-I./include

LIB	=		-L./lib/my -lmy

CC	=		gcc

CFLAGS	=	-W -Wall -Wextra -g

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C lib/my/
			@	tput setaf 2; cat sign/sign; tput sgr0
			$(CC) -o $(NAME) $(OBJS) $(LIB) -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

clean:
			make clean -C ./lib/my/
			$(RM) $(OBJS)

fclean:		clean
			make fclean -C ./lib/my/
			$(RM) $(NAME)
			$(RM) *.gcno
			$(RM) *.gcda
			$(RM) unit_tests

re:			fclean all

tests_run:
			make fclean
			make -C lib/my/
			gcc -o unit_tests $(SRCS_unit) $(CPPFLAGS) --coverage $(LIB) -lmy -lcriterion -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window
			./unit_tests
			gcovr --exclude tests/ --branches
			gcovr --exclude tests/

.PHONY: all clean fclean re

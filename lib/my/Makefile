##
## EPITECH PROJECT, 2020
## mk
## File description:
## mk
##

RM	=	 rm -f

SRC	= 	$(shell find . -type f -name '*.c')

CPPFLAGS	=		-I../../include

CFLAGS	=	-W -Wall -Wextra -g3

OBJ	= 	$(SRC:.c=.o)

NAME	=	libmy.a

all: 		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean: 	clean
		$(RM) $(NAME)

re: 		fclean all

.PHONY: all clean fclean re
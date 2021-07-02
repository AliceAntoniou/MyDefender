##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## compile
##

MAIN	=		main.c

SRC		=		src/my_defender.c				\
				src/window.c					\
				src/menu/menu.c					\
				src/menu/init_struct.c			\
				src/menu/settings.c				\
				src/menu/free_struct.c			\
				src/menu/win_lose.c				\
				src/menu/choose_map.c			\
				src/game/game.c					\
				src/game/init_struct.c			\
				src/game/pause.c				\
				src/game/difficulty.c			\
				src/game/free_struct.c			\
				src/game/init_sprite.c			\
				src/game/doc.c					\
				src/ennemi/ennemi.c				\
				src/ennemi/set_ennemi.c			\
				src/defence/defence.c				\
				src/defence/projectiles.c			\
				src/defence/set_defence.c			\
				src/defence/anim.c

OBJ		=		$(SRC:.c=.o) $(MAIN:.c=.o)

TESTS	=

NAME	=		my_defender

LIB		=		lib/libmy.a

LIB_2	=		lib/libbuttons.a

CFLAGS 	=		-W -Wall -Wextra -g

CPPFLAGS	=	-I./include

LDFLAGS	=	-Llib/

LDIBS	=	-lmy -lmy_csfml -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all:		$(NAME)

$(NAME):	$(OBJ) $(LIB) $(LIB_2)
			gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(LDIBS)

$(LIB):
			$(MAKE) -C lib/my

$(LIB_2):	$(LIB)
			$(MAKE) -C lib/my_csfml

run:		$(NAME)
			./$(NAME)

tests_run:	LDIBS += -lcriterion --coverage
tests_run:	all
			gcc -o $@ $(SRC) $(TESTS) $(CPPFLAGS) $(LDFLAGS) $(LDIBS)
			-./$@

clean:
		find . -name "*.o" -delete -o -name "*~" -delete -o -name "*.gc*" -delete

fclean:	clean
		$(RM) $(NAME)
		$(RM) $(LIB)
		$(RM) $(LIB_2)
		$(RM) vgcore.*
		make -C lib/my fclean
		make -C lib/my_csfml fclean

re:		fclean all

.PHONY: re fclean clean tests_run run all
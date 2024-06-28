SRC 			= main.c usleep.c think_planning.c orchestrate.c orchestrate_utils.c output.c init_philo.c init_pack.c end.c
SRCS_DIR 		= ./src/
SRCS 			= $(addprefix $(SRCS_DIR), $(SRC))
OBJS			= ${SRCS:.c=.o}
NAME 			= philo

#CHECKER_SRC		= checker.c get_next_line.c get_next_line_utils.c
#CHECKER_DIR		= ./checker_folder/
#CHECKER			= $(addprefix $(CHECKER_DIR), $(CHECKER_SRC))
#CHECKER_OBJS	=  ${CHECKER:.c=.o}
#NAME_CHECKER	= checker

all : ${NAME}

.c.o:
	cc -Wall -Wextra -Werror -pthread -I ./include/ -c $< -o ${<:.c=.o}

${NAME} : $(OBJS)
	cc -Wall -Wextra -Werror -pthread $(OBJS) -o ${NAME}
#-fsanitize=thread -g3
#$(NAME_CHECKER) : $(OBJS) $(CHECKER_OBJS)
#	cc -Wall -Wextra -Werror $(OBJS) $(CHECKER_OBJS) -o $(NAME_CHECKER)

#bonus : $(NAME_CHECKER)

clean :
	rm -f ${OBJS} $(CHECKER_OBJS) $(MAIN_OBJS)

fclean : clean
	rm -f ${NAME} $(NAME_CHECKER)

re : fclean all

.PHONY: all clean fclean re
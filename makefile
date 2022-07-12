SRCS 	=	main.c get_next_line.c get_next_line_utils.c ft_split.c ft_memcpy.c ft_calloc.c  ransom.c
OBJS	=	${SRCS:.c=.o}
NAME	=	encryptacioon_va
CC		=	gcc
RM		=	rm -f
CFLAGS	=	-Wall -Wextra -Werror 
all:	${NAME}
$(NAME):	${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${SRCS}
clean:
	${RM} ${OBJS}
fclean:
	${RM} ${NAME}
re: fclean all
.PHONY: all clean fclean re

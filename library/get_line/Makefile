NAME= gnl.a
HEADE= get_next_line.h
SRC= get_next_line get_next_line_utils

OBJ = ${SRC:=.o}

CFLAGS = -Wall -Werror -Wextra
%.o: %.c $(HEADER) 
		@$(CC) $(FLAGS)  -c -o $@ $<
${NAME} : ${OBJ} ${HEADER}
	@ar -rc ${NAME} ${OBJ}
	@echo "<gnl compiled>" 
clean:
	@rm -f ${OBJ} 
fclean : clean
	@rm -f ${NAME}
re : fclean all
all : ${NAME}
#####
HEADERS_DIR= includes
SRC_DIR= sources
OBJ_DIR= objects
LIBFT= library/libft/libft.a
GET_LINE= library/get_line/gnl.a
####
NAME= cub3D
SRC := main.c makeShifthelpers.c destruct.c parse.c parseHelpers.c init.c colors.c map.c  lastCheck.c render.c degree.c movements.c
OBJ := $(SRC:.c=.o)
OBJ := $(addprefix $(OBJ_DIR)/, $(OBJ))
HEADERS := cub3d.h types.h
HEADERS := $(addprefix $(HEADERS_DIR)/, $(HEADERS))
SRC := $(addprefix $(SRC_DIR)/, $(SRC))
CFLAGS=  -g
MFLAGS=  -lmlx -framework OpenGL -framework AppKit

all: $(NAME)
 
$(GET_LINE):
	@make -C library/get_line/
$(LIBFT):
	@make -C library/libft/

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) 
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(NAME): $(OBJ)  $(LIBFT) $(GET_LINE)
	
	$(CC) $(CFLAGS) $(MFLAGS) $(GET_LINE) $(LIBFT)  $(OBJ) -o $(NAME)


clean:
	@make clean -C library/get_line/
	@make clean -C library/libft/
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(LIBFT) $(GET_LINE) $(NAME)
re: fclean all
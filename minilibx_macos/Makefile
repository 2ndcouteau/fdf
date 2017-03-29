#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

# Sweet colors just for swag :)
RED=\033[0;31m
BLUE=\033[1;34m
CYAN=\033[0;36m
ORANGE=\033[0;33m
NC=\033[0m

all: $(NOM)

$(NOM):	$(OBJ)
	@echo "${CYAN}--Compilation LIBMLX-SRCS to OBJS = OK ${NC}"
	@echo "${BLUE}--Linking $(NOM)${NC}"
	@echo "${BLUE}--ar rc $(NOM)${NC}"
	@ar rc $(NOM) $(OBJ)
	@echo "${BLUE}--ranlib $(NOM)${NC}"
	@ranlib $(NOM)

clean:
	@echo "${ORANGE}--Delete Libmlx Object ${NC}";
	@rm -rf $(OBJ)

fclean: clean
	@echo "${RED}--Delete $(NOM)${NC}"
	@rm -rf $(NOM)

re: fclean all clean

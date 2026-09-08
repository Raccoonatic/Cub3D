# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Cr#    Created: 2026/09/03 12:55:42 by lde-san-          #+#    #+#              #
#    Updated: 2026/09/03 12:55:42 by lde-san-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
BONO = cub3D_bonus

LEAK_ARGS ?= ""

LIBFT = ./inc/libft/libft.a
CUB_LIB_MAN = ./inc/libcub.a
CUB_LIB_BON = ./inc/libcubon.a

NEOR	= \033[3m\033[38;2;255;153;51m
MINT	= \033[1;38;2;55;250;133m
ORNG	= \033[1;38;2;255;153;51m
PURP	= \033[1;38;2;174;5;252m
PINK	= \033[1;38;2;255;0;251m
BABY	= \033[1;38;2;0;255;247m
BLOD	= \033[1;38;2;255;0;0m
LIME	= \033[1;38;2;0;255;0m
B_WI	= \033[1;37m
RSET	= \033[0m

MAIN_MAN = src/mandatory/cb_main.c
MAIN_BON = src/bonus/cb_main_bonus.c

SRC_DIR_MAN = src/mandatory/
SRC_DIR_BON = src/bonus/
OBJ_DIR_MAN = obj/mandatory/
OBJ_DIR_BON = obj/bonus/

MANDA = cb_destroy.c
MANDA += cb_exit.c
MANDA += cb_getborders.c
MANDA += cb_getcolors.c
MANDA += cb_getpaths.c
MANDA += cb_map_pars_utils.c
MANDA += cb_map_pars.c
MANDA += cb_scenetomap.c
MANDA += cb_define_playable_map.c
MANDA += cb_scenetomap_utils_alpha.c
MANDA += cb_scenetomap_utils_beta.c
MANDA += cb_time.c
MANDA += cb_zeroing.c
MANDA += cb_player.c
MANDA += cb_layer_init.c
MANDA += cb_minimap.c
MANDA += cb_render.c
MANDA += cb_render_utils_alpha.c
MANDA += cb_coordinate.c
MANDA += cb_movement.c
MANDA += cb_rotate.c

BONUS = cb_template_bonus.c
# BONUS +=
# BONUS +=
# BONUS +=
# BONUS +=
# BONUS +=
# BONUS +=
# BONUS +=

INC_MAN = ./inc/cb_main_header.h ./inc/cb_structs.h
INC_BON =

SRC_MAN = $(addprefix $(SRC_DIR_MAN),$(MANDA))
OBJ_MAN = $(SRC_MAN:$(SRC_DIR_MAN)%.c=$(OBJ_DIR_MAN)%.o)

SRC_BON = $(addprefix $(SRC_DIR_BON),$(BONUS))
OBJ_BON = $(SRC_BON:$(SRC_DIR_BON)%.c=$(OBJ_DIR_BON)%.o)

.PRECIOUS: $(BONUS) $(FILE) $(MAIN_MAN) $(MAIN_BON)

COMPILE = cc -g -O0 -Wall -Werror -Wextra -Wno-cast-function-type -I./inc -I./inc/mlx_linux
LEAK_FLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose

all: $(NAME)

bonus: $(BONO)

$(NAME): $(LIBFT) ./inc/mlx_linux/libmlx.a ./inc/mlx_linux/libmlx_Linux.a $(CUB_LIB_MAN) $(INC_MAN)
	@printf "$(BABY)"
	$(COMPILE) $(MAIN_MAN) $(CUB_LIB_MAN) $(LIBFT) -L./inc/mlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)
	@printf "$(MINT)"
	@ls -la
	@printf "$(RSET)"

$(BONO): $(LIBFT) ./inc/mlx_linux/libmlx.a ./inc/mlx_linux/libmlx_Linux.a $(CUB_LIB_BON) $(INC_BON)
	@printf "$(BABY)"
	$(COMPILE) $(MAIN_BON) $(CUB_LIB_BON) $(LIBFT) -L./inc/mlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $(BONO)
	@mv $(BONO) $(NAME)
	@printf "$(MINT)"
	@ls -la
	@printf "$(RSET)"

$(OBJ_DIR_MAN)%.o: $(SRC_DIR_MAN)%.c $(INC_MAN) | $(OBJ_DIR_MAN)
	@printf "$(PURP)"
	$(COMPILE) -I/usr/include -I./inc/mlx_linux -c $< -o $@
	@printf "$(RSET)"

$(OBJ_DIR_BON)%.o: $(SRC_DIR_BON)%.c $(INC_BON) | $(OBJ_DIR_BON)
	@printf "$(PURP)"
	$(COMPILE) -I/usr/include -I./inc/mlx_linux -c $< -o $@
	@printf "$(RSET)"

$(SRC_DIR_MAN):
	@mkdir -p src
	@mkdir -p $(SRC_DIR_MAN)

$(SRC_DIR_BON):
	@mkdir -p src
	@mkdir -p $(SRC_DIR_BON)

$(OBJ_DIR_MAN):
	@mkdir -p obj
	@mkdir -p $(OBJ_DIR_MAN)

$(OBJ_DIR_BON):
	@mkdir -p obj
	@mkdir -p $(OBJ_DIR_BON)

$(LIBFT):
	@printf "$(NEOR)"
	@make -C ./inc/libft
	@printf "$(RSET)"

$(CUB_LIB_MAN): $(OBJ_MAN)
	@printf "$(PINK)"
	ar -rcs $@ $^
	@printf "$(RSET)"

$(CUB_LIB_BON): $(OBJ_BON)
	@printf "$(PINK)"
	ar -rcs $@ $^
	@printf "$(RSET)"

clean: rm_parse_test_permit
	@printf "$(LIME)"
	@make -C ./inc/libft clean
	@sleep 0.3
	@printf "$(BLOD)"
	rm -rf obj
	rm -rf $(CUB_LIB_MAN)
	rm -rf $(CUB_LIB_BON)
	@sleep 0.3
	@printf "$(RSET)"

fclean: clean
	@printf "$(B_WI)"
	@make -C ./inc/libft fclean
	@sleep 0.3
	@printf "$(PURP)"
	rm -f $(NAME)
	@printf "$(MINT)"
	@sleep 0.3
	@ls -la
	@printf "$(RSET)"

re: fclean all

.PHONY: all clean fclean re leaks wipe mlx_dependencies

# /////////////////////// -- * Functionalities * -- ////////////////////// #

leaks: $(NAME)
	@printf "\n$(PINK)valgrind $(ORNG)$(LEAK_FLAGS) $(MINT)./$(NAME)"
	@printf "$(RSET)\n"
	@valgrind $(LEAK_FLAGS) ./$(NAME) $(LEAK_ARGS)
	@sleep 0.3

wipe: fclean
	@printf "$(BLOD)"
	rm -rf ./inc/mlx_linux
	rm -rf ./inc/minilibx-linux
	@printf "$(RSET)\n"

./inc/mlx_linux:
	@rm -rf ./inc/mlx_linux
	@printf "$(MINT)\n\t\t🦝 Looks like you don't have the library yet... 🦝\n"
	@sleep 0.5
	@printf "\t\t\t\t Let's get it!\n\n"
	@sleep 0.5
	@printf "$(NEOR)  wGetting it... \n"
	@printf "$(RSET)\n"
	@printf "$(PURP)"
	wget -nc https://cdn.intra.42.fr/document/document/54626/minilibx-linux.tgz
	@printf "$(BABY)"
	tar -xzf minilibx-linux.tgz
	@printf "$(RSET)\n"
	@ls -la
	@sleep 0.5
	@printf "$(LIME)"
	rm -rf minilibx-linux.tgz
	mv minilibx-linux ./inc/mlx_linux
	@printf "$(RSET)\n\n"
	@make -C ./inc/mlx_linux CC="gcc -std=gnu17"
	@sleep 1
	@printf "$(MINT)\n\t\t  🦝 There u go <3! 🦝\n\n"

./inc/mlx_linux/libmlx.a:
	@make ./inc/mlx_linux
	@make -C ./inc/mlx_linux
	@rm -rf ./inc/mlx_linux/Makefile

./inc/mlx_linux/libmlx_Linux.a:
	@make ./inc/mlx_linux
	@make -C ./inc/mlx_linux
	@rm -rf ./inc/mlx_linux/Makefile
	@sudo apt-get update || true
	@sudo apt-get upgrade || true
	@printf "$(RSET)\n\n"
	@sleep 0.5
	@printf "$(NEOR)Installing requirements... \n\n"
	sudo apt-get install xorg || true
	sudo apt-get install libxext-dev || true
	sudo apt-get install zlib1g-dev || true
	sudo apt-get install libbsd-dev || true
	@sleep 1
	@printf "$(PURP)"
	@printf "$(RSET)\n"
	@sleep 1
	@printf "$(MINT)\t\t🦝 All requirements should be installed! 🦝\n\n"
	@printf "$(RSET)"

add_parse_test_permit:
	@touch ./textures/tests/a_texture_with_no_permissions.xpm
	@mkdir -p ./textures/tests/no_permit
	@touch ./textures/tests/no_permit/no_permit.xpm
	@touch ./maps/tests/no_permissions.cub
	@mkdir -p ./maps/tests/no_permit
	@touch ./maps/tests/no_permit/in_no_permit_folder.cub
	@chmod -r ./textures/tests/a_texture_with_no_permissions.xpm
	@chmod -x ./textures/tests/no_permit
	@chmod -r ./maps/tests/no_permissions.cub
	@chmod -x ./maps/tests/no_permit

rm_parse_test_permit:
	@chmod +r ./textures/tests/a_texture_with_no_permissions.xpm || true
	@chmod +x ./textures/tests/no_permit || true
	@chmod +r ./textures/tests/no_permit/no_permit.xpm || true
	@chmod +r ./maps/tests/no_permissions.cub || true
	@chmod +x ./maps/tests/no_permit || true
	@rm -rf ./textures/tests/a_texture_with_no_permissions.xpm
	@rm -rf ./textures/tests/no_permit
	@rm -rf ./textures/tests/no_permit/no_permit.xpm
	@rm -rf ./maps/tests/no_permissions.cub
	@rm -rf ./maps/tests/no_permit

parse_tests: all add_parse_test_permit
	@printf "$(MINT)\n\t\t🦝 Initiating tests! 🦝\n"
	@printf "$(NEOR)\tHit enter after every test to continue... \n\n$(RSET)"
	@read dummy
	@printf "$(BABY)\tNo arguments: \n$(RSET)"
	! ./$(NAME)
	@read dummy
	@printf "$(BABY)\tToo many arguments: \n$(RSET)"
	! ./$(NAME) arg1 arg2
	@read dummy
	@printf "$(BABY)\tValid minimalistic scene: \n$(RSET)"
	./$(NAME) ./maps/tests/minimalistic.cub
	@read dummy
	@printf "$(BABY)\tScene with blank name: \n$(RSET)"
	! ./$(NAME) ./maps/tests/' '
	@read dummy
	@printf "$(BABY)\tScene with only .cub for name: \n$(RSET)"
	./$(NAME) ./maps/tests/.cub
	@read dummy
	@printf "$(BABY)\tScene with no .cub extension: \n$(RSET)"
	! ./$(NAME) ./maps/tests/nocub
	@read dummy
	@printf "$(BABY)\tScene with invalid extension: \n$(RSET)"
	! ./$(NAME) ./maps/tests/invalid.txt
	@read dummy
	@printf "$(BABY)\tScene with no read permissions: \n$(RSET)"
	! ./$(NAME) ./maps/tests/no_permissions.cub
	@read dummy
	@printf "$(BABY)\tScene with missing texture path: \n$(RSET)"
	! ./$(NAME) ./maps/tests/missing_path.cub
	@read dummy
	@printf "$(BABY)\tScene with missing tile: \n$(RSET)"
	! ./$(NAME) ./maps/tests/missing_tile.cub
	@read dummy
	@printf "$(BABY)\tScene without colors: \n$(RSET)"
	! ./$(NAME) ./maps/tests/no_color.cub
	@read dummy
	@printf "$(BABY)\tScene with impossible color values: \n$(RSET)"
	! ./$(NAME) ./maps/tests/impossible_color.cub
	@read dummy
	@printf "$(BABY)\tScene with non_numeric color values: \n$(RSET)"
	! ./$(NAME) ./maps/tests/non_numeric_color.cub
	@read dummy
	@printf "$(BABY)\tScene with no map: \n$(RSET)"
	! ./$(NAME) ./maps/tests/nomap.cub
	@read dummy
	@printf "$(BABY)\tScene with non-existent texture: \n$(RSET)"
	! ./$(NAME) ./maps/tests/non_existent_texture.cub
	@read dummy
	@printf "$(BABY)\tScene with a texture with no read permissions: \n$(RSET)"
	! ./$(NAME) ./maps/tests/no_permit_texture.cub
	@read dummy
	@printf "$(BABY)\tScene with a texture in a directory with no execute permissions: \n$(RSET)"
	! ./$(NAME) ./maps/tests/texture_in_dir_with_no_permit.cub
	@read dummy
	@printf "$(BABY)\tScene in a directory with no execute permissions: \n$(RSET)"
	! ./$(NAME) ./maps/tests/no_permit/in_no_permit_folder.cub
	@read dummy
	@printf "$(BABY)\tScene with a map that has blank padding around it: \n$(RSET)"
	./$(NAME) ./maps/tests/blank_padding_around_map.cub
	@read dummy
	@printf "$(BABY)\tScene with blank padding between informations: \n$(RSET)"
	./$(NAME) ./maps/tests/blank_padding_between_info.cub
	@read dummy
	@printf "$(BABY)\tScene with blank padding in color information: \n$(RSET)"
	./$(NAME) ./maps/tests/blank_padding_num.cub
	@read dummy
	@printf "$(BABY)\tScene without extra blank spaces: \n$(RSET)"
	./$(NAME) ./maps/tests/compressed.cub
	@read dummy
	@printf "$(BABY)\tScene with map not surrounded by walls: \n$(RSET)"
	! ./$(NAME) ./maps/tests/broken.cub
	@read dummy
	@printf "$(BABY)\tScene with various maps separated by blank lines: \n$(RSET)"
	./$(NAME) ./maps/tests/islands.cub
	@read dummy
	@printf "$(BABY)\tScene with a map that has more than one player start: \n$(RSET)"
	! ./$(NAME) ./maps/tests/multiplayer.cub
	@read dummy
	@printf "$(BABY)\tScene with a map that has no player start: \n$(RSET)"
	! ./$(NAME) ./maps/tests/missing_tile.cub
	@read dummy
	@printf "$(BABY)\tScene with a map with no air: \n$(RSET)"
	./$(NAME) ./maps/tests/prison.cub
	@read dummy
	@printf "$(BABY)\tScene with a map with an unexpected character: \n$(RSET)"
	! ./$(NAME) ./maps/tests/unexpected_character.cub
	@read dummy
	@printf "$(BABY)\tScene with multiple definitions of the same texture: \n$(RSET)"
	! ./$(NAME) ./maps/tests/repeat.cub
	@read dummy
	@make rm_parse_test_permit
	@printf "$(MINT)\t\t🦝 Tests completed! 🦝\n\n$(RSET)"

val_parse_tests: all add_parse_test_permit
	@printf "$(MINT)\n\t\t🦝 Initiating tests! 🦝\n"
	@printf "$(NEOR)\tHit enter after every test to continue... \n\n$(RSET)"
	@read dummy
	@printf "$(BABY)\tNo arguments: \n$(PINK)"
	! valgrind $(LEAK_FLAGS) ./$(NAME)
	@read dummy
	@printf "$(BABY)\tToo many arguments: \n$(PINK)"
	! valgrind $(LEAK_FLAGS) ./$(NAME) arg1 arg2
	@read dummy
	@printf "$(BABY)\tValid minimalistic scene: \n$(PINK)"
	valgrind $(LEAK_FLAGS) ./$(NAME) ./maps/tests/minimalistic.cub
	@read dummy
	@printf "$(BABY)\tScene with blank name: \n$(PINK)"
	! valgrind $(LEAK_FLAGS) ./$(NAME) ./maps/tests/' '
	@read dummy
	@printf "$(BABY)\tScene with only .cub for name: \n$(PINK)"
	valgrind $(LEAK_FLAGS) ./$(NAME) ./maps/tests/.cub
	@read dummy
	@printf "$(BABY)\tScene with no .cub extension: \n$(PINK)"
	! valgrind $(LEAK_FLAGS) ./$(NAME) ./maps/tests/nocub
	@read dummy
	@printf "$(BABY)\tScene with invalid extension: \n$(PINK)"
	! valgrind $(LEAK_FLAGS) ./$(NAME) ./maps/tests/invalid.txt
	@read dummy
	@printf "$(BABY)\tScene with no read permissions: \n$(PINK)"
	! valgrind $(LEAK_FLAGS) ./$(NAME) ./maps/tests/no_permissions.cub
	@read dummy
	@printf "$(BABY)\tScene with missing texture path: \n$(PINK)"
	! valgrind $(LEAK_FLAGS) ./$(NAME) ./maps/tests/missing_path.cub
	@read dummy
	@printf "$(BABY)\tScene with missing tile: \n$(PINK)"
	! valgrind $(LEAK_FLAGS) ./$(NAME) ./maps/tests/missing_tile.cub
	@read dummy
	@printf "$(BABY)\tScene without colors: \n$(PINK)"
	! valgrind $(LEAK_FLAGS) ./$(NAME) ./maps/tests/no_color.cub
	@read dummy
	@printf "$(BABY)\tScene with impossible color values: \n$(PINK)"
	! valgrind $(LEAK_FLAGS) ./$(NAME) ./maps/tests/impossible_color.cub
	@read dummy
	@printf "$(BABY)\tScene with non_numeric color values: \n$(PINK)"
	! valgrind $(LEAK_FLAGS) ./$(NAME) ./maps/tests/non_numeric_color.cub
	@read dummy
	@printf "$(BABY)\tScene with no map: \n$(PINK)"
	! valgrind $(LEAK_FLAGS) ./$(NAME) ./maps/tests/nomap.cub
	@read dummy
	@printf "$(BABY)\tScene with non-existent texture: \n$(PINK)"
	! valgrind $(LEAK_FLAGS) ./$(NAME) ./maps/tests/non_existent_texture.cub
	@read dummy
	@printf "$(BABY)\tScene with a texture with no read permissions: \n$(PINK)"
	! valgrind $(LEAK_FLAGS) ./$(NAME) ./maps/tests/no_permit_texture.cub
	@read dummy
	@printf "$(BABY)\tScene with a texture in a directory with no execute permissions: \n$(PINK)"
	! valgrind $(LEAK_FLAGS) ./$(NAME) ./maps/tests/texture_in_dir_with_no_permit.cub
	@read dummy
	@printf "$(BABY)\tScene in a directory with no execute permissions: \n$(PINK)"
	! valgrind $(LEAK_FLAGS) ./$(NAME) ./maps/tests/no_permit/in_no_permit_folder.cub
	@read dummy
	@printf "$(BABY)\tScene with a map that has blank padding around it: \n$(PINK)"
	valgrind $(LEAK_FLAGS) ./$(NAME) ./maps/tests/blank_padding_around_map.cub
	@read dummy
	@printf "$(BABY)\tScene with blank padding between informations: \n$(PINK)"
	valgrind $(LEAK_FLAGS) ./$(NAME) ./maps/tests/blank_padding_between_info.cub
	@read dummy
	@printf "$(BABY)\tScene with blank padding in color information: \n$(PINK)"
	valgrind $(LEAK_FLAGS) ./$(NAME) ./maps/tests/blank_padding_num.cub
	@read dummy
	@printf "$(BABY)\tScene without extra blank spaces: \n$(PINK)"
	valgrind $(LEAK_FLAGS) ./$(NAME) ./maps/tests/compressed.cub
	@read dummy
	@printf "$(BABY)\tScene with map not surrounded by walls: \n$(PINK)"
	! valgrind $(LEAK_FLAGS) ./$(NAME) ./maps/tests/broken.cub
	@read dummy
	@printf "$(BABY)\tScene with various maps separated by blank lines: \n$(PINK)"
	valgrind $(LEAK_FLAGS) ./$(NAME) ./maps/tests/islands.cub
	@read dummy
	@printf "$(BABY)\tScene with a map that has more than one player start: \n$(PINK)"
	! valgrind $(LEAK_FLAGS) ./$(NAME) ./maps/tests/multiplayer.cub
	@read dummy
	@printf "$(BABY)\tScene with a map that has no player start: \n$(PINK)"
	! valgrind $(LEAK_FLAGS) ./$(NAME) ./maps/tests/missing_tile.cub
	@read dummy
	@printf "$(BABY)\tScene with a map with no air: \n$(PINK)"
	valgrind $(LEAK_FLAGS) ./$(NAME) ./maps/tests/prison.cub
	@read dummy
	@printf "$(BABY)\tScene with a map with an unexpected character: \n$(PINK)"
	! valgrind $(LEAK_FLAGS) ./$(NAME) ./maps/tests/unexpected_character.cub
	@read dummy
	@printf "$(BABY)\tScene with multiple definitions of the same texture: \n$(PINK)"
	! valgrind $(LEAK_FLAGS) ./$(NAME) ./maps/tests/repeat.cub
	@read dummy
	@make rm_parse_test_permit
	@printf "$(MINT)\t\t🦝 Tests completed! 🦝\n\n$(RSET)"

normloop:
	@printf "$(NEOR) Building normloop.sh... $(RESET)"
	@sleep 0.5
	@printf "$(MINT)🦝\n\n"
	@printf "$(BABY)'# ************************************************************************ #'\n"
	@printf "$(BABY)'#                                                                          #'\n"
	@printf "$(BABY)'#                                                       :::      ::::::::  #'\n"
	@printf "$(BABY)'#  normloop.sh                                        :+:      :+:    :+:  #'\n"
	@printf "$(BABY)'#                                                   +:+ +:+         +:+    #'\n"
	@printf "$(BABY)'#  By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+       #'\n"
	@printf "$(BABY)'#                                               +#+#+#+#+#+   +#+          #'\n"
	@printf "$(BABY)'#  Created: 2026/03/14 17:57:19 by lde-san-          #+#    #+#            #'\n"
	@printf "$(BABY)'#  Updated: 2026/03/14 17:58:08 by lde-san-         ###   ########.fr      #'\n"
	@printf "$(BABY)'#                                                                          #'\n"
	@printf "$(BABY)'# ************************************************************************ #'\n"
	@> normloop.sh
	@printf "%s\n" '#!/bin/bash'>> normloop.sh
	@printf "%s\n" '# **************************************************************************** #'>> normloop.sh
	@printf "%s\n" '#                                                                              #'>> normloop.sh
	@printf "%s\n" '#                                                         :::      ::::::::    #'>> normloop.sh
	@printf "%s\n" '#    normloop.sh                                        :+:      :+:    :+:    #'>> normloop.sh
	@printf "%s\n" '#                                                     +:+ +:+         +:+      #'>> normloop.sh
	@printf "%s\n" '#    By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+         #'>> normloop.sh
	@printf "%s\n" '#                                                 +#+#+#+#+#+   +#+            #'>> normloop.sh
	@printf "%s\n" '#    Created: 2026/03/14 17:57:19 by lde-san-          #+#    #+#              #'>> normloop.sh
	@printf "%s\n" '#    Updated: 2026/03/14 17:58:08 by lde-san-         ###   ########.fr        #'>> normloop.sh
	@printf "%s\n" '#                                                                              #'>> normloop.sh
	@printf "%s\n" '# **************************************************************************** #'>> normloop.sh
	@printf "%s\n" ''>> normloop.sh
	@printf "%s\n" 'trap '\''rm -f tody.txt; exit'\'' INT'>> normloop.sh
	@printf "%s\n" ''>> normloop.sh
	@printf "%s\n" 'if [ -n '\"'$$1'\"' ]; then'>> normloop.sh
	@printf "%s\n" '	FILE='\"'$$1'\"''>> normloop.sh
	@printf "%s\n" ''>> normloop.sh
	@printf "%s\n" '	while true'>> normloop.sh
	@printf "%s\n" '	do'>> normloop.sh
	@printf "%s\n" '		norminette -R CheckForbiddenSourceHeader '\"'$$FILE'\"' | grep Error | head -n 40 > tody.txt'>> normloop.sh
	@printf "%s\n" '		clear && cat tody.txt'>> normloop.sh
	@printf "%s\n" '		tput cup 0 0'>> normloop.sh
	@printf "%s\n" '		sleep 1'>> normloop.sh
	@printf "%s\n" '	done'>> normloop.sh
	@printf "%s\n" 'else'>> normloop.sh
	@printf "%s\n" '	while true'>> normloop.sh
	@printf "%s\n" '	do'>> normloop.sh
	@printf "%s\n" '		norminette -R CheckForbiddenSourceHeader *.c | grep Error | head -n 40 > tody.txt'>> normloop.sh
	@printf "%s\n" '        clear && cat tody.txt'>> normloop.sh
	@printf "%s\n" '		tput cup 0 0'>> normloop.sh
	@printf "%s\n" '		sleep 1'>> normloop.sh
	@printf "%s\n" '	done'>> normloop.sh
	@printf "%s\n" 'fi'>> normloop.sh
	@chmod 777 normloop.sh
	@printf "$(RESET)\t\t\t🦝"

# path_of_gluttony: $(NAME)
# 	@printf "🦝 \001\033[3m\033[38;2;255;153;51m\002Building path_of_gluttony.sh... 🦝\\n"
# 	@> path_of_gluttony.sh
# 	@printf "%s\n" '#!/bin/bash' >> path_of_gluttony.sh
# 	@printf "%b%s%b\n" '\001\033[1;38;2;0;255;247m\002' '# **************************************************************************** #' '\001\033[0m\002'
# 	@printf "%s\n" '# **************************************************************************** #' >> path_of_gluttony.sh
# 	@printf "%b%s%b\n" '\001\033[1;38;2;0;255;247m\002' '#                                                                              #' '\001\033[0m\002'
# 	@printf "%s\n" '#                                                                              #' >> path_of_gluttony.sh
# 	@printf "%b%s%b\n" '\001\033[1;38;2;0;255;247m\002' '#                                                         :::      ::::::::    #' '\001\033[0m\002'
# 	@printf "%s\n" '#                                                         :::      ::::::::    #' >> path_of_gluttony.sh
# 	@printf "%b%s%b%s%b%s%b\n" '\001\033[1;38;2;0;255;247m\002' '#    ' '\001\033[1;38;2;55;250;133m\002' 'path_of_gluttony.sh                           ' '\001\033[1;38;2;0;255;247m\002' '     :+:      :+:    :+:    #' '\001\033[0m\002'
# 	@printf "%s\n" '#    path_of_gluttony.sh                                :+:      :+:    :+:    #' >> path_of_gluttony.sh
# 	@printf "%b%s%b\n" '\001\033[1;38;2;0;255;247m\002' '#                                                     +:+ +:+         +:+      #' '\001\033[0m\002'
# 	@printf "%s\n" '#                                                     +:+ +:+         +:+      #' >> path_of_gluttony.sh
# 	@printf "%b%s%b%s%b%s%b\n" '\001\033[1;38;2;0;255;247m\002' '#    ' '\001\033[1;38;2;55;250;133m\002' 'By: lde-san- <lde-san-@student.42porto.co     ' '\001\033[1;38;2;0;255;247m\002' ' +#+  +:+       +#+         #' '\001\033[0m\002'
# 	@printf "%s\n" '#    By: lde-san- <lde-san-@student.42porto.co      +#+  +:+       +#+         #' >> path_of_gluttony.sh
# 	@printf "%b%s%b\n" '\001\033[1;38;2;0;255;247m\002' '#                                                 +#+#+#+#+#+   +#+            #' '\001\033[0m\002'
# 	@printf "%s\n" '#                                                 +#+#+#+#+#+   +#+            #' >> path_of_gluttony.sh
# 	@printf "%b%s%b%s%b%s%b\n" '\001\033[1;38;2;0;255;247m\002' '#    ' '\001\033[1;38;2;0;255;0m\002' 'Created: 2026/04/07 12:44:59 by lde-san-      ' '\001\033[1;38;2;0;255;247m\002' '    #+#    #+#              #' '\001\033[0m\002'
# 	@printf "%s\n" '#    Created: 2026/04/07 12:44:59 by lde-san-          #+#    #+#              #' >> path_of_gluttony.sh
# 	@printf "%b%s%b%s%b%s%b\n" '\001\033[1;38;2;0;255;247m\002' '#    ' '\001\033[1;38;2;0;255;0m\002' 'Updated: 2026/04/07 12:44:59 by lde-san-      ' '\001\033[1;38;2;0;255;247m\002' '   ###   ########.fr        #' '\001\033[0m\002'
# 	@printf "%s\n" '#    Updated: 2026/04/07 12:44:59 by lde-san-         ###   ########.fr        #' >> path_of_gluttony.sh
# 	@printf "%b%s%b\n" '\001\033[1;38;2;0;255;247m\002' '#                                                                              #' '\001\033[0m\002'
# 	@printf "%s\n" '#                                                                              #' >> path_of_gluttony.sh
# 	@printf "%b%s%b\n" '\001\033[1;38;2;0;255;247m\002' '# **************************************************************************** #' '\001\033[0m\002'
# 	@printf "%s\n" '# **************************************************************************** #' >> path_of_gluttony.sh
# 	@printf "%s\n" '' >> path_of_gluttony.sh
# 	@printf "%s\n" 'NEOR='\''\001\033[3m\033[38;2;255;153;51m\002'\''' >> path_of_gluttony.sh
# 	@printf "%s\n" 'MINT='\''\001\033[1;38;2;55;250;133m\002'\''' >> path_of_gluttony.sh
# 	@printf "%s\n" 'ORNG='\''\001\033[1;38;2;255;153;51m\002'\''' >> path_of_gluttony.sh
# 	@printf "%s\n" 'PURP='\''\001\033[1;38;2;174;5;252m\002'\''' >> path_of_gluttony.sh
# 	@printf "%s\n" 'PINK='\''\001\033[1;38;2;255;0;251m\002'\''' >> path_of_gluttony.sh
# 	@printf "%s\n" 'BABY='\''\001\033[1;38;2;0;255;247m\002'\''' >> path_of_gluttony.sh
# 	@printf "%s\n" 'BLOD='\''\001\033[1;38;2;255;0;0m\002'\''' >> path_of_gluttony.sh
# 	@printf "%s\n" 'LIME='\''\001\033[1;38;2;0;255;0m\002'\''' >> path_of_gluttony.sh
# 	@printf "%s\n" 'RSET='\''\001\033[0m\002'\''' >> path_of_gluttony.sh
# 	@printf "%s\n" '' >> path_of_gluttony.sh
# 	@printf "%s\n" 'EXEC="./so_long"' >> path_of_gluttony.sh
# 	@printf "%s\n" 'MAP_DIR="maps"' >> path_of_gluttony.sh
# 	@printf "%s\n" 'START_LEVEL=$${1:-0}' >> path_of_gluttony.sh
# 	@printf "%s\n" '' >> path_of_gluttony.sh
# 	@printf "%s\n" 'if [ ! -x "$$EXEC" ]; then' >> path_of_gluttony.sh
# 	@printf "%s\n" '    echo -e "\n❌ $${BLOD}Error: $${ORNG}Could not find the executable $${MINT}'\''$$EXEC'\'' $${ORNG}or it is missing execution rights!\n"' >> path_of_gluttony.sh
# 	@printf "%s\n" '    echo -e "              🦝$${PURP}..*$${LIME}#$${PINK}>$${BABY}--$${LIME}>$${BABY}>$${PINK} Did you forget to run $${ORNG}'\''$${MINT}make$${ORNG}'\''$${PINK}? $${BABY}<$${LIME}<$${BABY}--$${PINK}<$${LIME}#$${PURP}*..$${RSET}🦝\n"' >> path_of_gluttony.sh
# 	@printf "%s\n" '    exit 1' >> path_of_gluttony.sh
# 	@printf "%s\n" 'fi' >> path_of_gluttony.sh
# 	@printf "%s\n" '' >> path_of_gluttony.sh
# 	@printf "%s\n" 'GLUTTORES=$$(xrandr | awk '\''/\*/ {print $$1}'\'')' >> path_of_gluttony.sh
# 	@printf "%s\n" '' >> path_of_gluttony.sh
# 	@printf "%s\n" 'MAP_SIZES=(' >> path_of_gluttony.sh
# 	@printf "%s\n" '	"$${GLUTTORES}"' >> path_of_gluttony.sh
# 	@printf "%s\n" '	"$${GLUTTORES}"' >> path_of_gluttony.sh
# 	@printf "%s\n" '	"$${GLUTTORES}"' >> path_of_gluttony.sh
# 	@printf "%s\n" '	"480x480"' >> path_of_gluttony.sh
# 	@printf "%s\n" '	"$${GLUTTORES}"' >> path_of_gluttony.sh
# 	@printf "%s\n" '	"$${GLUTTORES}"' >> path_of_gluttony.sh
# 	@printf "%s\n" '	"$${GLUTTORES}"' >> path_of_gluttony.sh
# 	@printf "%s\n" '	"600x600"' >> path_of_gluttony.sh
# 	@printf "%s\n" '	"1900x800"' >> path_of_gluttony.sh
# 	@printf "%s\n" '	"1500x1000"' >> path_of_gluttony.sh
# 	@printf "%s\n" '	"$${GLUTTORES}"' >> path_of_gluttony.sh
# 	@printf "%s\n" ')' >> path_of_gluttony.sh
# 	@printf "%s\n" '' >> path_of_gluttony.sh
# 	@printf "%s\n" 'BACKGROUNDS=(' >> path_of_gluttony.sh
# 	@printf "%s\n" '	"./textures/sunsety.xpm"' >> path_of_gluttony.sh
# 	@printf "%s\n" '	"./textures/Herculy.xpm"' >> path_of_gluttony.sh
# 	@printf "%s\n" '	"./textures/bluey.xpm"' >> path_of_gluttony.sh
# 	@printf "%s\n" '	"./textures/nighty.xpm"' >> path_of_gluttony.sh
# 	@printf "%s\n" '	"./textures/Herculy.xpm"' >> path_of_gluttony.sh
# 	@printf "%s\n" '	"./textures/Seventy.xpm"' >> path_of_gluttony.sh
# 	@printf "%s\n" '	"./textures/sunsety.xpm"' >> path_of_gluttony.sh
# 	@printf "%s\n" '	"./textures/Tranquill.xpm"' >> path_of_gluttony.sh
# 	@printf "%s\n" '	"./textures/Woody.xpm"' >> path_of_gluttony.sh
# 	@printf "%s\n" '	"./textures/nighty.xpm"' >> path_of_gluttony.sh
# 	@printf "%s\n" '	"./textures/Tranquill.xpm"' >> path_of_gluttony.sh
# 	@printf "%s\n" ')' >> path_of_gluttony.sh
# 	@printf "%s\n" '' >> path_of_gluttony.sh
# 	@printf "%s\n" 'echo -e "\n\t\t🦊 $${LIME}Starting the $${NEOR}Path of Gluttony $${LIME}Gauntlet... $${RSET}🦝\n"' >> path_of_gluttony.sh
# 	@printf "%s\n" 'sleep 1' >> path_of_gluttony.sh
# 	@printf "%s\n" '' >> path_of_gluttony.sh
# 	@printf "%s\n" 'for (( i=$$START_LEVEL; i<=10; i++ )); do' >> path_of_gluttony.sh
# 	@printf "%s\n" '    MAP_FILE="$${MAP_DIR}/lvl_$${i}.ber"' >> path_of_gluttony.sh
# 	@printf "%s\n" '    if [ ! -f "$$MAP_FILE" ]; then' >> path_of_gluttony.sh
# 	@printf "%s\n" '        echo -e "❌ $${BLOD}Error: $${ORNG}Could not find $${MINT}$$MAP_FILE$${ORNG}! Did you delete the by any chance?$${RSET}\n"' >> path_of_gluttony.sh
# 	@printf "%s\n" '        exit 1' >> path_of_gluttony.sh
# 	@printf "%s\n" '    fi' >> path_of_gluttony.sh
# 	@printf "%s\n" '' >> path_of_gluttony.sh
# 	@printf "%s\n" '        echo -e "\t              $${PURP}..*$${LIME}#$${PINK}>$${BABY}--$${LIME}>$${BABY}>$${MINT}===========$${BABY}<$${LIME}<$${BABY}--$${PINK}<$${LIME}#$${PURP}*..$${RSET}"' >> path_of_gluttony.sh
# 	@printf "%s\n" '	echo -e "\n\t\t     🦝🗺️     $${BABY}LOADING LEVEL$${MINT} $$i    🗺️ 🦝\n"' >> path_of_gluttony.sh
# 	@printf "%s\n" '        echo -e "\t              $${PURP}..*$${LIME}#$${PINK}>$${BABY}--$${LIME}>$${BABY}>$${MINT}===========$${BABY}<$${LIME}<$${BABY}--$${PINK}<$${LIME}#$${PURP}*..$${RSET}\n"' >> path_of_gluttony.sh
# 	@printf "%s\n" '	make re_path BKGRND=$${BACKGROUNDS[$$i]} &> /dev/null' >> path_of_gluttony.sh
# 	@printf "%s\n" '#################################### Calling the map over here boy!' >> path_of_gluttony.sh
# 	@printf "%s\n" '	CURRENT_SIZE="$${MAP_SIZES[$$i]}"' >> path_of_gluttony.sh
# 	@printf "%s\n" '	$$EXEC "$$MAP_FILE" $$CURRENT_SIZE' >> path_of_gluttony.sh
# 	@printf "%s\n" '	EXIT_CODE=$$?' >> path_of_gluttony.sh
# 	@printf "%s\n" '####################################    ' >> path_of_gluttony.sh
# 	@printf "%s\n" '	if [ $$EXIT_CODE -eq 42 ]; then' >> path_of_gluttony.sh
# 	@printf "%s\n" '        echo -e "\t $${PURP}..*$${LIME}#$${PINK}>$${BABY}--$${LIME}>$${BABY}>✅ $${MINT}SUCCESS! $${LIME}Moving to the next level... $${RSET}🦝$${BABY}<$${LIME}<$${BABY}--$${PINK}<$${LIME}#$${PURP}*..$${RSET}\n"' >> path_of_gluttony.sh
# 	@printf "%s\n" '        sleep 0.5' >> path_of_gluttony.sh
# 	@printf "%s\n" '' >> path_of_gluttony.sh
# 	@printf "%s\n" '    elif [ $$EXIT_CODE -eq 69 ]; then' >> path_of_gluttony.sh
# 	@printf "%s\n" '        echo -e "\n\t\t🦝💀 $${BLOD}You failed! $${PURP}Game Over on level$${PINK} $$i$${PURP}. 💀🦝\n"' >> path_of_gluttony.sh
# 	@printf "%s\n" '        exit 0' >> path_of_gluttony.sh
# 	@printf "%s\n" '' >> path_of_gluttony.sh
# 	@printf "%s\n" '    else' >> path_of_gluttony.sh
# 	@printf "%s\n" '        echo -e "❌$${BLOD} Game terminated unexpectedly $${PURP}(Exit Code: $$EXIT_CODE). $${NEOR}Aborting gauntlet.$${RSET}🦝"' >> path_of_gluttony.sh
# 	@printf "%s\n" '        exit 1' >> path_of_gluttony.sh
# 	@printf "%s\n" '    fi' >> path_of_gluttony.sh
# 	@printf "%s\n" 'done' >> path_of_gluttony.sh
# 	@printf "%s\n" '' >> path_of_gluttony.sh
# 	@printf "%s\n" 'echo -e "\t\t🦝🏆 $${MINT}CONGRATULATIONS! $${LIME}You cleared all the maps! 🏆🦝$${RSET}"' >> path_of_gluttony.sh
# 	@printf "%s\n" 'echo -e "\t              $${PURP}..*$${LIME}#$${PINK}>$${BABY}--$${LIME}>$${BABY}>$${BABY}Glutto $${LIME}now lives free of guilt! $${RSET}$${BABY}<$${LIME}<$${BABY}--$${PINK}<$${LIME}#$${PURP}*..$${RSET}"' >> path_of_gluttony.sh
# 	@chmod +x path_of_gluttony.sh
# 	@printf "\033[0m\t🦝\n"

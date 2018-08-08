# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/08 17:26:49 by wseegers          #+#    #+#              #
#    Updated: 2018/08/08 19:28:19 by wseegers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libmatrix.a
CC = clang
CFLAGS = -Wall -Wextra -Werror
INC := -I include

VEC3_SRC = vec3_add.c vec3_create.c vec3_cross.c vec3_direction.c vec3_dist.c\
		   vec3_dot.c vec3_length.c vec3_length2.c vec3_lerp.c vec3_multiply.c\
		   vec3_negate.c vec3_normalize.c vec3_print.c vec3_reflect.c\
		   vec3_scale.c vec3_set.c vec3_subtract.c vec3_transform.c
VEC3 = $(addprefix vec3/, $(VEC3_SRC))

MAT4_SRC = mat4_create.c mat4_determinant.c mat4_frustum.c mat4_init.c\
		   mat4_inverse.c mat4_look_at.c mat4_multiply.c mat4_print.c\
		   mat4_rotate.c mat4_rotate_unit_axis.c mat4_scale.c mat4_to_mat3.c\
		   mat4_to_rotation_mat.c mat4_translate.c mat4_transpose.c
MAT4 = $(addprefix mat4/, $(MAT4_SRC))

OBJ_LIST = $(patsubst %.c, %.o, $(VEC3) $(MAT4))
BIN_PATH = bin
BIN = $(addprefix $(BIN_PATH)/, $(OBJ_LIST))

all : $(NAME)

$(NAME) : $(BIN)
	ar rc $@ $?
	ranlib $@

$(BIN_PATH)/%.o :  %.c
	@mkdir -p $(BIN_PATH)
	@mkdir -p $(addprefix $(BIN_PATH)/,$(dir $<))
	$(CC) $(CFLAGS) $(INC) -MMD -c $< -o $@

clean :
	rm -rf $(BIN_PATH)

fclean : clean
	rm -f $(NAME)

re : fclean all

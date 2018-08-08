/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 14:35:41 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/08 19:30:04 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAT4_H
# define MAT4_H

# include <stdlib.h>
# include <math.h>
# include "s_frustrum.h"
# include "s_mat4.h"
# include "../vec3/vec3.h"
# include "../vec3/s_vec3.h"
# include "../mat3/s_mat3.h"

/*
**  http://www.songho.ca/
*/

typedef struct s_mat4		t_mat4;
typedef struct s_vec3		t_vec3;
typedef struct s_frustum	t_frustum;

t_mat4	*mat4_create(void);
void	mat4_init(t_mat4 *mat);
t_mat4	mat4_transpose(t_mat4 mat);
double	mat4_determinant(t_mat4 mat);
t_mat4	mat4_inverse(t_mat4 mat);
t_mat4	mat4_to_rotation_mat(t_mat4 mat);
t_mat3	mat4_to_mat3(t_mat4 mat);
t_mat4	mat4_multiply(t_mat4 m1, t_mat4 m2);
t_mat4	mat4_translate(t_mat4 mat, t_vec3 v);
t_mat4	mat4_scale(t_mat4 mat, t_vec3 vec);
t_mat4	mat4_rotate(t_mat4 mat, double angle, t_vec3 axis);
t_mat4	mat4_rotatex(t_mat4 mat, double angle);
t_mat4	mat4_rotatey(t_mat4 mat, double angle);
t_mat4	mat4_rotatez(t_mat4 mat, double angle);
t_mat4	mat4_frustum(t_frustum f);
t_mat4	mat4_perspective(double deg_fovy, double aspect_ratio, double near,
		double far);
t_mat4	mat4_ortho(t_frustum f);
t_mat4	mat4_look_at(t_vec3 eye, t_vec3 center, t_vec3 up);
void	mat4_print(t_mat4 mat);

#endif

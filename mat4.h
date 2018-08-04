/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 14:35:41 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/04 22:35:26 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAT4_h
# define MAT4_h

# include <stdlib.h>
# include "libmatrix.h"

t_mat4 *mat4_create(void);
void mat4_init(t_mat4 *mat);
t_mat4 t_mat4ranspose(t_mat4 mat);
double mat4_determinant(t_mat4 mat);
t_mat4 mat4_inverse(t_mat4 mat);
t_mat4 t_mat4oRotationMat(t_mat4 mat);
t_mat3 t_mat4oMat3(t_mat4 mat);
t_mat4 mat4_multiply(t_mat4 m1, t_mat4 m2);
t_mat4 t_mat4ranslate(t_mat4 mat, t_vec3 v);
t_mat4 mat4_scale(t_mat4 mat, t_vec3 vec);
t_mat4 mat4_rotate(t_mat4 mat, double angle, t_vec3 axis);
t_mat4 mat4_rotatex(t_mat4 mat, double angle);
t_mat4 mat4_rotateY(t_mat4 mat, double angle, t_mat4 dest);
t_mat4 mat4_rotateZ(t_mat4 mat, double angle, t_mat4 dest);
t_mat4 mat4_frustum(t_frustum f);
t_mat4 mat4_perspective(double deg_fovy, double aspect_ratio, double near, double far, t_mat4 dest);
t_mat4 mat4_ortho(t_frustum f);
t_mat4 mat4_lookAt(t_vec3 eye, t_vec3 center, t_vec3 up);
t_mat4 mat4_fromRotationTranslation(t_quat q, t_vec3 vec);
void	mat4_print(t_mat4 mat);

#endif
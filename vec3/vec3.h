/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 00:09:16 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/08 19:23:07 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

# include <stddef.h>
# include <stdlib.h>
# include <math.h>

# include "../mat4/s_mat4.h"
# include "s_vec3.h"

typedef struct s_mat4	t_mat4;
typedef struct s_vec3	t_vec3;


# define VEC3(x, y, z)		((t_vec3){(double)(x), (double)(y), (double)(z)})

t_vec3			*vec3_create(t_vec3 v);
t_vec3			*vec3_set(t_vec3 v, t_vec3 *ret);
t_vec3			vec3_add(t_vec3 v1, t_vec3 v2);
t_vec3			vec3_subtract(t_vec3 v1, t_vec3 v2);
t_vec3			vec3_multiply(t_vec3 v1, t_vec3 v2);
t_vec3			vec3_negate(t_vec3 v);
t_vec3			vec3_scale(double val, t_vec3 ret);
t_vec3			vec3_normalize(t_vec3 v);
t_vec3			vec3_cross (t_vec3 v1, t_vec3 v2);
double			vec3_length(t_vec3 vec);
double			vec3_length2(t_vec3 v);
t_vec3			vec3_direction (t_vec3 v1, t_vec3 v2);
double			vec3_dot(t_vec3 v, t_vec3 v2);
t_vec3			vec3_direction (t_vec3 v1, t_vec3 v2);
t_vec3			vec3_lerp(t_vec3 v1, t_vec3 v2, double lerp);
double			vec3_dist(t_vec3 v1, t_vec3 v2);
t_vec3			vec3_transform(t_vec3 v, t_mat4 mat);
t_vec3			vec3_reflect(t_vec3 v, t_vec3 normal);
void			vec3_print(char *name, t_vec3 v);

#endif
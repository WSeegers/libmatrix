/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 00:16:55 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/04 22:51:39 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>

#include "vec3.h"

t_vec3 *vec3_create(t_vec3 v)
{
	t_vec3 *ret;

	ret = malloc(sizeof(t_vec3));
	*ret = v;
	return (ret);    
}

t_vec3 *vec3_set(t_vec3 v, t_vec3 *ret)
{
	*ret = v;
	return (ret);
}

t_vec3 vec3_add(t_vec3 v1, t_vec3 v2)
{
	v1.x += v2.x;
	v1.y += v2.y;
	v1.z += v2.z;
	return (v1);
}

t_vec3 vec3_subtract(t_vec3 v1, t_vec3 v2)
{
	v1.x -= v2.x;
	v1.y -= v2.y;
	v1.z -= v2.z;
	return (v1);
}

t_vec3 vec3_multiply(t_vec3 v1, t_vec3 v2)
{
	v1.x *= v2.x;
	v1.y *= v2.y;
	v1.z *= v2.z;
	return (v1);
}

t_vec3 vec3_negate(t_vec3 v)
{
	return (VEC3(-v.x, -v.y, -v.z));
}

t_vec3 vec3_scale(double val, t_vec3 ret)
{
	ret.x *= val;
	ret.y *= val;
	ret.z *= val;
	return (ret);
}

t_vec3 vec3_normalize(t_vec3 v)
{
	double x;
	double y;
	double z;
	double len;

	x = v.x;
	y = v.y;
	z = v.z;
	len = sqrt(x * x + y * y + z * z);
	if (!len) 
		v = VEC3(0, 0, 0);
	else if (len == 1) 
		v = VEC3(x, y, z);
	else
	{
		len = 1 / len;
		v.x = x * len;
		v.y = y * len;
		v.z = z * len;
	}
	return (v);
}

t_vec3 vec3_cross (t_vec3 v1, t_vec3 v2)
{
	return (
		VEC3(
			v1.y * v2.z - v1.z * v2.y,
			v1.z * v2.x - v1.x * v2.z,
			v1.x * v2.y - v1.y * v2.x
			)
		);
}

double vec3_length(t_vec3 v)
{
	double x;
	double y;
	double z;

	x = v.x;
	y = v.y;
	z = v.z;
	return (sqrt(x * x + y * y + z * z));
}

double vec3_length2(t_vec3 v)
{
	double x;
	double y;
	double z;

	x = v.x;
	y = v.y;
	z = v.z;

	return (x * x + y * y + z * z);
}

double vec3_dot(t_vec3 v, t_vec3 v2)
{
	return (v.x * v2.x + v.y * v2.y + v.z * v2.z);
}

t_vec3 vec3_direction (t_vec3 v1, t_vec3 v2)
{
	double x;
	double y;
	double z;
	double len;

	x = v1.x - v2.x,
	y = v1.y - v2.y,
	z = v1.z - v2.z,
	len = sqrt(x * x + y * y + z * z);
	if (!len) {
		v1.x = 0;
		v1.y = 0;
		v1.z = 0;
		return (v1);
	}
	len = 1 / len;
	v1.x = x * len;
	v1.y = y * len;
	v1.z = z * len;
	return (v1);
}

t_vec3 vec3_lerp(t_vec3 v1, t_vec3 v2, double lerp)
{
	t_vec3 ret;

	ret.x = v1.x + lerp * (v2.x - v1.x);
	ret.y = v1.y + lerp * (v2.y - v1.y);
	ret.z = v1.z + lerp * (v2.z - v1.z);

	return ret;
}

double vec3_dist(t_vec3 v1, t_vec3 v2)
{
	double x;
	double y;
	double z;

	x = v2.x - v1.x,
	y = v2.y - v1.y,
	z = v2.z - v1.z;
	return sqrt(x*x + y*y + z*z);
}

void vec3_print(char *name, t_vec3 v)
{
	printf("%s: %f, %f, %f\n", name, v.x, v.y, v.z);
}

t_vec3	vec3_transform(t_vec3 v, t_mat4 mat)
{
	t_vec3	ret;
	double	x;
	double 	y;
	double	z;
	
	x = v.x;
	y = v.y;
	z = v.z;
	ret.x = mat.aa * x + mat.ab * y + mat.ac * z + mat.ad;
	ret.y = mat.ba * x + mat.bb * y + mat.bc * z + mat.bd;
	ret.z = mat.ca * x + mat.cb * y + mat.cc * z + mat.cd;
	return (ret);
}
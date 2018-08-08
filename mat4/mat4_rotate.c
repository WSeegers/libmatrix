/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 18:45:50 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/08 18:51:07 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat4.h"
#include "vec3.h"

t_mat4	calculate(t_mat4 mat, t_mat3 rot)
{
	t_mat4 ret;

	ret.aa = mat.aa * rot.aa + mat.ba * rot.ab + mat.ca * rot.ac;
	ret.ab = mat.ab * rot.aa + mat.bb * rot.ab + mat.cb * rot.ac;
	ret.ac = mat.ac * rot.aa + mat.bc * rot.ab + mat.cc * rot.ac;
	ret.ad = mat.ad * rot.aa + mat.bd * rot.ab + mat.cd * rot.ac;
	ret.ba = mat.aa * rot.ba + mat.ba * rot.bb + mat.ca * rot.bc;
	ret.bb = mat.ab * rot.ba + mat.bb * rot.bb + mat.cb * rot.bc;
	ret.bc = mat.ac * rot.ba + mat.bc * rot.bb + mat.cc * rot.bc;
	ret.bd = mat.ad * rot.ba + mat.bd * rot.bb + mat.cd * rot.bc;
	ret.ca = mat.aa * rot.ca + mat.ba * rot.cb + mat.ca * rot.cc;
	ret.cb = mat.ab * rot.ca + mat.bb * rot.cb + mat.cb * rot.cc;
	ret.cc = mat.ac * rot.ca + mat.bc * rot.cb + mat.cc * rot.cc;
	ret.cd = mat.ad * rot.ca + mat.bd * rot.cb + mat.cd * rot.cc;
	ret.da = mat.da;
	ret.db = mat.db;
	ret.dc = mat.dc;
	ret.dd = mat.dd;
	return (ret);
}

t_mat4	mat4_rotate(t_mat4 mat, double angle, t_vec3 axis)
{
	double s;
	double c;
	double t;
	double len;
	t_mat3 rot;

	if (!(len = sqrt(pow(axis.x, 2) + pow(axis.y, 2) + pow(axis.z, 2)))
		|| !angle)
		return (mat);
	vec3_normalize(axis);
	s = sin(angle);
	c = cos(angle);
	t = 1 - c;
	rot.aa = axis.x * axis.x * t + c;
	rot.ab = axis.y * axis.x * t + axis.z * s;
	rot.ac = axis.z * axis.x * t - axis.y * s;
	rot.ba = axis.x * axis.y * t - axis.z * s;
	rot.bb = axis.y * axis.y * t + c;
	rot.bc = axis.z * axis.y * t + axis.x * s;
	rot.ca = axis.x * axis.z * t + axis.y * s;
	rot.cb = axis.y * axis.z * t - axis.x * s;
	rot.cc = axis.z * axis.z * t + c;
	return (calculate(mat, rot));
}

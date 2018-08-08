/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_look_at.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 19:03:24 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/08 21:28:59 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat4.h"

t_mat4	mat4_look_at(t_vec3 eye, t_vec3 center, t_vec3 up)
{
	t_vec3	z;
	t_vec3	x;
	t_vec3	y;
	t_mat4	ret;

	z = vec3_normalize(vec3_direction(eye, center));
	x = vec3_normalize(vec3_cross(up, z));
	y = vec3_normalize(vec3_cross(z, x));
	ret.aa = x.x;
	ret.ab = y.x;
	ret.ac = z.x;
	ret.ad = 0;
	ret.ba = x.y;
	ret.bb = y.y;
	ret.bc = z.y;
	ret.bd = 0;
	ret.ca = x.z;
	ret.cb = y.z;
	ret.cc = z.z;
	ret.cd = 0;
	ret.da = -(x.x * eye.x + x.y * eye.y + x.z * eye.z);
	ret.db = -(y.x * eye.x + y.y * eye.y + y.z * eye.z);
	ret.dc = -(z.x * eye.x + z.y * eye.y + z.z * eye.z);
	ret.dd = 1;
	return (ret);
}

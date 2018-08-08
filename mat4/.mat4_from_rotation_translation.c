/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .mat4_from_rotation_translation.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 19:05:02 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/08 19:06:09 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include "mat4.h"
#include "quat.h"

t_mat4	mat4_fromRotationTranslation(t_quat q, t_vec3 vec)
{
	t_mat4 ret;
	double x;
	double y;
	double z;
	double w;

	x = q.x;
	y = q.y;
	z = q.z;
	w = q.w;
	ret.aa = 1 - (y * y * 2 + z * z * 2);
	ret.ab = x * y * 2 + w * z * 2;
	ret.ac = x * z * 2 - w * y * 2;
	ret.ad = 0;
	ret.ba = x * y * 2 - w * z * 2;
	ret.bb = 1 - (x * x * 2 + z * z * 2);
	ret.bc = y * z * 2 + w * x * 2;
	ret.bd = 0;
	ret.ca = x * z * 2 + w * y * 2;
	ret.cb = y * z * 2 - w * x * 2;
	ret.cc = 1 - (x * x * 2 + y * y * 2);
	ret.cd = 0;
	ret.da = vec.x;
	ret.db = vec.y;
	ret.dc = vec.z;
	ret.dd = 1;
	return (ret);
}

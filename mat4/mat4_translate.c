/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_translate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 18:42:54 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/08 19:30:42 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat4.h"

t_mat4	mat4_translate(t_mat4 mat, t_vec3 v)
{
	double	x;
	double	y;
	double	z;
	t_mat4	ret;

	x = v.x;
	y = v.y;
	z = v.z;
	ret.aa = mat.aa;
	ret.ab = mat.ab;
	ret.ac = mat.ac;
	ret.ad = mat.ad;
	ret.ba = mat.ba;
	ret.bb = mat.bb;
	ret.bc = mat.bc;
	ret.bd = mat.bd;
	ret.ca = mat.ca;
	ret.cb = mat.cb;
	ret.cc = mat.cc;
	ret.cd = mat.cd;
	ret.da = mat.aa * x + mat.ba * y + mat.ca * z + mat.da;
	ret.db = mat.ab * x + mat.bb * y + mat.cb * z + mat.db;
	ret.dc = mat.ac * x + mat.bc * y + mat.cc * z + mat.dc;
	ret.dd = mat.ad * x + mat.bd * y + mat.cd * z + mat.dd;
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_frustum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 18:58:50 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/08 21:28:24 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat4.h"
#include "s_frustrum.h"

t_mat4	mat4_frustum(t_frustum f)
{
	double	rl;
	double	tb;
	double	fn;
	t_mat4	ret;

	rl = (f.right - f.left);
	tb = (f.top - f.bottom);
	fn = (f.far - f.near);
	ret.aa = (f.near * 2) / rl;
	ret.ab = 0;
	ret.ac = 0;
	ret.ad = 0;
	ret.ba = 0;
	ret.bb = (f.near * 2) / tb;
	ret.bc = 0;
	ret.bd = 0;
	ret.ca = (f.right + f.left) / rl;
	ret.cb = (f.top + f.bottom) / tb;
	ret.cc = -(f.far + f.near) / fn;
	ret.cd = -1;
	ret.da = 0;
	ret.db = 0;
	ret.dc = -(f.far * f.near * 2) / fn;
	ret.dd = 0;
	return (ret);
}

t_mat4	mat4_perspective(double deg_fovy, double aspect_ratio, double near,
			double far)
{
	double	top;
	double	right;

	top = near * tan(deg_fovy * 3.14159265358979323846 / 360.0);
	right = top * aspect_ratio;
	return (mat4_frustum(FRUSTRUM(-right, right, -top, top, near, far)));
}

t_mat4	mat4_ortho(t_frustum f)
{
	double	rl;
	double	tb;
	double	fn;
	t_mat4	ret;

	rl = (f.right - f.left);
	tb = (f.top - f.bottom);
	fn = (f.far - f.near);
	ret.aa = 2 / rl;
	ret.ab = 0;
	ret.ac = 0;
	ret.ad = 0;
	ret.ba = 0;
	ret.bb = 2 / tb;
	ret.bc = 0;
	ret.bd = 0;
	ret.ca = 0;
	ret.cb = 0;
	ret.cc = -2 / fn;
	ret.cd = 0;
	ret.da = -(f.left + f.right) / rl;
	ret.db = -(f.top + f.bottom) / tb;
	ret.dc = -(f.far + f.near) / fn;
	ret.dd = 1;
	return (ret);
}

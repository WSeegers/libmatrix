/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_inverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 18:30:08 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/08 18:37:50 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat4.h"

static t_mat4	calculate_new(t_mat4 mat, t_mat4 temp, double det)
{
	t_mat4	ret;

	ret.aa = (mat.bb * temp.cd - mat.bc * temp.cc + mat.bd * temp.cb) * det;
	ret.ab = (-mat.ab * temp.cd + mat.ac * temp.cc - mat.ad * temp.cb) * det;
	ret.ac = (mat.db * temp.bb - mat.dc * temp.ba + mat.dd * temp.ad) * det;
	ret.ad = (-mat.cb * temp.bb + mat.cc * temp.ba - mat.cd * temp.ad) * det;
	ret.ba = (-mat.ba * temp.cd + mat.bc * temp.ca - mat.bd * temp.bd) * det;
	ret.bb = (mat.aa * temp.cd - mat.ac * temp.ca + mat.ad * temp.bd) * det;
	ret.bc = (-mat.da * temp.bb + mat.dc * temp.ac - mat.dd * temp.ab) * det;
	ret.bd = (mat.ca * temp.bb - mat.cc * temp.ac + mat.cd * temp.ab) * det;
	ret.ca = (mat.ba * temp.cc - mat.bb * temp.ca + mat.bd * temp.bc) * det;
	ret.cb = (-mat.aa * temp.cc + mat.ab * temp.ca - mat.ad * temp.bc) * det;
	ret.cc = (mat.da * temp.ba - mat.db * temp.ac + mat.dd * temp.aa) * det;
	ret.cd = (-mat.ca * temp.ba + mat.cb * temp.ac - mat.cd * temp.aa) * det;
	ret.da = (-mat.ba * temp.cb + mat.bb * temp.bd - mat.bc * temp.bc) * det;
	ret.db = (mat.aa * temp.cb - mat.ab * temp.bd + mat.ac * temp.bc) * det;
	ret.dc = (-mat.da * temp.ad + mat.db * temp.ab - mat.dc * temp.aa) * det;
	ret.dd = (mat.ca * temp.ad - mat.cb * temp.ab + mat.cc * temp.aa) * det;

	return (ret);
}

t_mat4			mat4_inverse(t_mat4 mat)
{
	t_mat4 temp;
	double det;

	temp.aa = mat.aa * mat.bb - mat.ab * mat.ba;
	temp.ab = mat.aa * mat.bc - mat.ac * mat.ba;
	temp.ac = mat.aa * mat.bd - mat.ad * mat.ba;
	temp.ad = mat.ab * mat.bc - mat.ac * mat.bb;
	temp.ba = mat.ab * mat.bd - mat.ad * mat.bb;
	temp.bb = mat.ac * mat.bd - mat.ad * mat.bc;
	temp.bc = mat.ca * mat.db - mat.cb * mat.da;
	temp.bd = mat.ca * mat.dc - mat.cc * mat.da;
	temp.ca = mat.ca * mat.dd - mat.cd * mat.da;
	temp.cb = mat.cb * mat.dc - mat.cc * mat.db;
	temp.cc = mat.cb * mat.dd - mat.cd * mat.db;
	temp.cd = mat.cc * mat.dd - mat.cd * mat.dc;
	det = 1 / (temp.aa * temp.cd - temp.ab * temp.cc + temp.ac * temp.cb +
			temp.ad * temp.ca - temp.ba * temp.bd + temp.bb * temp.bc);

	return (calculate_new(mat, temp, det));
}

/*
**	ret.aa = (mat.bb * temp.cd - mat.bc * temp.cc + mat.bd * temp.cb) * det;
**	ret.ab = (-mat.ab * temp.cd + mat.ac * temp.cc - mat.ad * temp.cb) * det;
**	ret.ac = (mat.db * temp.bb - mat.dc * temp.ba + mat.dd * temp.ad) * det;
**	ret.ad = (-mat.cb * temp.bb + mat.cc * temp.ba - mat.cd * temp.ad) * det;
**	ret.ba = (-mat.ba * temp.cd + mat.bc * temp.ca - mat.bd * temp.bd) * det;
**	ret.bb = (mat.aa * temp.cd - mat.ac * temp.ca + mat.ad * temp.bd) * det;
**	ret.bc = (-mat.da * temp.bb + mat.dc * temp.ac - mat.dd * temp.ab) * det;
**	ret.bd = (mat.ca * temp.bb - mat.cc * temp.ac + mat.cd * temp.ab) * det;
**	ret.ca = (mat.ba * temp.cc - mat.bb * temp.ca + mat.bd * temp.bc) * det;
**	ret.cb = (-mat.aa * temp.cc + mat.ab * temp.ca - mat.ad * temp.bc) * det;
**	ret.cc = (mat.da * temp.ba - mat.db * temp.ac + mat.dd * temp.aa) * det;
**	ret.cd = (-mat.ca * temp.ba + mat.cb * temp.ac - mat.cd * temp.aa) * det;
**	ret.da = (-mat.ba * temp.cb + mat.bb * temp.bd - mat.bc * temp.bc) * det;
**	ret.db = (mat.aa * temp.cb - mat.ab * temp.bd + mat.ac * temp.bc) * det;
**	ret.dc = (-mat.da * temp.ad + mat.db * temp.ab - mat.dc * temp.aa) * det;
**	ret.dd = (mat.ca * temp.ad - mat.cb * temp.ab + mat.cc * temp.aa) * det;
*/
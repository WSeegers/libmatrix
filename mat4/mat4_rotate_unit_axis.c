/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_rotate_unit_axis.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 18:52:30 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/08 21:28:12 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat4.h"

t_mat4	mat4_rotatex(t_mat4 mat, double angle)
{
	double s;
	double c;
	double temp;

	s = sin(angle);
	c = cos(angle);
	temp = mat.ba;
	mat.ba = temp * c + mat.ca * s;
	mat.ca = temp * -s + mat.ca * c;
	temp = mat.bb;
	mat.bb = temp * c + mat.cb * s;
	mat.cb = temp * -s + mat.cb * c;
	temp = mat.bc;
	mat.bc = temp * c + mat.cc * s;
	mat.cc = temp * -s + mat.cc * c;
	temp = mat.bd;
	mat.bd = temp * c + mat.cd * s;
	mat.cd = temp * -s + mat.cd * c;
	return (mat);
}

t_mat4	mat4_rotatey(t_mat4 mat, double angle)
{
	double s;
	double c;
	double temp;

	s = sin(angle);
	c = cos(angle);
	temp = mat.aa;
	mat.aa = temp * c + mat.ca * -s;
	mat.ca = temp * s + mat.ca * c;
	temp = mat.ab;
	mat.ab = temp * c + mat.cb * -s;
	mat.cb = temp * s + mat.cb * c;
	temp = mat.ac;
	mat.ac = temp * c + mat.cc * -s;
	mat.cc = temp * s + mat.cc * c;
	temp = mat.ad;
	mat.ad = temp * c + mat.cd * -s;
	mat.cd = temp * s + mat.cd * c;
	return (mat);
}

t_mat4	mat4_rotatez(t_mat4 mat, double angle)
{
	double s;
	double c;
	double temp;

	s = sin(angle);
	c = cos(angle);
	temp = mat.aa;
	mat.aa = temp * c + mat.ba * s;
	mat.ba = temp * -s + mat.ba * c;
	temp = mat.ab;
	mat.ab = temp * c + mat.bb * s;
	mat.bb = temp * -s + mat.bb * c;
	temp = mat.ac;
	mat.ac = temp * c + mat.bc * s;
	mat.bc = temp * -s + mat.bc * c;
	temp = mat.ad;
	mat.ad = temp * c + mat.bd * s;
	mat.bd = temp * -s + mat.bd * c;
	return (mat);
}

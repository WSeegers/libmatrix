/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_scale.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 18:44:06 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/08 19:30:20 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat4.h"

t_mat4	mat4_scale(t_mat4 mat, t_vec3 vec)
{
	double x;
	double y;
	double z;

	x = vec.x;
	y = vec.y;
	z = vec.z;
	mat.aa *= x;
	mat.ba *= x;
	mat.ca *= x;
	mat.da *= x;
	mat.ab *= y;
	mat.bb *= y;
	mat.cb *= y;
	mat.db *= y;
	mat.ac *= z;
	mat.bc *= z;
	mat.cc *= z;
	mat.dc *= z;
	return (mat);
}

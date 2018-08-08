/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 18:18:52 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/08 19:26:53 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3	vec3_transform(t_vec3 v, t_mat4 mat)
{
	t_vec3	ret;
	double	x;
	double	y;
	double	z;

	x = v.x;
	y = v.y;
	z = v.z;
	ret.x = mat.aa * x + mat.ab * y + mat.ac * z + mat.ad;
	ret.y = mat.ba * x + mat.bb * y + mat.bc * z + mat.bd;
	ret.z = mat.ca * x + mat.cb * y + mat.cc * z + mat.cd;
	return (ret);
}

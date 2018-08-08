/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_normalize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 18:10:27 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/08 18:10:56 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3	vec3_normalize(t_vec3 v)
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

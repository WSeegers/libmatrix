/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_direction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 18:14:18 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/08 18:15:07 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3	vec3_direction(t_vec3 v1, t_vec3 v2)
{
	double x;
	double y;
	double z;
	double len;

	x = v1.x - v2.x;
	y = v1.y - v2.y;
	z = v1.z - v2.z;
	len = sqrt(x * x + y * y + z * z);
	if (!len)
	{
		v1.x = 0;
		v1.y = 0;
		v1.z = 0;
		return (v1);
	}
	len = 1 / len;
	v1.x = x * len;
	v1.y = y * len;
	v1.z = z * len;
	return (v1);
}

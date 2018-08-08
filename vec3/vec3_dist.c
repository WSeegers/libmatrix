/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_dist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 18:16:07 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/08 18:17:01 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

double	vec3_dist(t_vec3 v1, t_vec3 v2)
{
	double x;
	double y;
	double z;

	x = v2.x - v1.x;
	y = v2.y - v1.y;
	z = v2.z - v1.z;
	return (sqrt(x * x + y * y + z * z));
}

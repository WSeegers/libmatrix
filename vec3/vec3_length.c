/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_length.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 18:12:18 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/08 18:12:49 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

double	vec3_length(t_vec3 v)
{
	double x;
	double y;
	double z;

	x = v.x;
	y = v.y;
	z = v.z;
	return (sqrt(x * x + y * y + z * z));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_lerp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 18:15:34 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/08 21:26:35 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3	vec3_lerp(t_vec3 v1, t_vec3 v2, double lerp)
{
	t_vec3 ret;

	ret.x = v1.x + lerp * (v2.x - v1.x);
	ret.y = v1.y + lerp * (v2.y - v1.y);
	ret.z = v1.z + lerp * (v2.z - v1.z);
	return (ret);
}

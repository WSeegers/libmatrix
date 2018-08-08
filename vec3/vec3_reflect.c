/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_reflect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 18:19:31 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/08 18:19:50 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3	vec3_reflect(t_vec3 i, t_vec3 normal)
{
	normal = vec3_normalize(normal);
	return (vec3_subtract(i, vec3_scale(2 * vec3_dot(i, normal), normal)));
}

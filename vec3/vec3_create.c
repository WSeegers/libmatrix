/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 17:30:10 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/08 17:30:50 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3	*vec3_create(t_vec3 v)
{
	t_vec3	*ret;

	ret = malloc(sizeof(t_vec3));
	*ret = v;
	return (ret);
}

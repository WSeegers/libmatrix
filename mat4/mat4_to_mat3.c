/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_to_mat3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 18:40:35 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/08 19:30:32 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat4.h"

t_mat3	mat4_to_mat3(t_mat4 mat)
{
	t_mat3	ret;

	ret.aa = mat.aa;
	ret.ab = mat.ab;
	ret.ac = mat.ac;
	ret.ba = mat.ba;
	ret.bb = mat.bb;
	ret.bc = mat.bc;
	ret.ca = mat.ca;
	ret.cb = mat.cb;
	ret.cc = mat.cc;
	return (ret);
}

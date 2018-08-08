/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_transpose.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 18:28:40 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/08 21:28:50 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat4.h"

t_mat4	mat4_transpose(t_mat4 mat)
{
	t_mat4 ret;

	ret.aa = mat.aa;
	ret.ab = mat.ba;
	ret.ac = mat.ca;
	ret.ad = mat.da;
	ret.ba = mat.ab;
	ret.bb = mat.bb;
	ret.bc = mat.cb;
	ret.bd = mat.db;
	ret.ca = mat.ac;
	ret.cb = mat.bc;
	ret.cc = mat.cc;
	ret.cd = mat.dc;
	ret.da = mat.ad;
	ret.db = mat.bd;
	ret.dc = mat.cd;
	ret.dd = mat.dd;
	return (ret);
}

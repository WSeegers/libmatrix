/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_multiply.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 18:42:02 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/08 18:42:19 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat4.h"

t_mat4	mat4_multiply(t_mat4 m1, t_mat4 m2)
{
	t_mat4 ret;

	ret.aa = m2.aa * m1.aa + m2.ab * m1.ba + m2.ac * m1.ca + m2.ad * m1.da;
	ret.ab = m2.aa * m1.ab + m2.ab * m1.bb + m2.ac * m1.cb + m2.ad * m1.db;
	ret.ac = m2.aa * m1.ac + m2.ab * m1.bc + m2.ac * m1.cc + m2.ad * m1.dc;
	ret.ad = m2.aa * m1.ad + m2.ab * m1.bd + m2.ac * m1.cd + m2.ad * m1.dd;
	ret.ba = m2.ba * m1.aa + m2.bb * m1.ba + m2.bc * m1.ca + m2.bd * m1.da;
	ret.bb = m2.ba * m1.ab + m2.bb * m1.bb + m2.bc * m1.cb + m2.bd * m1.db;
	ret.bc = m2.ba * m1.ac + m2.bb * m1.bc + m2.bc * m1.cc + m2.bd * m1.dc;
	ret.bd = m2.ba * m1.ad + m2.bb * m1.bd + m2.bc * m1.cd + m2.bd * m1.dd;
	ret.ca = m2.ca * m1.aa + m2.cb * m1.ba + m2.cc * m1.ca + m2.cd * m1.da;
	ret.cb = m2.ca * m1.ab + m2.cb * m1.bb + m2.cc * m1.cb + m2.cd * m1.db;
	ret.cc = m2.ca * m1.ac + m2.cb * m1.bc + m2.cc * m1.cc + m2.cd * m1.dc;
	ret.cd = m2.ca * m1.ad + m2.cb * m1.bd + m2.cc * m1.cd + m2.cd * m1.dd;
	ret.da = m2.da * m1.aa + m2.db * m1.ba + m2.dc * m1.ca + m2.dd * m1.da;
	ret.db = m2.da * m1.ab + m2.db * m1.bb + m2.dc * m1.cb + m2.dd * m1.db;
	ret.dc = m2.da * m1.ac + m2.db * m1.bc + m2.dc * m1.cc + m2.dd * m1.dc;
	ret.dd = m2.da * m1.ad + m2.db * m1.bd + m2.dc * m1.cd + m2.dd * m1.dd;
	return (ret);
}

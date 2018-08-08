/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_determinant.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 18:29:21 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/08 21:25:56 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat4.h"

double	mat4_determinant(t_mat4 mat)
{
	return (
	mat.da * mat.cb * mat.bc * mat.ad - mat.ca * mat.db * mat.bc * mat.ad -
	mat.da * mat.bb * mat.cc * mat.ad + mat.ba * mat.db * mat.cc * mat.ad +
	mat.ca * mat.bb * mat.dc * mat.ad - mat.ba * mat.cb * mat.dc * mat.ad -
	mat.da * mat.cb * mat.ac * mat.bd + mat.ca * mat.db * mat.ac * mat.bd +
	mat.da * mat.ab * mat.cc * mat.bd - mat.aa * mat.db * mat.cc * mat.bd -
	mat.ca * mat.ab * mat.dc * mat.bd + mat.aa * mat.cb * mat.dc * mat.bd +
	mat.da * mat.bb * mat.ac * mat.cd - mat.ba * mat.db * mat.ac * mat.cd -
	mat.da * mat.ab * mat.bc * mat.cd + mat.aa * mat.db * mat.bc * mat.cd +
	mat.ba * mat.ab * mat.dc * mat.cd - mat.aa * mat.bb * mat.dc * mat.cd -
	mat.ca * mat.bb * mat.ac * mat.dd + mat.ba * mat.cb * mat.ac * mat.dd +
	mat.ca * mat.ab * mat.bc * mat.dd - mat.aa * mat.cb * mat.bc * mat.dd -
	mat.ba * mat.ab * mat.cc * mat.dd + mat.aa * mat.bb * mat.cc * mat.dd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 19:06:37 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/08 19:07:05 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mat4.h"

void	mat4_print(t_mat4 mat)
{
	printf("\n|| %10.2f || %10.2f || %10.2f || %10.2f ||\n\
|| %10.2f || %10.2f || %10.2f || %10.2f ||\n\
|| %10.2f || %10.2f || %10.2f || %10.2f ||\n\
|| %10.2f || %10.2f || %10.2f || %10.2f ||\n",
		mat.aa, mat.ab, mat.ac, mat.ad,
		mat.ba, mat.bb, mat.bc, mat.bd,
		mat.ca, mat.cb, mat.cc, mat.cd,
		mat.da, mat.db, mat.dc, mat.dd);
}

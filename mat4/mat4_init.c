/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 18:27:30 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/08 18:28:05 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat4.h"

void	mat4_init(t_mat4 *mat)
{
	mat->aa = 1;
	mat->ab = 0;
	mat->ac = 0;
	mat->ad = 0;
	mat->ba = 0;
	mat->bb = 1;
	mat->bc = 0;
	mat->bd = 0;
	mat->ca = 0;
	mat->cb = 0;
	mat->cc = 1;
	mat->cd = 0;
	mat->da = 0;
	mat->db = 0;
	mat->dc = 0;
	mat->dd = 1;
}

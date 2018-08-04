/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmatrix.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 22:20:42 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/04 22:25:38 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMATRIX_H
# define LIBMATRIX_H

typedef struct	s_vec3
{
	double x;
	double y;
	double z;
}				t_vec3;

typedef struct	s_mat3
{
	double	aa;
	double	ab;
	double	ac;
	double	ba;
	double	bb;
	double	bc;
	double	ca;
	double	cb;
	double	cc;
}				t_mat3;

typedef struct	s_mat4
{
	double	aa;
	double	ab;
	double	ac;
	double	ad;
	double	ba;
	double	bb;
	double	bc;
	double	bd;
	double	ca;
	double	cb;
	double	cc;
	double	cd;
	double	da;
	double	db;
	double	dc;
	double	dd;
}				t_mat4;

typedef struct s_frustum
{
	double left;
	double right;
	double bottom;
	double top;
	double near;
	double far;
}				t_frustum;

typedef struct	s_quat
{
	double	x;
	double	y;
	double	z;
	double	w;
}				t_quat;

#define FRUSTRUM(l, r, b, t, n, f)	((t_frustum){l, r, t, b, n ,f})

#endif
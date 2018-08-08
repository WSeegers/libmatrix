/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_frustrum.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 18:57:36 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/08 19:00:26 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_FRUSTRUM_H
# define S_FRUSTRUM_H

typedef struct	s_frustum
{
	double left;
	double right;
	double bottom;
	double top;
	double near;
	double far;
}				t_frustum;

# define FRUSTRUM(l, r, b, t, n, f)	((t_frustum){l, r, t, b, n ,f})

#endif

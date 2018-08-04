/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 14:35:20 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/04 23:14:00 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat4.h"
#include "vec3.h"

t_mat4 *mat4_create(void)
{
    t_mat4 *ret;
	
	ret = malloc(sizeof(t_mat4));
    return (ret);
}

void mat4_init(t_mat4 *mat)
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

t_mat4 t_mat4ranspose(t_mat4 mat) 
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

double mat4_determinant(t_mat4 mat) 
{
    return (mat.da * mat.cb * mat.bc * mat.ad - mat.ca * mat.db * mat.bc * mat.ad -
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

#include "mat3.h"

t_mat4 mat4_inverse(t_mat4 mat)
{
	t_mat4 temp;
	t_mat4 ret;
	double det;

    temp.aa = mat.aa * mat.bb - mat.ab * mat.ba;
    temp.ab = mat.aa * mat.bc - mat.ac * mat.ba;
    temp.ac = mat.aa * mat.bd - mat.ad * mat.ba;
    temp.ad = mat.ab * mat.bc - mat.ac * mat.bb;
    temp.ba = mat.ab * mat.bd - mat.ad * mat.bb;
    temp.bb = mat.ac * mat.bd - mat.ad * mat.bc;
    temp.bc = mat.ca * mat.db - mat.cb * mat.da;
    temp.bd = mat.ca * mat.dc - mat.cc * mat.da;
    temp.ca = mat.ca * mat.dd - mat.cd * mat.da;
    temp.cb = mat.cb * mat.dc - mat.cc * mat.db;
    temp.cc = mat.cb * mat.dd - mat.cd * mat.db;
    temp.cd = mat.cc * mat.dd - mat.cd * mat.dc;
    det = 1 / (temp.aa * temp.cd - temp.ab * temp.cc + temp.ac * temp.cb +
			temp.ad * temp.ca - temp.ba * temp.bd + temp.bb * temp.bc);

	ret.aa = (mat.bb * temp.cd - mat.bc * temp.cc + mat.bd * temp.cb) * det;
	ret.ab = (-mat.ab * temp.cd + mat.ac * temp.cc - mat.ad * temp.cb) * det;
	ret.ac = (mat.db * temp.bb - mat.dc * temp.ba + mat.dd * temp.ad) * det;
	ret.ad = (-mat.cb * temp.bb + mat.cc * temp.ba - mat.cd * temp.ad) * det;
	ret.ba = (-mat.ba * temp.cd + mat.bc * temp.ca - mat.bd * temp.bd) * det;
	ret.bb = (mat.aa * temp.cd - mat.ac * temp.ca + mat.ad * temp.bd) * det;
	ret.bc = (-mat.da * temp.bb + mat.dc * temp.ac - mat.dd * temp.ab) * det;
	ret.bd = (mat.ca * temp.bb - mat.cc * temp.ac + mat.cd * temp.ab) * det;
	ret.ca = (mat.ba * temp.cc - mat.bb * temp.ca + mat.bd * temp.bc) * det;
	ret.cb = (-mat.aa * temp.cc + mat.ab * temp.ca - mat.ad * temp.bc) * det;
	ret.cc = (mat.da * temp.ba - mat.db * temp.ac + mat.dd * temp.aa) * det;
	ret.cd = (-mat.ca * temp.ba + mat.cb * temp.ac - mat.cd * temp.aa) * det;
	ret.da = (-mat.ba * temp.cb + mat.bb * temp.bd - mat.bc * temp.bc) * det;
	ret.db = (mat.aa * temp.cb - mat.ab * temp.bd + mat.ac * temp.bc) * det;
	ret.dc = (-mat.da * temp.ad + mat.db * temp.ab - mat.dc * temp.aa) * det;
	ret.dd = (mat.ca * temp.ad - mat.cb * temp.ab + mat.cc * temp.aa) * det;

    return (ret);
}

t_mat4 t_mat4oRotationMat(t_mat4 mat)
{
    mat.da = 0;
    mat.db = 0;
    mat.dc = 0;
    mat.dd = 1;

    return (mat);
}

#include "mat3.h"

t_mat3 t_mat4oMat3(t_mat4 mat) 
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

t_mat4 mat4_multiply(t_mat4 m1, t_mat4 m2)
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

t_mat4 t_mat4ranslate(t_mat4 mat, t_vec3 v)
{
	double	x;
	double	y;
	double	z;
	t_mat4	ret;

	x = v.x;
	y = v.y;
	z = v.z;
    ret.aa = mat.aa;
	ret.ab = mat.ab;
	ret.ac = mat.ac;
	ret.ad = mat.ad;
	ret.ba = mat.ba;
	ret.bb = mat.bb;
	ret.bc = mat.bc;
	ret.bd = mat.bd;
	ret.ca = mat.ca;
	ret.cb = mat.cb;
	ret.cc = mat.cc;
	ret.cd = mat.cd;
    ret.da = mat.aa * x + mat.ba * y + mat.ca * z + mat.da;
    ret.db = mat.ab * x + mat.bb * y + mat.cb * z + mat.db;
    ret.dc = mat.ac * x + mat.bc * y + mat.cc * z + mat.dc;
    ret.dd = mat.ad * x + mat.bd * y + mat.cd * z + mat.dd;
    return (ret);
}

t_mat4 mat4_scale(t_mat4 mat, t_vec3 vec)
{
	double x;
	double y;
	double z;

	x = vec.x;
	y = vec.y;
	z = vec.z;
	mat.aa *= x;
	mat.ba *= x;
	mat.ca *= x;
	mat.da *= x;
	mat.ab *= y;
	mat.bb *= y;
	mat.cb *= y;
	mat.db *= y;
	mat.ac *= z;
	mat.bc *= z;
	mat.cc *= z;
	mat.dc *= z;
	return (mat);

}

t_mat4 mat4_rotate(t_mat4 mat, double angle, t_vec3 axis)
{
    double s;
	double c;
	double t;
	double len;
	t_mat3 rot;

    if (!(len = sqrt(pow(axis.x, 2) + pow(axis.y, 2) + pow(axis.z, 2))) || !angle)
		return (mat);
	vec3_normalize(axis);
    s = sin(angle);
    c = cos(angle);
    t = 1 - c;
	
	
    // Construct the elements of the rotation matrix
    rot.aa = axis.x * axis.x * t + c;
	rot.ab = axis.y * axis.x * t + axis.z * s;
	rot.ac = axis.z * axis.x * t - axis.y * s;
    rot.ba = axis.x * axis.y * t - axis.z * s;
	rot.bb = axis.y * axis.y * t + c;
	rot.bc = axis.z * axis.y * t + axis.x * s;
    rot.ca = axis.x * axis.z * t + axis.y * s;
	rot.cb = axis.y * axis.z * t - axis.x * s;
	rot.cc = axis.z * axis.z * t + c;

    // Perform rotation-specific matrix multiplication
	t_mat4 ret;
    ret.aa = mat.aa * rot.aa + mat.ba * rot.ab + mat.ca * rot.ac;
    ret.ab = mat.ab * rot.aa + mat.bb * rot.ab + mat.cb * rot.ac;
    ret.ac = mat.ac * rot.aa + mat.bc * rot.ab + mat.cc * rot.ac;
    ret.ad = mat.ad * rot.aa + mat.bd * rot.ab + mat.cd * rot.ac;
    ret.ba = mat.aa * rot.ba + mat.ba * rot.bb + mat.ca * rot.bc;
    ret.bb = mat.ab * rot.ba + mat.bb * rot.bb + mat.cb * rot.bc;
    ret.bc = mat.ac * rot.ba + mat.bc * rot.bb + mat.cc * rot.bc;
    ret.bd = mat.ad * rot.ba + mat.bd * rot.bb + mat.cd * rot.bc;
    ret.ca = mat.aa * rot.ca + mat.ba * rot.cb + mat.ca * rot.cc;
    ret.cb = mat.ab * rot.ca + mat.bb * rot.cb + mat.cb * rot.cc;
    ret.cc = mat.ac * rot.ca + mat.bc * rot.cb + mat.cc * rot.cc;
    ret.cd = mat.ad * rot.ca + mat.bd * rot.cb + mat.cd * rot.cc;
	ret.da = mat.da;
	ret.db = mat.db;
	ret.dc = mat.dc;
	ret.dd = mat.dd;
    return (ret);
}

t_mat4 mat4_rotatex(t_mat4 mat, double angle)
{
    double s;
	double c;

	double temp;
	
	s = sin(angle);
    c = cos(angle);

    // Perform axis-specific matrix multiplication
	temp = mat.ba;
    mat.ba = temp * c + mat.ca * s;
    mat.ca = temp * -s + mat.ca * c;
	temp = mat.bb;
	mat.bb = temp * c + mat.cb * s;
    mat.cb = temp * -s + mat.cb * c;
	temp = mat.bc;
	mat.bc = temp * c + mat.cc * s;
    mat.cc = temp * -s + mat.cc * c;
	temp = mat.bd;
	mat.bd = temp * c + mat.cd * s;
	mat.cd = temp * -s + mat.cd * c;
    return (mat);
}

t_mat4 mat4_rotateY(t_mat4 mat, double angle, t_mat4 dest)
{
    double s;
	double c;
	double temp;
	
	s = sin(angle);
    c = cos(angle);

    // Perform axis-specific matrix multiplication
	temp = mat.aa;
	mat.aa = temp * c + mat.ca * -s;
	mat.ca = temp * s + mat.ca * c;
	temp = mat.ab;
	mat.ab = temp * c + mat.cb * -s;
    mat.cb = temp * s + mat.cb * c;
	temp = mat.ac;
	mat.ac = temp * c + mat.cc * -s;
    mat.cc = temp * s + mat.cc * c;
	temp = mat.ad;
	mat.ad = temp * c + mat.cd * -s;
    mat.cd = temp * s + mat.cd * c;
    return dest;
}

t_mat4 mat4_rotateZ(t_mat4 mat, double angle, t_mat4 dest)
{
    double s;
	double c;
	double temp;
	
	s = sin(angle);
    c = cos(angle);

    // Perform axis-specific matrix multiplication
	temp = mat.aa;
	mat.aa = temp * c + mat.ba * s;
    mat.ba = temp * -s + mat.ba * c;
	temp = mat.ab;
	mat.ab = temp * c + mat.bb * s;
    mat.bb = temp * -s + mat.bb * c;
	temp = mat.ac;
	mat.ac = temp * c + mat.bc * s;
    mat.bc = temp * -s + mat.bc * c;
	temp = mat.ad;
	mat.ad = temp * c + mat.bd * s;
    mat.bd = temp * -s + mat.bd * c;

    return dest;
}

/*
**  http://www.songho.ca/opengl/gl_projectionmatrix.html
*/

t_mat4 mat4_frustum(t_frustum f)
{
	double	rl;
	double	tb;
	double	fn;
	t_mat4	ret;

    rl = (f.right - f.left);
	tb = (f.top - f.bottom);
    fn = (f.far - f.near);
    ret.aa = (f.near * 2) / rl;
    ret.ab = 0;
    ret.ac = 0;
    ret.ad = 0;
    ret.ba = 0;
    ret.bb = (f.near * 2) / tb;
    ret.bc = 0;
    ret.bd = 0;
    ret.ca = (f.right + f.left) / rl;
    ret.cb = (f.top + f.bottom) / tb;
    ret.cc = -(f.far + f.near) / fn;
    ret.cd = -1;
    ret.da = 0;
    ret.db = 0;
    ret.dc = -(f.far * f.near * 2) / fn;
    ret.dd = 0;
    return (ret);
}

t_mat4 mat4_perspective(double deg_fovy, double aspect_ratio, double near, double far, t_mat4 dest) 
{
    double top = near * tan(deg_fovy * 3.14159265358979323846 / 360.0),
        right = top * aspect_ratio;
    return mat4_frustum(FRUSTRUM(-right, right, -top, top, near, far));
}

t_mat4 mat4_ortho(t_frustum f)
{
    double	rl;
	double	tb;
	double	fn;
	t_mat4	ret;

    rl = (f.right - f.left);
	tb = (f.top - f.bottom);
    fn = (f.far - f.near);

    ret.aa = 2 / rl;
    ret.ab = 0;
    ret.ac = 0;
    ret.ad = 0;
    ret.ba = 0;
    ret.bb = 2 / tb;
    ret.bc = 0;
    ret.bd = 0;
    ret.ca = 0;
    ret.cb = 0;
    ret.cc = -2 / fn;
    ret.cd = 0;
    ret.da = -(f.left + f.right) / rl;
    ret.db = -(f.top + f.bottom) / tb;
    ret.dc = -(f.far + f.near) / fn;
    ret.dd = 1;
    return (ret);
}

t_mat4 mat4_lookAt(t_vec3 eye, t_vec3 center, t_vec3 up) 
{
	t_vec3	z;
	t_vec3	x;
	t_vec3	y;
	t_mat4	ret;
    
	z = vec3_normalize(vec3_direction(eye, center));
	x = vec3_normalize(vec3_cross(up, z));
    y = vec3_normalize(vec3_cross(z, x));
    ret.aa = x.x;
    ret.ab = y.x;
    ret.ac = z.x;
    ret.ad = 0;
    ret.ba = x.y;
    ret.bb = y.y;
    ret.bc = z.y;
    ret.bd = 0;
    ret.ca = x.z;
    ret.cb = y.z;
    ret.cc = z.z;
    ret.cd = 0;
    ret.da = -(x.x * eye.x + x.y * eye.y + x.z * eye.z);
    ret.db = -(y.x * eye.x + y.y * eye.y + y.z * eye.z);
    ret.dc = -(z.x * eye.x + z.y * eye.y + z.z * eye.z);
    ret.dd = 1;
    return (ret);
}

t_mat4 mat4_fromRotationTranslation(t_quat q, t_vec3 vec)
{
	t_mat4 ret;
	double x;
	double y;
	double z;
	double w;

    x = q.x;
	y = q.y;
	z = q.z;
	w = q.w;
    ret.aa = 1 - (y * y * 2 + z * z * 2);
    ret.ab = x * y * 2 + w * z * 2;
    ret.ac = x * z * 2 - w * y * 2;
    ret.ad = 0;
    ret.ba = x * y * 2 - w * z * 2;
    ret.bb = 1 - (x * x * 2 + z * z * 2);
    ret.bc = y * z * 2 + w * x * 2;
    ret.bd = 0;
    ret.ca = x * z * 2 + w * y * 2;
    ret.cb = y * z * 2 - w * x * 2;
    ret.cc = 1 - (x * x * 2 + y * y * 2);
    ret.cd = 0;
    ret.da = vec.x;
    ret.db = vec.y;
    ret.dc = vec.z;
    ret.dd = 1;

    return (ret);
}

void	mat4_print(t_mat4 mat)
{
	printf ("\n|| %10.2f || %10.2f || %10.2f || %10.2f ||\n\
|| %10.2f || %10.2f || %10.2f || %10.2f ||\n\
|| %10.2f || %10.2f || %10.2f || %10.2f ||\n\
|| %10.2f || %10.2f || %10.2f || %10.2f ||\n",
		mat.aa, mat.ab, mat.ac, mat.ad,
		mat.ba, mat.bb, mat.bc, mat.bd,
		mat.ca, mat.cb, mat.cc, mat.cd,
		mat.da, mat.db, mat.dc, mat.dd);
}
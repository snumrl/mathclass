
#include "mathclass.h"


namespace jhm {

m_real
point3::length() const
{
	return sqrt( float(p[0]*p[0] + p[1]*p[1] + p[2]*p[2]) );
}



// negation
point3 operator-( point3 const& a )
{
	point3 b;

	b.p[0] = -1 * a.p[0];
	b.p[1] = -1 * a.p[1];
	b.p[2] = -1 * a.p[2];

	return b;
}
    
// addtion
point3& operator+=( point3& a, point3 const& b )
{
	a.p[0] += b.p[0];
	a.p[1] += b.p[1];
	a.p[2] += b.p[2];
	
	return a;
}


point3 operator+( point3 const& a, point3 const& b )
{
	point3 c;

	c.p[0] = a.p[0] + b.p[0];
	c.p[1] = a.p[1] + b.p[1];
	c.p[2] = a.p[2] + b.p[2];

	return c;
}
    
// subtraction
point3 operator-( point3 const& a, point3 const& b )
{
	point3 c;

	c.p[0] = a.p[0] - b.p[0];
	c.p[1] = a.p[1] - b.p[1];
	c.p[2] = a.p[2] - b.p[2];

	return c;
}


point3& operator-=( point3& a, point3 const& b )
{
	a.p[0] -= b.p[0];
	a.p[1] -= b.p[1];
	a.p[2] -= b.p[2];

	return a;
}

}









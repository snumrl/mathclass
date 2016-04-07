
#include "mathclass.h"

namespace jhm {

m_real
point2::length() const
{
	return sqrt( float(p[0]*p[0] + p[1]*p[1]) );
}



// negation
point2 operator-( point2 const& a )
{
	point2 b;

	b.p[0] = -1 * a.p[0];
	b.p[1] = -1 * a.p[1];

	return b;
}
    
// addtion
point2& operator+=( point2& a, point2 const& b )
{
	a.p[0] += b.p[0];
	a.p[1] += b.p[1];
	return a;
}


point2 operator+( point2 const& a, point2 const& b )
{
	point2 c;

	c.p[0] = a.p[0] + b.p[0];
	c.p[1] = a.p[1] + b.p[1];

	return c;
}
    
// subtraction
point2 operator-( point2 const& a, point2 const& b )
{
	point2 c;

	c.p[0] = a.p[0] - b.p[0];
	c.p[1] = a.p[1] - b.p[1];

	return c;
}


point2& operator-=( point2& a, point2 const& b )
{
	a.p[0] -= b.p[0];
	a.p[1] -= b.p[1];

	return a;
}


}








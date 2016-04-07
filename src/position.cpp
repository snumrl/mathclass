
#include "mathclass.h"

namespace jhm {

position
interpolate( m_real t, position const& a, position const& b )
{
    position c;

    c.p[0] = (1.0-t)*a.p[0] + t*b.p[0];
    c.p[1] = (1.0-t)*a.p[1] + t*b.p[1];
    c.p[2] = (1.0-t)*a.p[2] + t*b.p[2];

    return c;
}

position
affineCombination( position const& p1, position const& p2, m_real t1 )
{
    position c;

    c.p[0] = t1*p1.p[0] + (1-t1)*p2.p[0];
    c.p[1] = t1*p1.p[1] + (1-t1)*p2.p[1];
    c.p[2] = t1*p1.p[2] + (1-t1)*p2.p[2];

    return c;
}

position
affineCombination( position const& p1, position const& p2, position const& p3,
				   m_real t1, m_real t2 )
{
    position c;
	m_real t3 = 1.0 - t1 - t2;

    c.p[0] = t1*p1.p[0] + t2*p2.p[0] + t3*p3.p[0];
    c.p[1] = t1*p1.p[1] + t2*p2.p[1] + t3*p3.p[1];
    c.p[2] = t1*p1.p[2] + t2*p2.p[2] + t3*p3.p[2];

    return c;
}

position
affineCombination( position const& p1, position const& p2, position const& p3, position const& p4,
				   m_real t1, m_real t2, m_real t3 )
{
    position c;
	m_real t4 = 1.0 - t1 - t2 - t3;

    c.p[0] = t1*p1.p[0] + t2*p2.p[0] + t3*p3.p[0] + t4*p4.p[0];
    c.p[1] = t1*p1.p[1] + t2*p2.p[1] + t3*p3.p[1] + t4*p4.p[1];
    c.p[2] = t1*p1.p[2] + t2*p2.p[2] + t3*p3.p[2] + t4*p4.p[2];

    return c;
}

position affineCombination( int n, position p[], m_real t[] )
{
	position c(0,0,0);
	m_real tn = 1.0;

	for( int i=0; i<n-1; i++ )
	{
		c.p[0] += t[i] * p[i].p[0];
		c.p[1] += t[i] * p[i].p[1];
		c.p[2] += t[i] * p[i].p[2];

		tn -= t[i];
	}

	c.p[0] += tn * p[n-1].p[0];
	c.p[1] += tn * p[n-1].p[1];
	c.p[2] += tn * p[n-1].p[2];

	return c;
}

m_real
distance( position const& p1, position const& p2 )
{
    return len(p2-p1);
}

m_real
distance( position const& p, position const& p1, position const& p2 )
{
    vector v1 = p2 - p1;
    vector v2 = p - p1;
    m_real t = ( v1 % v2 ) / ( v1 % v1 );
    position p3 = p1 + t*v1;

    return distance( p, p3 );
}

std::ostream& operator<<( std::ostream& os, position const& a )
{
    os << "( " << a.p[0] << " , " << a.p[1] << " , " << a.p[2] << " )";
    return os;
}

std::istream& operator>>( std::istream& is, position& a )
{
	static char buf[256];
	// is >> "(" >> a.p[0] >> "," >> a.p[1] >> "," >> a.p[2] >> ")";
    is >> buf >> a.p[0] >> buf >> a.p[1] >> buf >> a.p[2] >> buf;

    return is;
}

}
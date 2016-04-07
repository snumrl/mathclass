
#include "mathclass.h"

namespace jhm {

vector
interpolate( m_real t, vector const& a, vector const& b )
{
	return (1.0-t)*a + t*b;
}

m_real len( vector const& v )
{
    return sqrt( v.p[0]*v.p[0] + v.p[1]*v.p[1] + v.p[2]*v.p[2] );
}

m_real
vector::length() const
{
    return sqrt( p[0]*p[0] + p[1]*p[1] + p[2]*p[2] );
}

matrix
vector::cross() const
{
    return matrix(	vector(  0 ,-z(), y()),
					vector( z(),  0 ,-x()),
					vector(-y(), x(),  0 ) );
}

unit_vector
vector::normalize() const
{
	m_real d = sqrt(p[0]*p[0] + p[1]*p[1] + p[2]*p[2]);
	return unit_vector( p[0]/d, p[1]/d, p[2]/d );
}

m_real angle( vector const& a, vector const& b )
{
    return ACOS( (a%b)/(len(a)*len(b)) );
}

position vector2position( vector const& v )
{
    return position( v.x(), v.y(), v.z() );
}

vector position2vector( position const& p )
{
    return vector( p.x(), p.y(), p.z() );
}

std::ostream& operator<<( std::ostream& os, vector const& a )
{
    os << "( " << a.p[0] << " , " << a.p[1] << " , " << a.p[2] << " )";
    return os;
}

std::istream& operator>>( std::istream& is, vector& a )
{
	static char buf[256];

    is >> buf >> a.p[0] >> buf >> a.p[1] >> buf >> a.p[2] >> buf;
    return is;
}


}
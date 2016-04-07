
#include "mathclass.h"

namespace jhm {

std::ostream& operator<<( std::ostream& os, box const& a )
{
    os << "[" << a.x << "," << a.y << "," << a.z << "]";
    return os;
}

std::istream& operator>>( std::istream& is, box& a )
{
	static char	buf[256];
    //is >> "[" >> a.x >> "," >> a.y >> "," >> a.z >> "]";
	is >> buf >> a.x >> buf >> a.y >> buf >> a.z >> buf;
    return is;
}

box& operator+=( box& a, vector const& b )
{
    a.x += b.x();
    a.y += b.y();
    a.z += b.z();

    return a;
}

box operator+( box const& a, vector const& b )
{
    box c( a );

    c.x += b.x();
    c.y += b.y();
    c.z += b.z();

    return c;
}

box operator+( vector const& b, box const& a )
{
    box c( a );

    c.x += b.x();
    c.y += b.y();
    c.z += b.z();

    return c;
}

box& operator-=( box& a, vector const& b )
{
    a.x -= b.x();
    a.y -= b.y();
    a.z -= b.z();

    return a;
}

box operator-( box const& a, vector const& b )
{
    box c( a );

    c.x -= b.x();
    c.y -= b.y();
    c.z -= b.z();

    return c;
}

box& operator*=( box& a, m_real b )
{
    a.x *= b;
    a.y *= b;
    a.z *= b;

    return a;
}

box operator*( box const& a, m_real b )
{
    box c( a );

    c.x *= b;
    c.y *= b;
    c.z *= b;

    return c;
}

box operator*( m_real b, box const& a )
{
    box c( a );

    c.x *= b;
    c.y *= b;
    c.z *= b;

    return c;
}

box& operator/=( box& a, m_real b )
{
    a.x /= b;
    a.y /= b;
    a.z /= b;

    return a;
}

box operator/( box const& a, m_real b )
{
    box c( a );

    c.x /= b;
    c.y /= b;
    c.z /= b;

    return c;
}

box& operator|=( box& a, box const& b )
{
    a.x |= b.x;
    a.y |= b.y;
    a.z |= b.z;

    return a;
}

box operator|( box const& a, box const& b )
{
    box c( a );

    c.x |= b.x;
    c.y |= b.y;
    c.z |= b.z;

    return c;
}

int operator>>( box const& a, position b )
{
    if ( a.x>>b.x() && a.y>>b.y() && a.z>>b.z() ) return TRUE;
                                             else return FALSE;
}

int operator<<( position b, box const& a )
{
    if ( a.x>>b.x() && a.y>>b.y() && a.z>>b.z() ) return TRUE;
                                             else return FALSE;
}

int operator>>( box const& a, box const& b )
{
    if ( a.x>>b.x && a.y>>b.y && a.z>>b.z ) return TRUE;
                                       else return FALSE;
}

int operator<<( box const& b, box const& a )
{
    if ( a.x>>b.x && a.y>>b.y && a.z>>b.z ) return TRUE;
                                       else return FALSE;
}

box& operator&=( box& a, box const& b )
{
    a.x &= b.x;
    a.y &= b.y;
    a.z &= b.z;
                               
    return a;
}

box operator&( box const& a, box const& b )
{
    box c( a );

    c.x &= b.x;
    c.y &= b.y;
    c.z &= b.z;
                               
    return c;
}

int operator&&( box const& a, box const& b )
{
    return ( (a.x && b.x) && (a.y && b.y) && (a.z && b.z) );
}

box operator^( box const& a, m_real b )
{
    return box( a.x ^ b, a.y ^ b, a.z ^ b );
}

vector
box::project( const vector& v ) const
{
    m_real a = this->x.project( v.x() );
    m_real b = this->y.project( v.y() );
    m_real c = this->z.project( v.z() );
    return vector( a, b, c );
}

}
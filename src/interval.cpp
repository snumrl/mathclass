
#include "mathclass.h"

m_real EPS_jhm = 1.0e-4;

namespace jhm {
std::ostream& operator<<( std::ostream& os, interval const& a )
{
    os << "[ " << a.start << " , " << a.end << " ]";
    return os;
}

std::istream& operator>>( std::istream& is, interval& a )
{
	static char	buf[256];
    //is >> "[" >> a.start >> "," >> a.end >> "]";
	is >> buf >> a.start >> buf >> a.end >> buf;
    return is;
}

interval operator-( interval const& a )
{
    return interval( -a.end, -a.start );
}

interval& operator+=( interval& a, m_real b )
{
    a.start += b;
    a.end   += b;

    return a;
}

interval operator+( interval const& a, m_real b )
{
    return interval( a.start + b, a.end + b );
}

interval operator+( m_real b, interval const& a )
{
    return interval( a.start + b, a.end + b );
}

interval& operator-=( interval& a, m_real b )
{
    a.start -= b;
    a.end   -= b;

    return a;
}

interval operator-( interval const& a, m_real b )
{
    return interval( a.start - b, a.end - b );
}

interval& operator*=( interval& a, m_real b )
{
    a.start *= b;
    a.end   *= b;
    adjust_interval( a );

    return a;
}

interval operator*( interval const& a, m_real b )
{
    interval c( a.start * b, a.end * b );
    adjust_interval( c );

    return c;
}

interval operator*( m_real b, interval const& a )
{
    interval c( a.start * b, a.end * b );
    adjust_interval( c );

    return c;
}

interval& operator/=( interval& a, m_real b )
{
    a.start /= b;
    a.end   /= b;
    adjust_interval( a );

    return a;
}

interval operator/( interval const& a, m_real b )
{
    interval c( a.start / b, a.end / b );
    adjust_interval( c );

    return c;
}

interval& operator|=( interval& a, interval const& b )
{
    a.start = MIN( a.start, b.start );
    a.end   = MAX( a.end  , b.end   );

    return a;
}

interval operator|( interval const& a, interval const& b )
{
    return interval( MIN( a.start, b.start ), MAX( a.end, b.end ) );
}

int operator>>( interval const& a, m_real b )
{
    if ( a.start<b+EPS_jhm && b<a.end+EPS_jhm ) return TRUE;
                                   else return FALSE;
}

int operator<<( m_real b, interval const& a )
{
    if ( a.start<b+EPS_jhm && b<a.end+EPS_jhm ) return TRUE;
                                   else return FALSE;
}

int operator>>( interval const& a, interval const& b )
{
    if ( a.start<b.start+EPS_jhm && b.end<a.end+EPS_jhm ) return TRUE;
                                             else return FALSE;
}

int operator<<( interval const& b, interval const& a )
{
    if ( a.start<b.start+EPS_jhm && b.end<a.end+EPS_jhm ) return TRUE;
                                             else return FALSE;
}

interval& operator&=( interval& a, interval const& b )
{
    if ( a<<b ) ;
    else if ( b<<a ) { a = b; }
    else if ( b.end<a.start ) { a *= 0.0; }
    else if ( a.end<b.start ) { a *= 0.0; }
    else if ( a.start<b.start ) { a.start = b.start; }
    else { a.end = b.end; }
                               
    return a;
}

interval operator&( interval const& a, interval const& b )
{
    interval c( 0.0 );

    if ( a<<b ) { c = a; }
    else if ( b<<a ) { c = b; }
    else if ( b.end<a.start ) { c *= 0.0; }
    else if ( a.end<b.start ) { c *= 0.0; }
    else if ( a.start<b.start ) { c.start = b.start; c.end = a.end; }
    else { c.start = a.start; c.end = b.end; }
                               
    return c;
}

int operator&&( interval const& a, interval const& b )
{
    if ( a.start-EPS_jhm > b.end || a.end+EPS_jhm < b.start ) return FALSE;
                                                 else return TRUE;
}

interval operator^( interval const& a, m_real b )
{
    return interval( a.start - b, a.end + b );
}

void adjust_interval( interval& a )
{
    if ( a.start > a.end )
    {
        m_real temp = a.start;
        a.start = a.end;
        a.end = temp;
    }
}

m_real
interval::project( m_real d ) const
{
    if ( this->start > d ) return this->start;
    if ( this->end < d ) return this->end;
    return d;
}

m_real
interval::distance( m_real d ) const
{
    if ( this->start > d ) return this->start - d;
    if ( this->end < d ) return d - this->end;
    return 0;
}

}


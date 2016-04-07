
#include "mathclass.h"

namespace jhm {

unit_vector x_axis( 1.0, 0.0, 0.0 );
unit_vector y_axis( 0.0, 1.0, 0.0 );
unit_vector z_axis( 0.0, 0.0, 1.0 );

unit_vector normalize( vector const& a )
{
    m_real s = len(a);

    if ( s != 0.0 )
        return unit_vector( a.p[0]/s, a.p[1]/s, a.p[2]/s );
    else
        return unit_vector( 0.0, 0.0, 0.0);
}

int equal_normal( unit_vector const& u, unit_vector const& v )
{
    if ( len(u-v) < EPS_jhm ) return TRUE;
                     else return FALSE;
}

std::ostream& operator<<( std::ostream& os, unit_vector const& a )
{
    os << "( " << a.p[0] << " , " << a.p[1] << " , " << a.p[2] << " )";
    return os;
}

std::istream& operator>>( std::istream& is, unit_vector& a )
{
	static char	buf[256];
    //is >> "(" >> a.p[0] >> "," >> a.p[1] >> "," >> a.p[2] >> ")";
	is >> buf >> a.p[0] >> buf >> a.p[1] >> buf >> a.p[2] >> buf;
    return is;
}


}
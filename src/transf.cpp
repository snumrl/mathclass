
#include "mathclass.h"

namespace jhm {

// Identity Transform

transf identity_transf( scaling(1), vector(0,0,0) );


// Inquiry Function

transf
transf::inverse() const
{
    matrix a = m.inverse();
    return transf( a, (-v)*a );
}

transf
inverse( transf const& t )
{
    return t.inverse();
}


// generator

transf scale_transf( m_real s )
{
    matrix m = scaling( s );
    vector v( 0.0, 0.0, 0.0 );
    return transf( m, v );
}

transf scale_transf( m_real sx, m_real sy, m_real sz )
{
    matrix m = scaling( sx, sy, sz );
    vector v( 0.0, 0.0, 0.0 );
    return transf( m, v );
}

transf rotate_transf( m_real angle, vector const& axis )
{
    matrix m = rotation( angle, axis );
    vector v( 0.0, 0.0, 0.0 );
    return transf( m, v );
}

transf reflect_transf( vector const& axis )
{
    matrix m = reflection( axis );
    vector v( 0.0, 0.0, 0.0 );
    return transf( m, v );
}

transf translate_transf( vector const& axis )
{
    return transf( scaling( 1.0 ), axis );
}

transf translate_transf( m_real x, m_real y, m_real z )
{
    return transf( scaling( 1.0 ), vector(x,y,z) );
}

transf coordinate_transf( position const& new_o,
                          unit_vector const& new_x,
                          unit_vector const& new_y )
{
    position o( 0.0, 0.0, 0.0 );
    vector x_axis( 1.0, 0.0, 0.0 );
    vector y_axis( 0.0, 1.0, 0.0 );
    vector z_axis( 0.0, 0.0, 1.0 );

    transf t1 = translate_transf( o - new_o );

    vector v1 = new_x;
    v1.set_x( 0.0 );
    m_real theta = ACOS( (v1 % z_axis) / len(v1) );
    transf t2 = rotate_transf( theta, x_axis );

    vector v2 = new_x;
    vector v3 = v2 * t2 * t1;
    theta = ACOS( (v3 % x_axis) / len(v3) );
    transf t3 = rotate_transf( theta, y_axis );

    vector v4 = new_y;
    vector v5 = v4 * t3 * t2 * t1;
    theta = ACOS( (v5 % y_axis) / len(v5) );
    transf t4 = rotate_transf( theta, x_axis );

    return t4 * t3 * t2 * t1;
}


std::ostream& operator<<( std::ostream& os, transf const& a )
{
    os << a.getAffine() << " + " << a.getTranslation();
    return os;
}

std::istream& operator>>( std::istream& is, transf& a )
{
	static char	buf[256];
    //is >> a.m >> "+" >> a.v;
	is >> a.m >> buf >> a.v;
    return is;
}

transf
interpolate( m_real t, transf const& a, transf const& b )
{
	matrix m = interpolate( t, a.getAffine(), b.getAffine() );
	vector v = interpolate( t, a.getTranslation(), b.getTranslation() );

    return transf( m, v );
}


}
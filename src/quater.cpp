
#include "mathclass.h"

namespace jhm {

static m_real eps = 0.0001;

quater operator-(quater const& a)
{
    return quater( -a.p[0], -a.p[1], -a.p[2], -a.p[3] );
}

quater inverse(quater const& a)
{
    return quater( a.p[0], -a.p[1], -a.p[2], -a.p[3] );
}

quater operator+ (quater const& a, quater const& b)
{
    quater c;
    for(int i = 0; i < 4; i++)
        c.p[i] = a.p[i] + b.p[i];
    return c;
}

quater operator- (quater const& a, quater const& b)
{
    quater c;
    for(int i = 0; i < 4; i++)
        c.p[i] = a.p[i] - b.p[i];
    return c;
}

quater operator* (m_real a, quater const& b)
{
    quater c;
    for(int i = 0; i < 4; i++)
        c.p[i] = a * b.p[i];
    return c;
}

quater operator* (quater const& a, m_real b)
{
    quater c;
    for(int i = 0; i < 4; i++)
        c.p[i] = a.p[i] * b;
    return c;
}

quater operator/ (quater const& a, m_real b) {
    quater c;
    for(int i = 0; i < 4; i++)
        c.p[i] = a.p[i] / b;
    return c;
}

m_real operator% (quater const& a, quater const& b)
{
    m_real c = 0;
    for(int i = 0; i < 4; i++)
        c += a.p[i] * b.p[i];
    return c;
}

quater operator* (quater const& a, quater const& b)
{
    quater c;
    c.p[0] = a.p[0]*b.p[0] - a.p[1]*b.p[1] - a.p[2]*b.p[2] - a.p[3]*b.p[3];
    c.p[1] = a.p[0]*b.p[1] + a.p[1]*b.p[0] + a.p[2]*b.p[3] - a.p[3]*b.p[2];
    c.p[2] = a.p[0]*b.p[2] + a.p[2]*b.p[0] + a.p[3]*b.p[1] - a.p[1]*b.p[3];
    c.p[3] = a.p[0]*b.p[3] + a.p[3]*b.p[0] + a.p[1]*b.p[2] - a.p[2]*b.p[1];
    return c;
}

matrix
quater::getMatrix()
{
	matrix m;
    m_real s, xs, ys, zs, wx, wy, wz, xx, xy, xz, yy, yz, zz;

    s  = 2.0/length();
    xs = x() * s;  ys = y() * s;  zs = z() * s;
    wx = w() * xs; wy = w() * ys; wz = w() * zs;
    xx = x() * xs; xy = x() * ys; xz = x() * zs;
    yy = y() * ys; yz = y() * zs; zz = z() * zs;

    m[0][0] = 1.0 - (yy + zz);
    m[1][0] = xy - wz;
    m[2][0] = xz + wy;
    m[0][1] = xy + wz;
    m[1][1] = 1.0 - (xx + zz);
    m[2][1] = yz - wx;
    m[0][2] = xz - wy;
    m[1][2] = yz + wx;
    m[2][2] = 1.0 - (xx + yy);

    return m;
}

void
quater::setMatrix( matrix const& m )
{
    quater q;

    m_real tr, s;
    int    i, j, k;
    static int next[3] = { 1, 2, 0 };

    tr = m.getValue(0,0) + m.getValue(1,1) + m.getValue(2,2);
    if ( tr > 0.0 )
    {
        s = sqrt( tr + 1.0 );
        q.p[0] = ( s * 0.5 );
        s = 0.5 / s;
        q.p[1] = ( m.getValue(1,2) - m.getValue(2,1) ) * s;
        q.p[2] = ( m.getValue(2,0) - m.getValue(0,2) ) * s;
        q.p[3] = ( m.getValue(0,1) - m.getValue(1,0) ) * s;
    }
    else
    {
        i = 0;
        if ( m.getValue(1,1) > m.getValue(0,0) ) i = 1;
        if ( m.getValue(2,2) > m.getValue(i,i) ) i = 2;

        j = next[i];
        k = next[j];

        s = sqrt( (m.getValue(i,i)
					- (m.getValue(j,j) + m.getValue(k,k))) + 1.0 );
        q.p[i+1] = s * 0.5;
        s = 0.5 / s;
        q.p[0]   = ( m.getValue(j,k) - m.getValue(k,j) ) * s;
        q.p[j+1] = ( m.getValue(i,j) + m.getValue(j,i) ) * s;
        q.p[k+1] = ( m.getValue(i,k) + m.getValue(k,i) ) * s;
    }

    (*this) = q;
}

matrix Quater2Matrix( quater const& q )
{
    matrix m;
    m_real s, xs, ys, zs, wx, wy, wz, xx, xy, xz, yy, yz, zz;

    s  = 2.0/len(q);
    xs = q.x() * s;  ys = q.y() * s;  zs = q.z() * s;
    wx = q.w() * xs; wy = q.w() * ys; wz = q.w() * zs;
    xx = q.x() * xs; xy = q.x() * ys; xz = q.x() * zs;
    yy = q.y() * ys; yz = q.y() * zs; zz = q.z() * zs;

    m.p[0][0] = 1.0 - (yy + zz);
    m.p[1][0] = xy - wz;
    m.p[2][0] = xz + wy;
    m.p[0][1] = xy + wz;
    m.p[1][1] = 1.0 - (xx + zz);
    m.p[2][1] = yz - wx;
    m.p[0][2] = xz - wy;
    m.p[1][2] = yz + wx;
    m.p[2][2] = 1.0 - (xx + yy);

    return m;
}

quater Matrix2Quater( matrix const& m )
{
    quater q;

    m_real tr, s;
    int    i, j, k;
    static int next[3] = { 1, 2, 0 };

    tr = m.getValue(0,0) + m.getValue(1,1) + m.getValue(2,2);
    if ( tr > 0.0 )
    {
        s = sqrt( tr + 1.0 );
        q.p[0] = ( s * 0.5 );
        s = 0.5 / s;
        q.p[1] = ( m.getValue(1,2) - m.getValue(2,1) ) * s;
        q.p[2] = ( m.getValue(2,0) - m.getValue(0,2) ) * s;
        q.p[3] = ( m.getValue(0,1) - m.getValue(1,0) ) * s;
    }
    else
    {
        i = 0;
        if ( m.getValue(1,1) > m.getValue(0,0) ) i = 1;
        if ( m.getValue(2,2) > m.getValue(i,i) ) i = 2;

        j = next[i];
        k = next[j];

        s = sqrt( (m.getValue(i,i)
					- (m.getValue(j,j) + m.getValue(k,k))) + 1.0 );
        q.p[i+1] = s * 0.5;
        s = 0.5 / s;
        q.p[0]   = ( m.getValue(j,k) - m.getValue(k,j) ) * s;
        q.p[j+1] = ( m.getValue(i,j) + m.getValue(j,i) ) * s;
        q.p[k+1] = ( m.getValue(i,k) + m.getValue(k,i) ) * s;
    }

    return q;
}

vector Quater2EulerAngle( quater const& q )
{
	return Matrix2EulerAngle( Quater2Matrix( q ) );
}

quater EulerAngle2Quater( vector const& v )
{
	return Matrix2Quater( EulerAngle2Matrix( v ) );
}

m_real len( quater const& v )
{
    return sqrt( v.p[0]*v.p[0] + v.p[1]*v.p[1] + v.p[2]*v.p[2] + v.p[3]*v.p[3] );
}

m_real
quater::length() const
{
    return sqrt( p[0]*p[0] + p[1]*p[1] + p[2]*p[2] + p[3]*p[3] );
}

quater
quater::normalize() const
{
	return (*this)/this->length();
}

std::ostream& operator<<( std::ostream& os, quater const& a )
{
    os << "( " << a.p[0] << " , " << a.p[1] << " , " << a.p[2] << " , " << a.p[3] << " )";
    return os;
}

std::istream& operator>>( std::istream& is, quater& a )
{
	static char	buf[256];
	//is >> "(" >> a.p[0] >> "," >> a.p[1] >> "," >> a.p[2] >> "," >> a.p[3] >> ")";
	is >> buf >> a.p[0] >> buf >> a.p[1] >> buf >> a.p[2] >> buf >> a.p[3] >> buf;
    return is;
}

quater exp(vector const& w)
{
    m_real theta = sqrt(w % w);
    m_real sc;

    if(theta < eps) sc = 1;
    else sc = sin(theta) / theta;

    vector v = sc * w;
    return quater(cos(theta), v.x(), v.y(), v.z());
}

quater pow(vector const& w, m_real a)
{
    return exp(a * w);
}

vector ln(quater const& q)
{
    m_real sc = sqrt(q.p[1] * q.p[1] + q.p[2] * q.p[2] + q.p[3] * q.p[3]);
    m_real theta = atan2(sc, q.p[0]);
    if(sc > eps)
        sc = theta / sc;
    else  sc = 1.0 ;
    return vector(sc * q.p[1], sc * q.p[2], sc * q.p[3]);
}

position rotate(quater const& a, position const& v)
{
    quater c = a * quater(0, v.x(), v.y(), v.z()) * inverse(a);
    return position(c.x(), c.y(), c.z());
}

vector rotate(quater const& a, vector const& v)
{
    quater c = a * quater(0, v.x(), v.y(), v.z()) * inverse(a);
    return vector(c.x(), c.y(), c.z());
}

unit_vector rotate(quater const& a, unit_vector const& v)
{
    quater c = a * quater(0, v.x(), v.y(), v.z()) * inverse(a);
    return unit_vector(c.x(), c.y(), c.z());
}

quater
slerp( quater const& a, quater const& b, m_real t )
{
	m_real c = a % b;

	if ( 1.0+c > EPS_jhm )
	{
		if ( 1.0-c > EPS_jhm )
		{
			m_real theta = acos( c );
			m_real sinom = sin( theta );
			return ( a*sin((1-t)*theta) + b*sin(t*theta) ) / sinom;
		}
		else
			return (a*(1-t) + b*t).normalize();
	}
	else	return a*sin((0.5-t)*M_PI) + b*sin(t*M_PI);
}

quater
interpolate( m_real t, quater const& a, quater const& b )
{
	return slerp( a, b, t );
}

m_real
distance( quater const& a, quater const& b )
{
	return MIN( ln( a.inverse()* b).length(),
				ln( a.inverse()*-b).length() );
}

vector
difference( quater const& a, quater const& b )
{
	return ln( b.inverse() * a );
}

}
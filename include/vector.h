// +-------------------------------------------------------------------------
// | vector.h
// | 
// | Author: Jehee Lee
// +-------------------------------------------------------------------------
// | COPYRIGHT:
// |    Copyright Jehee Lee 2013
// |    See the included COPYRIGHT.txt file for further details.
// |    
// |    This file is part of the MATHCLASS.
// |    MATHCLASS is free software: you can redistribute it and/or modify
// |    it under the terms of the MIT License.
// |
// |    You should have received a copy of the MIT License
// |    along with MATHCLASS.  If not, see <mit-license.org>.
// +-------------------------------------------------------------------------

#ifndef VECTOR_H
#define VECTOR_H

namespace jhm
{

class unit_vector;
class matrix;
class transf;

class vector
{
  private:
    m_real p[3];

    // negation
    friend vector      operator-( vector const& );
    friend unit_vector operator-( unit_vector const& );

    // addtion
    friend position& operator+=( position&, vector const& );
    friend vector&   operator+=( vector&, vector const& );
    friend vector    operator+( vector const&, vector const& );
    friend position  operator+( position const&, vector const& );
    friend position  operator+( vector const&, position const& );

    // subtraction
    friend vector    operator-( vector const&, vector const& );
    friend position  operator-( position const&, vector const& );
    friend position& operator-=( position&, vector const& );
    friend vector&   operator-=( vector&, vector const& );

    // dot product
    friend m_real    operator%( vector const&, vector const& );
    friend m_real    operator%( position const&, vector const& );
    friend m_real    operator%( vector const&, position const& );

    // cross product
    friend vector    operator*( vector const&, vector const& );
    friend position  operator*( position const&, unit_vector const& );
    friend position  operator*( unit_vector const&, position const& );

    // scalar Multiplication
    friend vector    operator*( vector const&, m_real );
    friend vector    operator*( m_real, vector const& );
    friend vector&   operator*=( vector&, m_real );

    // scalar Division
    friend vector    operator/( vector const&, m_real );
    friend m_real    operator/( vector const&, vector const& );
    friend vector&   operator/=( vector&, m_real );

    // matrix Multiplication
    friend vector    operator*( vector const&, matrix const& );
    friend vector    operator*( matrix const&, vector const& );

    friend vector&   operator*=( vector&, transf const& );
    friend vector    operator*( vector const&, transf const& );

    // functions
    friend m_real       len( vector const& );
    friend unit_vector  normalize( vector const& );
	friend vector       interpolate( m_real, vector const&, vector const& );


    friend m_real       angle( vector const&, vector const& );

    friend position     vector2position( vector const& );
    friend vector       position2vector( position const& );

    // stream
    friend std::ostream& operator<<( std::ostream&, vector const& );
    friend std::istream& operator>>( std::istream&, vector& );
    friend std::ostream& operator<<( std::ostream&, unit_vector const& );
    friend std::istream& operator>>( std::istream&, unit_vector& );

  public:
    // constructors
    vector() {}
    vector( m_real x, m_real y, m_real z ) { p[0]=x; p[1]=y; p[2]=z; }
    vector( m_real a[3] ) { p[0]=a[0]; p[1]=a[1]; p[2]=a[2]; }

    // inquiry functions
    m_real& operator[](int i) { return p[i]; }

    m_real x() const { return p[0]; };
    m_real y() const { return p[1]; };
    m_real z() const { return p[2]; };
    void   getValue( m_real d[3] ) { d[0]=p[0]; d[1]=p[1]; d[2]=p[2]; }
    void   setValue( m_real d[3] ) { p[0]=d[0]; p[1]=d[1]; p[2]=d[2]; }
	m_real getValue( int n ) const { return p[n]; }
	vector setValue( m_real x, m_real y, m_real z )
								   { p[0]=x, p[1]=y, p[2]=z; return *this; }
	m_real setValue( int n, m_real x )
								   { return p[n]=x; }

	m_real length() const;
	matrix cross() const;

	unit_vector normalize() const;

    // change functions
    void set_x( m_real x ) { p[0]=x; };
    void set_y( m_real x ) { p[1]=x; };
    void set_z( m_real x ) { p[2]=x; };
};

}
#endif

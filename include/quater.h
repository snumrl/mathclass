// +-------------------------------------------------------------------------
// | quater.h
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

#ifndef QUATER_H
#define QUATER_H

namespace jhm
{

class vector;

class quater
{
  private:
    m_real p[4];

    // negation
    friend quater    operator-( quater const& );

    // addtion
    friend quater    operator+( quater const&, quater const& );

    // subtraction
    friend quater    operator-( quater const&, quater const& );

    // dot product
    friend m_real    operator%( quater const&, quater const& );

    // Multiplication
    friend quater    operator*( quater const&, quater const& );

    // scalar Multiplication
    friend quater    operator*( quater const&, m_real );
    friend quater    operator*( m_real, quater const& );

    // scalar Division
    friend quater    operator/( quater const&, m_real );

    // transform with matrix
	matrix	getMatrix();
	void	setMatrix( matrix const& );

    friend matrix    Quater2Matrix( quater const& );
    friend quater    Matrix2Quater( matrix const& );
    friend vector    Quater2EulerAngle( quater const& );
    friend quater    EulerAngle2Quater( vector const& );

    // functions
    friend quater    exp( vector const& );
    friend quater    pow( vector const&, m_real );
    friend quater    inverse( quater const& );
    friend m_real    len( quater const& );
    friend vector    ln ( quater const& );
    friend position  rotate( quater const&, position const& );
    friend vector    rotate( quater const&, vector const& );
    friend unit_vector rotate( quater const&, unit_vector const& );
    friend quater    slerp( quater const&, quater const&, m_real );
    friend quater    interpolate( m_real, quater const&, quater const& );
    friend m_real    distance( quater const&, quater const& );
    friend vector    difference( quater const&, quater const& );

    // stream
    friend std::ostream& operator<<( std::ostream&, quater const& );
    friend std::istream& operator>>( std::istream&, quater& );

  public:
	//
    // constructors
	//
    quater() {};
    quater( m_real w, m_real x, m_real y, m_real z )
                          { p[0]=w; p[1]=x; p[2]=y; p[3]=z; }
    quater( m_real a[4] ) { p[0]=a[0]; p[1]=a[1]; p[2]=a[2]; p[3]=a[3]; }

	//
    // inquiry functions
	//
	m_real	real() const { return p[0]; }
	vector	imaginaries() const { return vector( p[1], p[2], p[3] ); }
    quater  inverse() const { return quater( p[0], -p[1], -p[2], -p[3] ); }
	quater  normalize() const;
	m_real  length() const;
    m_real& operator[] (int i) { return p[i]; }

    void getValue( m_real d[4] ) { d[0]=p[0]; d[1]=p[1]; d[2]=p[2]; d[2]=p[2]; }
    void setValue( m_real d[4] ) { p[0]=d[0]; p[1]=d[1]; p[2]=d[2]; p[2]=d[2]; }

    m_real w() const { return p[0]; }
    m_real x() const { return p[1]; }
    m_real y() const { return p[2]; }
    m_real z() const { return p[3]; }

	//
    // Set parameters
	//
    void set_w( m_real x ) { p[0]=x; }
    void set_x( m_real x ) { p[1]=x; }
    void set_y( m_real x ) { p[2]=x; }
    void set_z( m_real x ) { p[3]=x; }
};

}
#endif

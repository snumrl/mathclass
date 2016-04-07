// +-------------------------------------------------------------------------
// | box.h
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

#ifndef BOX_H
#define BOX_H

namespace jhm
{

class box
{
  private:
    interval x, y, z;
    
    // addtion
    friend box& operator+=( box&, vector const& );
    friend box  operator+( box const&, vector const& );
    friend box  operator+( vector const&, box const& );

    // subtraction
    friend box& operator-=( box&, vector const& );
    friend box  operator-( box const&, vector const& );

    // multiplication by scalar
    friend box& operator*=( box&, m_real );
    friend box  operator*( box const&, m_real );
    friend box  operator*( m_real, box const& );

    // division by scalar
    friend box& operator/=( box&, m_real );
    friend box  operator/( box const&, m_real );

    // inclusion operation
    friend int  operator>>( box const&, position );
    friend int  operator<<( position, box const& );

    // inclusion operation
    friend int  operator>>( box const&, box const& );
    friend int  operator<<( box const&, box const& );

    // or operation
    friend box& operator|=( box&, box const& );
    friend box  operator|( box const&, box const& );

    // and operation
    friend box& operator&=( box&, box const& );
    friend box  operator&( box const&, box const& );

    // logical-and operation
    friend int  operator&&( box const&, box const& );

    // expansion
    friend box  operator^( box const&, m_real );

    // stream
    friend std::ostream& operator<<( std::ostream&, box const& );
    friend std::istream& operator>>( std::istream&, box& );


  public:
    // constructors
    box()
        : x( 0.0 ), y( 0.0 ), z( 0.0 ) { };

    box( position const& a )
        : x( a.x() ), y( a.y() ), z( a.z() ) { };

    box( position const& a, position const& b )
        : x( a.x(), b.x() ),
          y( a.y(), b.y() ),
          z( a.z(), b.z() ) { };

    box( interval const& a, interval const& b, interval const& c )
        : x( a ), y( b ), z( c ) { };

    // inquiry functions
	interval x_range() const { return x; }
	interval y_range() const { return y; }
	interval z_range() const { return z; }

    position low() const
    { position p( x.start_pt(), y.start_pt(), z.start_pt() ); return p; };
    position high() const
    { position p( x.end_pt(), y.end_pt(), z.end_pt() ); return p; };

    vector project( const vector& ) const;
};

}
#endif

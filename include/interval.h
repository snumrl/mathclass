// +-------------------------------------------------------------------------
// | interval.h
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

#ifndef INTERVAL_H
#define INTERVAL_H

namespace jhm
{

class interval
{
  private:
    m_real start, end;
    
    // negation
    friend interval operator-( interval const& );

    // addtion
    friend interval& operator+=( interval&, m_real );
    friend interval  operator+( m_real, interval const& );
    friend interval  operator+( interval const&, m_real );

    // subtraction
    friend interval& operator-=( interval&, m_real );
    friend interval  operator-( interval const&, m_real );

    // multiplication by scalar
    friend interval& operator*=( interval&, m_real );
    friend interval  operator*( interval const&, m_real );
    friend interval  operator*( m_real, interval const& );

    // division by scalar
    friend interval& operator/=( interval&, m_real );
    friend interval  operator/( interval const&, m_real );

    // inclusion operation
    friend int   operator>>( interval const&, m_real );
    friend int   operator<<( m_real, interval const& );

    // inclusion operation
    friend int   operator>>( interval const&, interval const& );
    friend int   operator<<( interval const&, interval const& );

    // or operation
    friend interval& operator|=( interval&, interval const& );
    friend interval  operator|( interval const&, interval const& );

    // and operation
    friend interval& operator&=( interval&, interval const& );
    friend interval  operator&( interval const&, interval const& );

    // logical-and operation
    friend int       operator&&( interval const&, interval const& );

    // expansion
    friend interval  operator^( interval const&, m_real );

    // axiliary functions
    friend void adjust_interval( interval& );

    // stream
    friend std::ostream& operator<<( std::ostream&, interval const& );
    friend std::istream& operator>>( std::istream&, interval& );

  public:
    // constructors
    interval( ) { start = end = 0.0; }
    interval( m_real a ) { start = end = a; }
    interval( m_real a, m_real b ) { start = MIN(a,b);
                                     end   = MAX(a,b); }

    // inquiry functions
    m_real start_pt() const { return start; }
    m_real end_pt() const { return end; }
    m_real mid_pt() const { return (start+end)/2.0f; }

    m_real interpolate( m_real t ) const { return (1-t)*start + t*end; }
    m_real len( ) const { return end - start; }

	m_real distance( m_real ) const;
    m_real project( m_real ) const;
};

}
#endif

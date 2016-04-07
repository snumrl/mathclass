// +-------------------------------------------------------------------------
// | unit_vector.h
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

#ifndef UNIT_VECTOR_H
#define UNIT_VECTOR_H

namespace jhm
{

class matrix;
class transf;

class unit_vector : public vector
{
  private:
    // negation
    friend unit_vector    operator-( unit_vector const& );

    // cross product
    friend position  operator*( position const&, unit_vector const& );
    friend position  operator*( unit_vector const&, position const& );

    friend unit_vector& operator*=( unit_vector&, matrix const& );
    friend unit_vector  operator*( unit_vector const&, matrix const& );

    friend unit_vector& operator*=( unit_vector&, transf const& );
    friend unit_vector  operator*( unit_vector const&, transf const& );

    // functions
    friend int    equal_normal( unit_vector const&,
                                unit_vector const& );
    friend transf coordinate_transf( position const&,
                                     unit_vector const&,
                                     unit_vector const& );

  public:
    // constructors
    unit_vector() { };
    unit_vector( m_real x, m_real y, m_real z ) : vector( x, y, z ) { };
    unit_vector( m_real a[3] ) : vector( a ) { };
};

extern unit_vector x_axis, y_axis, z_axis;

}
#endif

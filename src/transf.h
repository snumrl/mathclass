// +-------------------------------------------------------------------------
// | transf.h
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

#ifndef TRANSF_H
#define TRANSF_H

namespace jhm
{

class quater;

class transf
{
  private:
    matrix m;
    vector v;

    // multiplication
    friend transf&      operator*=( transf &, transf const& );
    friend transf       operator*( transf const&, transf const& );
    friend vector&      operator*=( vector&, transf const& );
    friend vector       operator*( vector const&, transf const& );
    friend position&    operator*=( position&, transf const& );
    friend position     operator*( position const&, transf const& );
    friend unit_vector& operator*=( unit_vector&, transf const& );
    friend unit_vector  operator*( unit_vector const&, transf const& );

    // functions
    friend transf       inverse( transf const& );
    friend transf       interpolate( m_real, transf const&, transf const& );

    // stream
    friend std::ostream& operator<<( std::ostream&, transf const& );
    friend std::istream& operator>>( std::istream&, transf& );

  public:
    // constructors
    transf() {}
    transf( matrix const& a, vector const& b ) { m = a; v = b; }
    transf( quater const& a, vector const& b ) { m = Quater2Matrix(a); v = b; }

    // inquiry functions
    const matrix&	getAffine() const { return m; };
    const vector&	getTranslation() const { return v; };
	const quater	getRotation() const { return Matrix2Quater(m); }
	const matrix&	affine() const { return m; };
	const vector&	translation() const { return v; }
	const position  getPosition() const { return position(v.x(), v.y(), v.z()); }

	void			setAffine( matrix const& a ) { m = a; }
	void			setTranslation( vector const& a ) { v = a; }
	void			setRotation( quater const& q ) { m = Quater2Matrix(q); }

    transf			inverse() const;
};

// identity transform
extern transf identity_transf;

// generator
extern transf scale_transf( m_real );
extern transf scale_transf( m_real, m_real, m_real );
extern transf rotate_transf( m_real, vector const& );
extern transf reflect_transf( vector const& );
extern transf translate_transf( vector const& );
extern transf translate_transf( m_real, m_real, m_real );
extern transf coordinate_transf( position const&,
                  unit_vector const&, unit_vector const& );

}
#endif

// +-------------------------------------------------------------------------
// | vectorN.h
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

#ifndef VECTOR_N_H
#define VECTOR_N_H

namespace jhm
{

class matrixN;
class smatrixN;

class vectorN
{
  private:
    int     n,
			on;
    m_real *v;

    // stream
    friend std::ostream&  operator<<( std::ostream&, vectorN const& );
    friend std::istream&  operator>>( std::istream&, vectorN& );

    // dot product
    friend m_real    operator%( vectorN const&, vectorN const& );

  public:
     vectorN();
     vectorN( int );
     vectorN( int, m_real* );
    ~vectorN();

	void	  getValue( m_real* );
	m_real	  getValue( int i ) const { assert(i>=0 && i<n); return v[i]; }
	void	  setValue( m_real* );
	void	  setValue( int i, m_real d ) { assert(i>=0 && i<n); v[i] = d; }

    m_real&   operator[](int i) const { assert(i>=0 && i<n); return v[i]; }
    int       size() const { return n; }
    int       getSize() const { return n; }
    void      setSize( int );

    m_real    len() const ;
    m_real    length() const ;

    vectorN&  normalize();

    vectorN&  assign( vectorN const& );
    vectorN&  operator=( vectorN const& );

    vectorN&  negate();

    vectorN&  add( vectorN const&, vectorN const& );
    vectorN&  operator+=( vectorN const& );

    vectorN&  sub( vectorN const&, vectorN const& );
    vectorN&  operator-=( vectorN const& );

    vectorN&  mult( vectorN const&, m_real );
    vectorN&  operator*=( m_real );

    vectorN&  mult( matrixN const&, vectorN const& );
    vectorN&  mult( vectorN const&, matrixN const& );
    vectorN&  mult( smatrixN const&, vectorN const& );
    vectorN&  mult( vectorN const&, smatrixN const& );

    vectorN&  div( vectorN const&, m_real );
    vectorN&  operator/=( m_real );

	friend m_real	difference( vectorN const&, vectorN const& );

	// SOR (Successive Over Relaxation)
    vectorN&  solve( matrixN const&,  vectorN const&, int, m_real, m_real );

	// LU Decomposition
    vectorN&  solve( matrixN const&,  vectorN const& );

	// SVD (Singular Value Decomposition)
    vectorN&  solve( matrixN const&,  vectorN const&, m_real );

	// Preconditioned Conjugate Gradient
    vectorN&  solve( smatrixN const&, vectorN const& );
};

}
#endif

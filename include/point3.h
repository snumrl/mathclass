// +-------------------------------------------------------------------------
// | point3.h
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

#ifndef POINT3_H
#define POINT3_H

namespace jhm
{

class point3
{
private:
	int p[3];

	// negation
	friend point3    operator-( point3 const& );

	// addtion
	friend point3&   operator+=( point3&, point3 const& );
	friend point3    operator+( point3 const&, point3 const& );

	// subtraction
	friend point3    operator-( point3 const&, point3 const& );
	friend point3&   operator-=( point3&, point3 const& );

public:
	// constructors
	point3() {}
	point3( int x, int y, int z ) { p[0]=x; p[1]=y; p[2]=z; }
	point3( int a[3] ) { p[0]=a[0]; p[1]=a[1]; p[2]=a[2]; }

	// inquiry functions
	int& operator[](int i) { return p[i]; }

	int x() const { return p[0]; };
	int y() const { return p[1]; };
	int z() const { return p[2]; };
	void   getValue( int d[2] ) { d[0]=p[0]; d[1]=p[1]; d[2]=p[2]; }
	void   setValue( int d[2] ) { p[0]=d[0]; p[1]=d[1]; p[2]=d[2]; }
	int    getValue( int n ) const { return p[n]; }
	point3 setValue( int x, int y, int z )
								{ p[0]=x, p[1]=y; p[2]=z; return *this; }
	int    setValue( int n, int x )
								{ return p[n]=x; }


	m_real length() const;


	// change functions
	void set_x( int x ) { p[0]=x; };
	void set_y( int y ) { p[1]=y; };
	void set_z( int z ) { p[2]=z; };
};

}
#endif

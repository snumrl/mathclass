
#include "mathclass.h"

namespace jhm {

vectorN::vectorN()
{
	on = n = 0;
}

vectorN::vectorN( int x )
{
    on = n = x;
    if ( on>0 ) v = new m_real[n];
}

vectorN::vectorN( int x, m_real *a )
{
    on = n = x;
    v = new m_real[n];
	for( int i=0; i<n; i++ )
		v[i] = a[i];
}

vectorN::~vectorN()
{
    if ( on>0 ) delete[] v;
}

void
vectorN::setValue( m_real *d )
{
	for( int i=0; i<n; i++ )
		v[i] = d[i];
}

void
vectorN::getValue( m_real *d )
{
	for( int i=0; i<n; i++ )
		d[i] = v[i];
}

void
vectorN::setSize( int x )
{
	if ( on<x )
	{
		if ( on>0 ) delete[] v;
		v = new m_real[x];
		on = x;
	}
	n = x;
}

vectorN&
vectorN::operator=( vectorN const& a )
{
    vectorN &c = (*this);
    c.setSize( a.size() );

    for( int i=0; i<c.size(); i++ )
        c[i] = a[i];
    return c;
}

vectorN&
vectorN::assign( vectorN const& a )
{
    vectorN &c = (*this);
    c.setSize( a.size() );

    for( int i=0; i<c.size(); i++ )
        c[i] = a[i];
    return c;
}

vectorN&
vectorN::negate()
{
    vectorN &c = (*this);
    for( int i=0; i<c.size(); i++ )
        c[i] = -c[i];
    return c;
}

vectorN&
vectorN::add( vectorN const& a, vectorN const& b )
{
    vectorN &c = (*this);
    assert( a.size()==b.size() );
    c.setSize( a.size() );

    for( int i=0; i<a.size(); i++ )
        c[i] = a[i] + b[i];
    return c;
}

vectorN&
vectorN::operator+=( vectorN const& a )
{
    vectorN &c = (*this);
    assert( c.size()==a.size() );

    for( int i=0; i<c.size(); i++ )
        c[i] += a[i];
    return c;
}

vectorN&
vectorN::sub( vectorN const& a, vectorN const& b )
{
    vectorN &c = (*this);
    assert( a.size()==b.size() );
    c.setSize( a.size() );

    for( int i=0; i<a.size(); i++ )
        c[i] = a[i] - b[i];
    return c;
}

vectorN&
vectorN::operator-=( vectorN const& a )
{
    vectorN &c = (*this);
    assert( c.size()==a.size() );

    for( int i=0; i<a.size(); i++ )
        c[i] -= a[i];
    return c;
}

m_real
operator%( vectorN const& a, vectorN const& b )
{
    assert( a.size()==b.size() );

    m_real c=0;
    for( int i=0; i<a.size(); i++ )
        c += a[i] * b[i];
    return c;
}

vectorN&
vectorN::mult( vectorN const& b, m_real a )
{
    vectorN &c = (*this);
    c.setSize( b.size() );

    for( int i=0; i<c.size(); i++ )
        c[i] = b[i]*a;
    return c;
}

vectorN&
vectorN::operator*=( m_real a )
{
    vectorN &c = (*this);

    for( int i=0; i<c.size(); i++ )
        c[i] *= a;
    return c;
}

vectorN&
vectorN::div( vectorN const& b, m_real a )
{
    vectorN &c = (*this);
    c.setSize( b.size() );

    for( int i=0; i<c.size(); i++ )
        c[i] = b[i]/a;
    return c;
}

vectorN&
vectorN::operator/=( m_real a )
{
    vectorN &c = (*this);

    for( int i=0; i<c.size(); i++ )
        c[i] /= a;
    return c;
}

vectorN&
vectorN::mult( matrixN const& a, vectorN const& b )
{
    vectorN &c = (*this);
    assert( a.column()==b.size() );
    c.setSize( a.row() );

    for( int i=0; i<a.row(); i++ )
    {
        c[i] = 0;
        for( int k=0; k<b.size(); k++ )
            c[i] += a[i][k] * b[k];
    }

    return c;
}

vectorN&
vectorN::mult( vectorN const& b, matrixN const& a )
{
    vectorN &c = (*this);
    assert( a.row()==b.size() );
    c.setSize( a.column() );

    for( int i=0; i<a.column(); i++ )
    {
        c[i] = 0;
        for( int k=0; k<b.size(); k++ )
            c[i] += b[k] * a[k][i];
    }

    return c;
}

vectorN&
vectorN::mult( smatrixN const& a, vectorN const& b )
{
    vectorN &c = (*this);
    assert( a.size()==b.size() );
    c.setSize( a.size() );

    for (int i=0; i<c.getSize(); i++) c.setValue(i, 0);

    for (int i=0; i<c.getSize(); i++ )
    {
        for (entity* p = a.getRows(i).next; p; p = p->next)
        {
            // c[i] += a[i][j] * b[j]
            // c[j] += a[i][j] * b[i]

            c[i] += p->value * b[p->id];
            if (i != p->id) c[p->id] += p->value * b[i];
        }
    }

	return c;
}

vectorN&
vectorN::mult( vectorN const& b, smatrixN const& a )
{
    vectorN &c = (*this);
    assert( a.size()==b.size() );
    c.setSize( a.size() );

    for ( int i=0; i<c.getSize(); i++ ) c.setValue(i, 0);

    for ( int i=0; i<c.getSize(); i++ )
    {
        for (entity* p = a.getRows(i).next; p; p = p->next)
        {
            // c[j] += b[i] * a[i][j]
            // c[i] += b[j] * a[i][j]

            c[p->id] += b[i] * p->value;
            if (i != p->id) c[i] += b[p->id] * p->value;
        }
    }

	return c;
}

m_real
vectorN::length() const
{
    m_real c=0;
    for( int i=0; i<n; i++ )
        c += this->v[i]*this->v[i];
    return sqrt(c);
}

m_real
vectorN::len() const
{
	return this->length();
}

vectorN&
vectorN::normalize()
{
    vectorN &c = (*this);

    m_real l = this->len();
    for( int i=0; i<n; i++ )
        c[i] = c[i] / l;
    return c;
}

m_real difference( vectorN const& a, vectorN const& b )
{
	assert( a.getSize()==b.getSize() );

	m_real d = 0.0;
	for( int i=0; i<a.getSize(); i++ )
		d += (a.v[i] - b.v[i]) * (a.v[i] - b.v[i]);

	return d;
}

std::ostream& operator<<( std::ostream& os, vectorN const& a )
{
    for( int i=0; i< a.size(); i++ )
        os << a.v[i] << " ";

    return os;
}

std::istream& operator>>( std::istream& is, vectorN& a )
{
	for( int i=0; i< a.size(); i++ )
		is >> a.v[i];

    return is;
}


vectorN&
vectorN::solve( matrixN const& a, vectorN const& b, int num, m_real tolerance, m_real damp )
{
    vectorN &c = (*this);
    assert( a.row()==a.column() );
    assert( a.row()==b.size() );
    c.setSize( b.size() );

    int flag = TRUE;
    for( int i=0; i<num && flag; i++ )
    {
        flag = FALSE;
        for( int j=0; j<a.row(); j++ )
        {
            m_real r = b[j] - a[j]%c;
            c[j] += damp*r/a[j][j];
            if ( r>tolerance ) flag = TRUE;
        }
    }

    return c;
}


vectorN&
vectorN::solve( matrixN const& a, vectorN const& b )
{
    vectorN &c = (*this);
    assert( a.row()==a.column() );
    assert( a.row()==b.size() );

	int n = b.size();
    c.setSize( n );
	c.assign( b );

	static matrixN mat; mat.setSize( n, n );
	mat.assign( a );

	static int* index;
	static int index_count = 0;
	if ( index_count<n )
	{
		if ( index_count>0 ) delete[] index;
		index_count = n;
		if ( index_count>0 ) index = new int[index_count];
	}

	mat.LUdecompose( index );
	mat.LUsubstitute( index, c );

	return c;
}


vectorN&
vectorN::solve( matrixN const& a, vectorN const& b, m_real tolerance )
{
	int m = a.row();
	int n = a.column();

	assert( m >= n );
	assert( b.size()==m );

    vectorN &c = (*this);
    c.setSize( n );

	static matrixN u; u.setSize( m, n );
	static vectorN w; w.setSize( n );
	static matrixN v; v.setSize( n, n );

	u.assign( a );
	u.SVdecompose( w, v );

	int i, j;
	m_real s;
	static vectorN tmp; tmp.setSize( n );

	m_real wmax = 0.0f;
	for( j=0; j<n; j++ )
		if ( w[j] > wmax ) wmax = w[j];

	for( j=0; j<n; j++ )
		if ( w[j] < wmax * tolerance ) w[j] = 0.0f;

	for( j=0; j<n; j++ )
	{
		s = 0.0f;
		if ( w[j] )
		{
			for( i=0; i<m; i++ )
				s += u[i][j] * b[i];
			s /= w[j];
		}
		tmp[j] = s;
	}

	for ( j=0; j<n; j++ )
	{
		s = 0.0;
		for ( i=0; i<n; i++ )
			s += v[j][i] * tmp[i];
		c[j] = s;
	}

	return c;
}


}
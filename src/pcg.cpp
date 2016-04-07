
#include "mathclass.h"

namespace jhm {

#define	Etol	0.01
#define	Imax	200

vectorN&
vectorN::solve( smatrixN const& A, vectorN const& b)
{
	int	n = A.getSize();
	assert(n == this->getSize() && n == b.getSize());

	vectorN& x = *this;

	// r = b - A * x
	vectorN	t(n);	t.mult(A, x);
	vectorN	r(n);	r.sub(b, t);

	// m = diag(inverse(M))
	vectorN	m(n);
	for (int i = 0; i < n; i++)
	{
		m_real	value = A.getValue(i, i);

		assert(fabs(value) > EPS_jhm);

		m[i] = 1.0 / value;
	}

	// d = inverse(M) * r
	vectorN	d(n);
	for (int i = 0; i < n; i++)
		d[i] = m[i] * r[i];

	m_real	delta_new = r % d;
	m_real	delta_0 = delta_new;

	vectorN	q(n);
	vectorN	s(n);
	m_real	alpha;
	m_real	beta;
	m_real	delta_old;

	m_real	e2d = Etol * Etol * delta_0;	// stopping criterion
	for (int i = 0; i < Imax && delta_new > e2d; i++)
	{
		q.mult(A, d);

		alpha = delta_new / (d % q);

		t.mult(d, alpha);
		x.add(x, t);

		if (i % 50)	{ t.mult(q, alpha);
					  r.sub(r, t); }
		else		{ t.mult(A, x);
					  r.sub(b, t); }

		for (int j = 0; j < n; j++)
			s[j] =  m[j] * r[j];

		delta_old = delta_new;
		delta_new = r % s;
		beta = delta_new / delta_old;

		t.mult(d, beta);
		d.add(s, t);
	}

	return	(*this);
}

}
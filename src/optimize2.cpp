
#include "mathclass.h"

namespace jhm {

#define TOL 2.0e-4

int    ncom;
m_real (*nrfunc) (vectorN const&);
static vectorN pcom, xicom;

m_real f1dim(m_real x)
{
	static vectorN xt; xt.setSize(ncom);

	for (int j=0; j<ncom; j++)
		xt[j] = pcom[j] + x * xicom[j];
	m_real f = (*nrfunc) (xt);

	return f;
}

void linmin( vectorN &p, vectorN &xi, int n, m_real &fret, m_real (*func) (vectorN const&))
{
	m_real xx, xmin, fx, fb, fa, bx, ax;

	ncom = n;
	pcom.setSize(n);
	xicom.setSize(n);
	nrfunc = func;

	for (int j=0; j<n; j++)
	{
		pcom[j] = p[j];
		xicom[j] = xi[j];
	}
  
	ax = 0.0;
	xx = 1.0;
	mnbrak(ax, xx, bx, fa, fx, fb, f1dim);
	fret = brent(ax, xx, bx, f1dim, TOL, xmin);
  
	for (int j=0; j<n; j++)
	{
		xi[j] *= xmin;
		p[j] += xi[j];
	}
}

#define ITMAX 200

void gradient_descent(vectorN &p, int n, m_real ftol, int &iter, m_real &fret,
			m_real (*func)  (vectorN const&),
			m_real (*dfunc) (vectorN const&,vectorN&))
{
	m_real fp;
	static vectorN xi; xi.setSize(n);

	for (iter=0; iter<ITMAX; iter++)
	{
		fp = (*dfunc) (p, xi);

		linmin(p, xi, n, fret, func);
		if (2.0 * fabs(fret - fp) <= ftol * (fabs(fret) + fabs(fp) + EPS_jhm))
   	    	return;
	}

	error("Too many iterations in gradient_descent");
}
	
void frprmn(vectorN &p, int n, m_real ftol, int &iter, m_real &fret,
			m_real (*func)  (vectorN const&),
			m_real (*dfunc) (vectorN const&,vectorN&))
{
	m_real gg, gam, fp, dgg;

	static vectorN g;   g.setSize(n);
	static vectorN h;   h.setSize(n);
	static vectorN xi; xi.setSize(n);
  
	fp = (*dfunc) (p, xi);

	for (int j=0; j<n; j++)
	{
		g[j] = -xi[j];
		xi[j] = h[j] = g[j];
	}

	for (iter=0; iter<ITMAX; iter++)
	{
		linmin(p, xi, n, fret, func);
		if (2.0 * fabs(fret - fp) <= ftol * (fabs(fret) + fabs(fp) + EPS_jhm)) return;
		
		fp = (*dfunc) (p, xi);
		dgg = gg = 0.0;

		for (int j=0; j<n; j++)
		{
			gg += g[j] * g[j];
			dgg += (xi[j] + g[j]) * xi[j];
		}

		if (gg == 0.0) return;

		gam = dgg / gg;

		for (int j=0; j<n; j++)
		{
			g[j] = -xi[j];
			xi[j] = h[j] = g[j] + gam * h[j];
		}
	}

	error("Too many iterations in frprmn");
}

}
#undef ITMAX


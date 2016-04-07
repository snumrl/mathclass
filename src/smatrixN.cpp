//
// Sparse Matrix:	Aug 11, 1998
//

#include "mathclass.h"

namespace jhm {

void
smatrixN::allocate(int N)
{
	n = N;

	nnze = 0;

	rows = new entity[n];
	for (int i = 0; i < n; i++)
	{
		rows[i].id = HEAD_ENTITY;
		rows[i].value = MEANINGLESS;
		rows[i].next = NULL;
	}
}

void
smatrixN::deallocate()
{
	// deallocate memories for every non-zero entities
	entity*	curr;
	entity*	next;
	for (int i = 0; i < n; i++)
	{
		next = rows[i].next;
		while (next)
		{
			curr = next;
			next = curr->next;
			delete	curr;
		}
	}
	delete []	rows;

	rows = NULL; n = nnze = 0;
}

m_real
smatrixN::setValue(int row, int col, m_real value, entity** e)
{
	assert(0 <= row && row < n);
	assert(0 <= col && col < n);

	if (row > col)	{ int tmp = row; row = col; col = tmp; }

	// find A(row,col) entity
	for (entity* p = &rows[row]; p; p = p->next)
	{
		if (p->id == col)
		{
			m_real	old = p->value;
			p->value = value;
			if (e)	*e = p;

			return	old;
		}
		else if (!p->next || p->next->id > col)
		{
			nnze++;

			entity*	tmp = new entity;
			tmp->id = col;
			tmp->value = value;
			tmp->next = p->next;
			p->next = tmp;
			if (e)	*e = tmp;

			return	0;
		}
	}

	return	0;
}

m_real
smatrixN::getValue(int row, int col) const
{
	assert(0 <= row && row < n);
	assert(0 <= col && col < n);

	if (row > col)	{ int tmp = row; row = col; col = tmp; }

	// find A(row,col) entity
	for (entity* p = rows[row].next; p; p = p->next)
		if (p->id == col)	return	p->value;

	// A(row,col) entity is zero
	return	0;
}

m_real
smatrixN::add(int row, int col, m_real increment)
{
	entity*	e;
	m_real	old;
	
	old = setValue(row, col, 0, &e);
	e->value = old + increment;

	return	(old + increment);
}

m_real
smatrixN::sub(int row, int col, m_real decrement)
{
	entity*	e;
	m_real	old;

	old = setValue(row, col, 0, &e);
	e->value = old - decrement;

	return	(old - decrement);
}

std::ostream&
operator<<(std::ostream& os, smatrixN& A)
{
	os << A.n << " x " << A.n << " ";
	os << A.nnze << " non-zero sparse matrix " << std::endl;

	for (int i = 0; i < A.n; i++)
	for (entity* p = A.rows[i].next; p; p = p->next)
		os << " [ " << i << " , " << p->id << " ] = " << p->value << std::endl;
	os << std::endl;

	return	os;
}

std::istream&
operator>>(std::istream& is, smatrixN& A)
{
	static char	buf[256];

	int	nrow, ncol, nnze;

//	is >> nrow >> "x" >> ncol;
	is >> nrow >> buf >> ncol;
//	is >> nnze >> "non-zero" >> "sparse" >> "matrix";
	is >> nnze >> buf >> buf >> buf;

	assert(nrow == ncol);

	int	n = nrow;

	A.deallocate();
	A.allocate(n);

	int		row, col;
	m_real	value;
	for (int i = 0; i < nnze; i++)
	{
		//is >> "[" >> row >> "," >> col >> "]" >> "=" >> value;
		is >> buf >> row >> buf >> col >> buf >> buf >> value;

		if (fabs(value) > EPS_jhm)	A.setValue(row, col, value);
	}

	return	is;
}

}
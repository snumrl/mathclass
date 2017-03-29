// +-------------------------------------------------------------------------
// | smatrixN.h
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
//
// Sparse Matrix:	Aug 11, 1998
//

#ifndef	_SPARSE_MATRIX_H_
#define	_SPARSE_MATRIX_H_

#define	HEAD_ENTITY	-1
#define	MEANINGLESS	0

namespace jhm
{

struct	entity
{
	int		id;
	m_real	value;
	entity*	next;
};

class	vectorN;

class	smatrixN
{
public:
	smatrixN(int n)	{ allocate(n); }
	~smatrixN()	{ deallocate(); }

	int		size() const	{ return n; }
	int		getSize() const	{ return n; }

	void	allocate(int n);
	void	deallocate();

	m_real	setValue(int row, int col, m_real value, entity** e = NULL);
	m_real	getValue(int row, int col) const;

	entity  getRows( int i ) const { return rows[i]; }

	m_real	add(int row, int col, m_real increment);
	m_real	sub(int row, int col, m_real decrement);
	smatrixN& add( smatrixN& a, smatrixN& b);

	friend std::ostream& operator<<(std::ostream& os, smatrixN& A);
	friend std::istream& operator>>(std::istream& is, smatrixN& A);

private:
	int		n;		// n x n sparse matrix

	int		nnze;	// number of non-zero entity
	entity*	rows;
};

}
#endif	// _SPARSE_MATRIX_H_

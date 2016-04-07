// +-------------------------------------------------------------------------
// | optimize.h
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

#ifndef __OPTIMIZE_H
#define __OPTIMIZE_H

namespace jhm
{

void mnbrak(m_real&, m_real&, m_real&,
			m_real&, m_real&, m_real&, m_real (*func)(m_real)) ;

m_real brent(m_real, m_real, m_real,
			m_real (*f)(m_real), m_real, m_real&) ;

void linmin(vectorN&, vectorN&, int, m_real&, m_real (*func)(vectorN const&));

void gradient_descent(	vectorN&, int, m_real, int&, m_real&,
            m_real (*func)(vectorN const&),
            m_real (*dfunc)(vectorN const&, vectorN&));

void frprmn(vectorN&, int, m_real, int&, m_real&,
            m_real (*func)(vectorN const&),
            m_real (*dfunc)(vectorN const&, vectorN&));

void error( char* );

}
#endif

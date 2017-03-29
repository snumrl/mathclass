// +-------------------------------------------------------------------------
// | mathclass.h
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
#ifndef	_MATHCLASS_H_
#define	_MATHCLASS_H_

#include <iostream>
#include <math.h>
#include <assert.h>

typedef double m_real;

#ifndef	M_PI
#define	M_PI	3.14159265358979323846
#endif

extern m_real EPS_jhm;

#include "math_macro.h"

#include "position.h"
#include "vector.h"
#include "unit_vector.h"
#include "matrix.h"
#include "quater.h"

#include "point2.h"
#include "point3.h"

#include "transf.h"
#include "transq.h"

#include "complex.h"

#include "interval.h"
#include "box.h"

#include "vectorN.h"
#include "matrixN.h"
#include "smatrixN.h"

#include "optimize.h"

#endif	// _MATHCLASS_H_

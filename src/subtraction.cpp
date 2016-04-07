
#include "mathclass.h"

namespace jhm {

unit_vector operator-( unit_vector const& a )
{
    unit_vector b;

    b.p[0] = - a.p[0];
    b.p[1] = - a.p[1];
    b.p[2] = - a.p[2];

    return b;
}

vector operator-( vector const& a )
{
    vector b;

    b.p[0] = - a.p[0];
    b.p[1] = - a.p[1];
    b.p[2] = - a.p[2];

    return b;
}

position& operator-=( position& a, vector const& b )
{
    a.p[0] -= b.p[0];
    a.p[1] -= b.p[1];
    a.p[2] -= b.p[2];

    return a;
}

vector& operator-=( vector& a, vector const& b )
{
    a.p[0] -= b.p[0];
    a.p[1] -= b.p[1];
    a.p[2] -= b.p[2];

    return a;
}

vector operator-( vector const& a, vector const& b )
{
    vector c;

    c.p[0] = a.p[0] - b.p[0];
    c.p[1] = a.p[1] - b.p[1];
    c.p[2] = a.p[2] - b.p[2];

    return c;
}

vector operator-( position const& a, position const& b )
{
    return vector( a.p[0] - b.p[0], a.p[1] - b.p[1], a.p[2] - b.p[2] );
}

position operator-( position const& a, vector const& b )
{
    position c;

    c.p[0] = a.p[0] - b.p[0];
    c.p[1] = a.p[1] - b.p[1];
    c.p[2] = a.p[2] - b.p[2];

    return c;
}


}
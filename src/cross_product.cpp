
#include "mathclass.h"

namespace jhm {

position operator*( position const& a, unit_vector const& b )
{
    position c;

    c.p[0] = a.p[1]*b.p[2] - a.p[2]*b.p[1];
    c.p[1] = a.p[2]*b.p[0] - a.p[0]*b.p[2];
    c.p[2] = a.p[0]*b.p[1] - a.p[1]*b.p[0];

    return c;
}

position operator*( unit_vector const& b, position const& a )
{
    position c;

    c.p[0] = a.p[1]*b.p[2] - a.p[2]*b.p[1];
    c.p[1] = a.p[2]*b.p[0] - a.p[0]*b.p[2];
    c.p[2] = a.p[0]*b.p[1] - a.p[1]*b.p[0];

    return c;
}

vector operator*( vector const& a, vector const& b )
{
    vector c;

    c.p[0] = a.p[1]*b.p[2] - a.p[2]*b.p[1];
    c.p[1] = a.p[2]*b.p[0] - a.p[0]*b.p[2];
    c.p[2] = a.p[0]*b.p[1] - a.p[1]*b.p[0];

    return c;
}


}

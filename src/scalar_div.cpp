
#include "mathclass.h"

namespace jhm {

vector& operator/=( vector& a, m_real b )
{
    a.p[0] = a.p[0] / b;
    a.p[1] = a.p[1] / b;
    a.p[2] = a.p[2] / b;

    return a;
}

vector operator/( vector const& a, m_real b )
{
    vector c;

    c.p[0] = a.p[0] / b;
    c.p[1] = a.p[1] / b;
    c.p[2] = a.p[2] / b;

    return c;
}

m_real operator/( vector const& a, vector const& b )
{
    if ( b.p[0] > 0.0 ) return a.p[0]/b.p[0];
    if ( b.p[1] > 0.0 ) return a.p[1]/b.p[1];
    if ( b.p[2] > 0.0 ) return a.p[2]/b.p[2];
    return 0.0;
}

}

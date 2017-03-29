// +-------------------------------------------------------------------------
// | transq.h
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

#ifndef TRANSQ_H
#define TRANSQ_H

namespace jhm
{

class transq
{
  public:
    quater rotation;
    vector translation;

  private:
    // multiplication
    friend transq&      operator*=( transq &, transq const& );
    friend transq       operator* ( transq const&, transq const& );
    friend vector&      operator*=( vector&, transq const& );
    friend vector       operator* ( vector const&, transq const& );
    friend position&    operator*=( position&, transq const& );
    friend position     operator* ( position const&, transq const& );
    friend unit_vector& operator*=( unit_vector&, transq const& );
    friend unit_vector  operator* ( unit_vector const&, transq const& );

    // functions
    friend transq       interpolate( m_real, transq const&, transq const& );

    // stream
    friend std::ostream& operator<<( std::ostream&, transq const& );
    friend std::istream& operator>>( std::istream&, transq& );

  public:
    // constructors
    transq() {};
    transq( quater const& a, vector const& b ) { rotation=a; translation=b; }

    transq			inverse() const;
};

// identity transq
extern transq identity_transq;

}
#endif

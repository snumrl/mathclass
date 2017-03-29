#include <iostream>
#include "mathclass.h"
int main(int argc,char** argv)
{
	jhm::vector v0(0,1,2);
	jhm::position p0(5,2,7);
	jhm::position p1(-3,-7,3);

	jhm::matrix m0(
		1.0,1.0,1.0,
		0.0,1.0,0.0,
		0.0,0.0,1.0);


	std::cout<<"Matrix-vector multiplication"<<std::endl;
	std::cout<<"m0 : \n"<<m0<<std::endl;

	//Row-wise operation
	std::cout<<"v0*m0 : "<<v0*m0<<std::endl;
	//column-wise operation
	std::cout<<"m0*v0 : "<<m0*v0<<std::endl;

	std::cout<<std::endl;



	return 0;
}

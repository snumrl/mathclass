#include <iostream>
#include "mathclass.h"
int main(int argc,char** argv)
{
	jhm::position p0(0,1,2);
	jhm::position p1(5,2,7);
	jhm::position p2(-3,-7,3);
	jhm::vector v0(1,2.5,3);
	jhm::vector v1(-1,5,4.5);
	double c = 3.0;

	//(position)+(position) = (UNDEFINED)
	//std::cout<<p0<<" + "<<p1<<" = "<<p0+p1<<std::endl;
	
	//(vector)+-(vector) = (vector)
	std::cout<<"position, vector operation"<<std::endl;
	std::cout<<v0<<" + "<<v1<<" = "<<v0+v1<<std::endl;
	std::cout<<v0<<" - "<<v1<<" = "<<v0-v1<<std::endl;

	//(position)+-(vector) = (position)
	std::cout<<p0<<" + "<<v0<<" = "<<p0+v0<<std::endl;
	std::cout<<p0<<" - "<<v0<<" = "<<p0-v0<<std::endl;
	
	//(position)-(position) = (vector)
	std::cout<<p0<<" - "<<p1<<" = "<<p0-p1<<std::endl;

	//(scalar)*(vector) = (vector)
	std::cout<<c<<" * "<<v0<<" = "<<c*v0<<std::endl;
	std::cout<<std::endl;

	std::cout<<"Affine combination"<<std::endl;
	//sum(scalar)*(point) = (point)        if sum(scalar) = 1
	//                 = (vector)          if sum(scalar) = 0 : meaningless
	//	               = (UNDEFINED)       o.w.

	// p = 0.3*p0 + 0.7*p1
	std::cout<<"0.3*"<<p0<<" + 0.7*"<<p1<<" = "<<affineCombination(p0,p1,0.3)<<std::endl;

	// p = 0.1*p0 + 0.4*p1 + 0.5*p2
	std::cout<<"0.1*"<<p0<<" + 0.4*"<<p1<<" + 0.5*"<<p2<<" = "<<affineCombination(p0,p1,p2,0.1,0.4)<<std::endl;	

	jhm::position p[3] = {p0,p1,p2};
	double t[2] = {0.1,0.4};
	std::cout<<"0.1*"<<p0<<" + 0.4*"<<p1<<" + 0.5*"<<p2<<" = "<<affineCombination(3,p,t)<<std::endl;	


	std::cout<<std::endl;
	std::cout<<"operation"<<std::endl;

	std::cout<<"|p0| : "<<p0.norm()<<std::endl;
	std::cout<<"v0 (dot) v1 : "<<v0%v1<<std::endl;
	std::cout<<"v0 (cross) v1 : "<<v0*v1<<std::endl;
	std::cout<<"|p0 - p1| : "<<distance(p0,p1)<<std::endl;

	return 0;
}

#include <iostream>
#include "mathclass.h"
int main(int argc,char** argv)
{
	jhm::position p0(0,1,2);
	jhm::position p1(5,2,7);
	jhm::position p2(-3,-7,3);

	jhm::vector v0(1,0,0);
	jhm::vector v1(-1,5,4.5);

	double c1 = 3.0;
	double c2 = 1.0;
	
	jhm::quater q0(0.707,0.707,0.0,0.0);
	jhm::quater q1(0.0,0.0,0.707,0.707);
	
	std::cout<<"Quaternion operation"<<std::endl;

	//(quaternion)*(quaternion) = (UNDEFINED)
	//std::cout<<"q0 * q1 : "<<q0*q1<<std::endl;

	//exp(rotation)*exp(rotation) = exp(rotation)
	std::cout<<"exp(v0) * exp(v1) : "<<exp(v0)*exp(v1)<<std::endl;

	//(quaternion)*exp(rotation) = (quaternion)
	std::cout<<"q0 * exp(v1) : "<<q0*exp(v1)<<std::endl;

	//(quaternion)^-1*(quaternion) = exp(rotation)
	std::cout<<"q0^-1 * q1 : "<<q0.inverse()*q1<<std::endl;

	//log(quaternion) = (rotation)
	std::cout<<"log(q0) : "<<ln(q0)<<std::endl;



	std::cout<<std::endl;
	std::cout<<"Rotation operation"<<std::endl;
	std::cout<<"Matrix of q0 : "<<std::endl<<Quater2Matrix(q0)<<std::endl;

	std::cout<<"Rotate v0 with q0 : "<<rotate(q0,v0)<<std::endl;
	std::cout<<"Rotate v0 with q0 : "<<v0*Quater2Matrix(q0)<<std::endl<<std::endl;

	std::cout<<"Rotate v0 with axis : (0,0,1), angle = 0.5*pi"<<std::endl;
	double angle = 0.5*3.141592;
	jhm::vector axis(0.0,0.0,1.0);
	jhm::vector v = 0.5*angle*axis;
	jhm::quater v0_q(0.0,v0.x(),v0.y(),v0.z()); //Pure imaginaries
	jhm::quater q(cos(0.5*angle),axis.x()*sin(0.5*angle),axis.y()*sin(0.5*angle),axis.z()*sin(0.5*angle));

	//Below 4 operations are same operation.
	std::cout<<"rotate(exp(v),v0)                   : "<<rotate(exp(v),v0)<<std::endl;
	std::cout<<"v0*Quater2Matrix(exp(v))            : "<<v0*Quater2Matrix(exp(v))<<std::endl;
	std::cout<<"rotate(cos(angle),v*sin(angle),v0)  : "<<rotate(q,v0)<<std::endl;
	std::cout<<"q^-1*v0*q                           : "<<q*v0_q*inverse(q)<<std::endl;


	return 0;
}

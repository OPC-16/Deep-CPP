/* ---- structure in c++ ---- 
		  Author >_ OPC 
*/

/* In C++, structs are the containers which can hold data members and the methods which act on them,
   structs and classes are almost same, the difference is that in structs the default access specifier is public while in class it is
   private
   */

#include<iostream>
using namespace std;

struct hello {
	int mo_num;
	int ho_num;
	float hu;
}; //struct hello

int main() {
	hello var; 

	var.mo_num = 234;
	var.ho_num = 1234;
	var.hu = 345.23F;
   /* or we can also initialise it by 'hello var = {234, 1234, 345.23F}' */

	cout << "mo_num = " << var.mo_num
		 << ", ho_num = " << var.ho_num
		 << ", hu = " << var.hu << endl;
} //main

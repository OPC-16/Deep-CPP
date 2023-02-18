/* ---- classes and objects intro ---- 
		Author >_ OPC 
*/
#include<iostream>
using namespace std;

/* classes are basically kind of a blueprint of the real-world entites which consist of variables or data members and functions or 
 * methods which act on those members, 
 * And objects are the instantiation of classes i.e. they form the entites with the users can interact */

class smallobj {
	private:
		int somedata;
	public:
		void setdata(int d) {		//member function or a method which can access the private members of this class
			somedata = d;
		} // setdata 

		void showdata() {			//member function or a method
			cout << "data is " << somedata << endl;
		} // showdata
};

int main() {
	smallobj s1, s2;		//define 2 objects (or instances) of class smallobj

	s1.setdata(12332);		//the dot operator is also called as class member access operator
	s2.setdata(89);

	s1.showdata();
	s2.showdata();
} // main

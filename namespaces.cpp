/* ---- namespaces ---- 
		Author >_ OPC 
*/
#include<iostream>

namespace first {
   int x = 1;
}

namespace second {
   int x = 2;
}
/* namespace provides a solution for preventing name conflicts in large projects.
 * each entity needs a unique name. A namespace allows for identically named entites 
 * as long as the namespaces are different */

int main() {
   int x = 0;
	std::cout << x; 		//uses local version of entity (here int x)

	std::cout << first::x << std::endl;		//using x which is declared in 'first' namespace

	std::cout << second::x << std::endl;		//using x which is declared in 'second' namespace

	/* using namespace first;
	 * std::cout << x;			//then it will automatically use x from 'first' namespace
	 * std::cout << second::x; 	//we have to explicitly mention 'second' if using 'first'
	 * */

	/* using namespace std;
	 *
	 * it is valid but dangerous as there are many predefines entites in std namespace having common names
	 * so by mistake we can use them in our code and that can  create ambiguity
	 *
	 * so we can say -> 
	 * using std::cout;
	 * using std::cin;
	 * etc*/
} //function-main

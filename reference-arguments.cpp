/* ---- reference arguments to functions ---- 
		Author >_ OPC 
*/
#include<iostream>

/* passing variables as reference to functions is really useful
 * when we normally pass variables a copy is made for the function to operate on, this takes up memory and also has performance back
 * By passing variables as reference helps to modify the value at that address directly and also copies are not made.
 * 
 * when passing strings or arrays we generally pass them by reference to save up memory and not having to deal with performance lag
 *
 * check -> https://cplusplus.com/forum/beginner/17945/ <- for more info */

void someFunction(std::string& name, int age) {    //here, taking name string as reference
   std::cout << "Hello " << name << "\nYour age is " << age << std::endl;
} //function-someFunction

int main() {

   std::string name = "Harry Potter";
   someFunction(name, 20);
} //function-main

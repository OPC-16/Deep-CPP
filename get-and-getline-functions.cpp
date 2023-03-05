/* ---- taking white space as input ----
 *      Author >_ OPC
 */
#include <iostream>

/* the std::cin function doesn't take spaces as input and stops taking input when it encounters one, so we use the get and getline functions.
 * getline function is for std::string type strings and get is for C-type strings */

int main() {
   std::string fullName1;

   std::cout << "Enter your Full Name : ";
   std::getline(std::cin, fullName1);
   std::cout << "Hello there, " << fullName1 << std::endl;

   // std::getline(std::cin, fullName1, '$');   we can also specify a 3rd argument to getline, it will stop taking input when it 
   //                                           encounters '$' this character

   char fullName2[40];

   std::cout << "Again, enter your Full Name : ";
   std::cin.get(fullName2, 40);
   std::cout << "Hello again, " << fullName2 << std::endl;
} //function-main

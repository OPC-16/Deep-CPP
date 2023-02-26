/* ---- constructors and destructors ---- 
         Author >_ OPC
*/
#include <iostream>

/*constructors and destructors are special functions for objects
 * a constructor, also ctor gets called whenever an object is created of a class and can be used as per will
 *    1. default constructor -> used to set data members to zero or nullptr, etc
 *    2. parameterized ctor -> used to initialise the members with user defined arguments
 *    3. copy constructor -> used to make a copy of an object by coping all members of one obj to another objects' members
 *
 * a destructor gets called whenever scope of an object ends and usually used to free the heap allocated memory of data members 
 *
 * constructors and destructors have same name of that of class, only for destructor it is prefixed with tilda (~) 
 
 For more info on constructors -> https://en.cppreference.com/w/cpp/language/constructor 
 For more info on destructors -> https://en.cppreference.com/w/cpp/language/destructor
 */

class entity {
private:
   int m_data;

public:
   entity() {        //default constructor
      m_data = 0;
   }

   entity(int num) :          //parameterized constructor
         m_data(num)
   { }

   entity(entity& otherEntity) {    //copy constructor
      m_data = otherEntity.m_data;
   }

   ~entity() {                //destructor
      std::cout << "entity class object destroyed !\n";
      //if any heap allocated members, delete statements should be in destructor
   }

}; //class entity

int main() {
   entity entityObject_1;     //calls default constructor
   entity entityObject_2(98); //calls parameterized constructor
   entity entityObject_3 (entityObject_2);      //calls copy constructor 

   //when this main function ends the destructors for these objects will be automatically called

} //function-main

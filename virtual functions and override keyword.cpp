/* ---- virtual functions ---- 
        Author >_ OPC 
*/
#include<iostream>

/* use virtual and override in pairs,
 * if have a method in base class and in a derived class we want to override that method
 * by having same name as in base class,
 * we use 'virtual' keyword in base class and 'override' in derived class*/

/* virtual functions are maintained in a V-table,
 * where all virtual functions are correctly mapped to their overriden parts in derived classes*/

/* virtual functions come at a cost -
 * 1. extra memory for the V-table
 * 2. and a bit slow performance whenever we call a virtual func it has to check the V-table */

class entity {
public:
   virtual std::string getName() {
      return "entity";
   } //getName
}; //class entity

class player : public entity {
private:
   std::string m_name;
public:
   player(const std::string& name) : m_name(name) {}

   std::string getName() override {      // see base class also has the same name for this method
      return m_name;
   } //getName
}; //class player <- entity 

void printName(entity* entity) {
   std::cout << entity->getName() << std::endl;
} //printName-function

int main() {
   entity* e = new entity;
   printName(e);

   player* p = new player("hello");
   printName(p);
} //main-function

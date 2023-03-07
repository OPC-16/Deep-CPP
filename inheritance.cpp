/* ---- inheritance ----
 *      Author >_ OPC
 */
#include <iostream>

/*inheritance is where a class can access the data members and methods of another class, here entity is base and player is derived class
 * derived class can only access the public and protected data members of base class
 *
 * also, if we don't specify a constructor, the derived class will use an appropriate constructor from the base class
 *
 * calling base constructor from derived class's ctor ->
 *    class derived : public base {
 *       public :
 *          derived() : base() { //some code }
 *    };
 *
 * C++ supports five types of inheritance:
    Single inheritance
    Multiple inheritance
    Hierarchical inheritance
    Multilevel inheritance
    Hybrid inheritance

For more info -> https://cplusplus.com/doc/tutorial/inheritance/
*/

class entity {
private:
   int someVariable;    //this can't be accessed by the player class
protected:
   int entityHealth;
public:
   void show() {
      //some code
   } //function-show
}; //class-entity

class player : public entity {
private:
   std::string playerAbility;
public:
   player (const std::string& ability, int health = 100) :
      playerAbility(ability) { 
      entityHealth = health;
   } //function-player 

   void printInfo() {
      std::cout << "--- player stats ---\n";
      std::cout << "Health = " << entityHealth << std::endl;
      std::cout << "Ability = " << playerAbility << std::endl;
   } //function-printInfo
}; //class player

int main() {
   player p1("Possesses Invisibility Cloak", 98);

   p1.printInfo();
   p1.show();

   /*here, the player classes inherits the properties of entity class*/
} //function-main

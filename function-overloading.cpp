/* ---- overloading of functions ---- 
		Author >_ OPC 
*/
#include<iostream>
using namespace std;

/* function overloading is a type of polymorphism, where the name of functions remains same only types of arguments change 
   polymorphism means one thing having many forms,

   functions may have different number of arguments or different types of arguments or different return type to make them differ 
   from each other */

//for more info -> https://cplusplus.com/doc/tutorial/functions2/

void rechar();
void rechar(char);
void rechar(char, int);

int main() {

	rechar();
	rechar('=');
	rechar('*', 30);

} // main

void rechar() {
	for (int i=0; i<45; i++)
		cout << '*';
	cout << endl;
} // rechar

void rechar(char ch) {
	for(int j=0; j<45; j++)
		cout << ch;
	cout << endl;
} // rechar

void rechar(char ch, int n) {
	for(int i=0; i<n; i++)
		cout << ch;
	cout << endl;
} // rechar

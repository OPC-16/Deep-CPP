#include <iostream>
#include <thread>

void func(int x) {
   std::cout << "hello from func thread\n";
   std::cout << "arg is: " << x << std::endl;
} //function-func

int main() {
   std::thread myThread(&func, 23);    //this creates a thread which takes a function pointer and its args
   myThread.join();     //this waits for myThread to be joined to main thread again and then only exit the main function
   
   std::cout << "hello from main thread\n";
}

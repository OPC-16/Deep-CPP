#include <iostream>
#include <thread>
#include <vector>

         //jthreads are c++20 feature
         //so compile this with -std=c++20
/*the jthreads are joined automatically, if we create a thread from main func so whenever the scope of main is ending this thread is 
 * automatically joined*/

void func(int x) {
   std::cout << "This is " << std::this_thread::get_id() << " thread\n";
   std::cout << "value of data is: " << x << std::endl;
} //function-func

int main() {
   std::jthread autoJoinThread(&func, 29);
} //function-main

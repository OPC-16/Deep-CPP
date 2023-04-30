#include <iostream>
#include <thread>
#include <vector>

void func(int x) {
   std::cout << "hello from thread " << std::this_thread::get_id() << std::endl;
   std::cout << "arg is: " << x << std::endl;
} //function-func

int main() {
   std::vector<std::thread> threads;

   for (int i=0; i<10; i++) {
      threads.push_back(std::thread(&func, i));
   } //for-loop
   
   for (int i=0; i<10; i++) {
      threads[i].join();
   } //for-loop
   std::cout << "hello from main thread\n";

   /* we get jumbled output as the threads are not synchronised*/
}

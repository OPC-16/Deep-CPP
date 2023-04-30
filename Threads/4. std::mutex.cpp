#include <iostream>
#include <thread>
#include <vector>
#include <mutex>  //mutual exclusion

std::mutex Lock;

static int sharedValue = 0;

void incrementSharedValue() {
   Lock.lock();   //locks the mutex and blocks other threads from entering this section
   sharedValue++;
   Lock.unlock(); //unlocks the mutex
} //function-increamentSharedValue

int main() {
   std::vector<std::thread> threads;

   for (int i=0; i<10; i++) {
      threads.push_back(std::thread(&incrementSharedValue));
   } //for-loop
   
   for (int i=0; i<10; i++) {
      threads[i].join();
   } //for-loop

   std::cout << "sharedValue :" << sharedValue << std::endl;
}

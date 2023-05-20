#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <atomic>

/* atomic variables and operations don't need locks, these operations are indivisible and are performed in one go */

static std::atomic<int> sharedValue(0);
//static std::atomic_int sharedValue(0);  //here we have used type alias for std::atomic<int> which is std::atomic_int

void incrementSharedValue() {
   sharedValue++;
} //function-incrementSharedValue

int main() {
   std::vector<std::thread> threads;

   for (int i=0; i<10; i++) {
      threads.push_back(std::thread(&incrementSharedValue));
   }

   for (int i=0; i<10; i++) {
      threads[i].join();
   }

   std::cout << "sharedValue: " << sharedValue << std::endl;
} //function-main

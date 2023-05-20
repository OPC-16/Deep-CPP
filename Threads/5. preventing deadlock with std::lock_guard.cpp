#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

/* we have to lock a mutex and then unlock that mutex, but we can forget to do it, so we use lock_guard 
 *
 * class lock_guard is a mutex wrapper, it takes ownership of the mutex and takes care of it's constructor and destructor */

/* there are many mutex wrappers like lock_guard, unique_lock, scoped_lock */

std::mutex glock;
static int sharedValue = 0;

void incrementSharedValue() {
   std::lock_guard<std::mutex> lockGuard(glock);

   sharedValue++;

   /* when lockGuard goes out-of-scope it unlocks the mutex */

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

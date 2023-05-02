/* ---- explicit specialization error ---- 
		Author >_ OPC 
*/
#include <iostream>

class notAllowed {
   public:
      template<typename T>
      void func() {
      }

      //when we compile this class we get error of EXPLICIT SPECIALIZATION, coz we cannot put template specialization like following in 
      //same class scope in which they are declared
      template<>
      void func<int>() {

      }

      template<>
      void func<char>() {

      }
};

class Allowed {
   public:
      template<typename T>
         void fun() {
         }
};

//following template specialization is ALLOWED, as this is an extension (not C++ standard) to explicitly define template-specializations 
//without namespacing
template<>
inline void Allowed::fun<float> () { }

template<>
inline void Allowed::fun<unsigned char> () { }

int main() {
}

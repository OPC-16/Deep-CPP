#include <iostream>

// Template function to find the maximum of two values
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    int num1 = 10, num2 = 20;
    float float1 = 3.14, float2 = 2.71;

    // Calling the max function with integers
    int maxInt = max(num1, num2);
    std::cout << "Maximum of " << num1 << " and " << num2 << " is " << maxInt << std::endl;

    // Calling the max function with floats
    float maxFloat = max(float1, float2);
    std::cout << "Maximum of " << float1 << " and " << float2 << " is " << maxFloat << std::endl;

    return 0;
}

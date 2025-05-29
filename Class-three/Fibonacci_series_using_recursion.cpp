#include <iostream>

using namespace std;

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    int number;
    cout << "Enter your number : ";
    cin >> number;
    int result = fibonacci(number);
    cout << "Fibonacci of " << number << " is " << result << endl;
    return 0;
}
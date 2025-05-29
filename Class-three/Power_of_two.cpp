#include <iostream>

using namespace std;

bool powerOfTwo(double n) {
    if (n == 1) return true;
    if (n < 1) return false;

    return powerOfTwo(n/2.0);
}

int main() {
    int number;
    int result;

    cout << "Enter your number : ";
    cin >> number;

    result = powerOfTwo(number);

    if(result) {
        cout << true << endl;
    } else {
        cout << false << endl;
    }

    return 0;
}
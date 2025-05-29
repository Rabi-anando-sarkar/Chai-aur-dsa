#include <iostream>

using namespace std;

bool powerOfFour(double n) {
    if (n == 1) return true;
    if (n < 1) return false;

    return powerOfFour(n/4.0);
} 

int main() {
    int number;
    int result;

    cout << "Enter your number : ";
    cin >> number;

    result = powerOfFour(number);

    if(result) {
        cout << true << endl;
    } else {
        cout << false << endl;
    }

    return 0;
}
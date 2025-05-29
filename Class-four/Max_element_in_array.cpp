#include <iostream>

using namespace std;

int main () {
    int arr[7] = {3,7,0,45,12,-8,-9};
    int largest = arr[0];

    for(int i=0;i <= 7; i++) {
        if(arr[i] > largest) {
            largest = arr[i];
        }
    }

    cout << "Largest number : " << largest << endl;

    return 0;
}
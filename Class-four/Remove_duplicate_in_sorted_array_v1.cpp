#include <iostream>

using namespace std;

int removeDuplicate(int arr[], int n) {
    int k = 1;
    int temp[n];
    temp[0] = arr[0];
    for(int i=1;i<n;i++) {
        if(arr[i] == arr[i-1]) {
            continue;
        } else {
            temp[k] = arr[i];
            k++;
        }
    }
    for(int i=0;i<k;i++) {
        arr[i] = temp[i];
    }
    return k;
}

int main() {
    int num[] = {1,1,1,2,2,3,3,3,4,4,4,5,5};
    int result = removeDuplicate(num, 13);

    cout << "Number of unique elements : " << result << endl;
    return 0;
}
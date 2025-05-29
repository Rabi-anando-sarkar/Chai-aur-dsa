#include <iostream>

using namespace std;

int removeDuplicate(int arr[], int n) {
    int k = 1;

    for(int i=1;i<n;i++) {
        if(arr[i] != arr[k-1]){
            arr[k] = arr[i];
            k++;
        }
    }
    return k;
}

int main() {
    int num[] = {1,1,1,2,2,3,3,3,4,4,4,5,5};
    int result = removeDuplicate(num, 13);

    cout << "Number of unique elements : " << result << endl;
    return 0;
}
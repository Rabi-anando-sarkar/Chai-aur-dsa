#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int> arr1, int m, vector<int> arr2, int n) {
    int k = m+n-1;
    int i = m-1;
    int j = n-1;

    while(i>=0 && j>=0) {
        if(arr1[i] > arr2[j]) {
            arr1[k] = arr1[i];
            i--;
        } else {
            arr1[k] = arr2[j];
            j--;
        }
        k--;
    }

    while(j>=0) {
        arr1[k] = arr2[j];
        j--;
        k--;
    }

    return arr1;
}

int main() {
    vector<int> num1 = {1,2,3,0,0,0};
    vector<int> num2 = {2,5,6};
    int m = 3;
    int n = 3;
    
    vector<int> arr = merge(num1,m,num2,n);

    for(int i=0; i < arr.size() ; i++) {
        cout << arr[i] << '\t';
    }

    
    return 0;
}
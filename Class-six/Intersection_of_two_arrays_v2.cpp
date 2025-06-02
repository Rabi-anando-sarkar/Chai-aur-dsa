#include <iostream>
#include <vector>

using namespace std;

bool isPresent(const vector<int>& result, int value) {
    for(int num: result) {
        if(num == value) {
            return true;
        }
    }
    return false;
}

vector<int> findIntersection(vector<int>& nums1, vector<int>& nums2) {
    
    vector<int> result; 

    for(int i=0; i<nums1.size(); i++) {
        for(int j=0; j<nums2.size(); j++) {
            if(nums1[i] == nums2[j]) {
                if(!isPresent(result, nums1[i])) {
                    result.push_back(nums1[i]);
                }
                break;
            }
        }
    }

    return result;
}

int main() {
    vector<int> arr1 = {4,9,5};
    vector<int> arr2 = {9,4,9,8,4};
    vector<int> result = findIntersection(arr1,arr2);

    for(int n: result) {
        cout << n << "\t";
    }
    return 0;
}
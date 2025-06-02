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
    int maxElem = nums1[0];

    for(int i=1; i <nums1.size() ; i++) {
        if(nums1[i] > maxElem) {
            maxElem = nums1[i];
        }
    }

    for(int i=0; i <nums2.size() ; i++) {
        if(nums2[i] > maxElem) {
            maxElem = nums2[i];
        }
    }

    vector<int> hash(maxElem+1,0);

    for(int i=0; i<nums1.size(); i++) {
        hash[nums1[i]]++;
    }

    vector<int> result;

    for(int i=0;i<nums2.size();i++) {
        hash[nums2[i]]++;
    }

    for(int i=0; i<hash.size() ; i++ ) {
        if(hash[i] >= 2) {
            result.push_back(i);
            hash[i] = 0;
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
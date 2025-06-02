#include <iostream>
#include <vector>

using namespace std;

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
        hash[nums1[i]] = 1;
    }

    vector<int> result;

    for(int i=0;i<nums2.size();i++) {
        int val = nums2[i];
        if(val <= maxElem && hash[val] == 1) {
            result.push_back(val);
            hash[val] = -1;
        }
    }

    return result;
}

int main() {
    vector<int> arr1 = {4,9,5};
    vector<int> arr2 = {9,4,9,8,4};
    findIntersection(arr1,arr2);
    return 0;
}
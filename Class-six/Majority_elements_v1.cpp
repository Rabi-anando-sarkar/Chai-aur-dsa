#include <iostream>
#include <vector>

using namespace std;

int majorElem(vector<int>& nums) {

    int maxElem = nums[0];

    for(int i=1; i<nums.size(); i++){
        if(nums[i] > maxElem) {
            maxElem = nums[i];
        }
    }
    
    vector<int> hash(maxElem+1,0);
    int major = nums.size()/2;

    for(int i=0; i<nums.size() ; i++) {
        hash[nums[i]]++;
    }

    for(int i=0; i<hash.size() ; i++) {
        if(hash[i] > major) {
            return i;
        }
    }

    return -1;
}

int main() {
    vector<int> arr = {3,2,3};
    int result = majorElem(arr);
    cout << result << endl;
    return 0;
}
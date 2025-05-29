#include <iostream>
#include <vector>

using namespace std;

int removeDuplicate(vector<int>& nums) {
    vector<int> arr;
    int k = 1;
    arr.push_back(nums[0]);

    for(int i=1;i<nums.size();i++) {
        if(nums[i] == nums[i-1]) {
            continue;
        } else {
            arr.push_back(nums[i]);
            k++;
        }
    }

    nums.assign(arr.begin(), arr.end());

    return k;
}

int main() {
    vector<int> num = {1,1,1,2,2,3,3,3,4,4,4,5,5};
    int result = removeDuplicate(num);

    cout << "Number of unique elements : " << result << endl;
    return 0;
}
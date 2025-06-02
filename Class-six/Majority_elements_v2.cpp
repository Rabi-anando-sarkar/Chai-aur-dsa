#include <iostream>
#include <vector>

using namespace std;

int majorElem(vector<int>& nums) {
    int candidate = nums[0];
    int count = 1;

    for(int i=1; i<nums.size(); ++i) {
        if(nums[i] == candidate) {
            ++count;
        } else {
            --count;
            if(count == 0) {
                candidate = nums[i];
                count = 1;
            }
        }
    }
    return candidate;
}

int main() {
    vector<int> arr = {1,1,3,2,2,2,2,3,2,2,2};
    int result = majorElem(arr);
    cout << result << endl;
    return 0;
}
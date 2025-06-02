#include <iostream>
#include <vector>

using namespace std;

void moveZeores(vector<int>& nums) {
    int i=0;
    for(int j=0; j<nums.size(); j++) {
        if(nums[j] != 0) {
            nums[i] = nums[j];
            i++;
        }
    }

    for(; i<nums.size() ;i++) {
        nums[i] = 0;
    }
}

int main() {
    vector<int> arr = {0,1,0,3,12};
    return 0;
}
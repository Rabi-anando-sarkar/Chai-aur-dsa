#include <iostream>
#include <vector>

using namespace std;

int removeDuplicate(vector<int>& vec) {
    int k = 1;

    for(int i=1;i<vec.size();i++) {
        if(vec[i] != vec[k-1]){
            vec[k] = vec[i];
            k++;
        }
    }
    return k;
}

int main() {
    vector<int> num {1,1,1,2,2,3,3,3,4,4,4,5,5};
    int result = removeDuplicate(num);

    cout << "Number of unique elements : " << result << endl;
    return 0;
}
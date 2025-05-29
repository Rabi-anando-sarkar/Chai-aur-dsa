#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& vec) {
    for(int i = vec.size()-1; i>=0; i--) {
        if(vec[i] < 9) {
            vec[i]++;
            return vec;
        } else {
            vec[i] = 0;
        }
    }
    vec.insert(vec.begin(),1);
    return vec;
}

int main() {
    vector <int> num = {9,9,9,9};
    vector <int> result = plusOne(num);

    cout << "New Array : ";
    for(int num : result) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}
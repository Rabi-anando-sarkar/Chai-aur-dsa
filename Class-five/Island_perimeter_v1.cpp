#include <iostream>
#include <vector>

using namespace std;

int islandPerimeter(vector<vector<int>>& iGrid) {
    int perimeter = 0;
    int rows = iGrid.size();
    int cols = iGrid[0].size();

    for(int i = 0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            if(iGrid[i][j] == 1) {
                perimeter+=4;
                if(i < rows-1 && iGrid[i+1][j] == 1) {
                    perimeter-=2;
                }
                if(j < cols-1 && iGrid[i][j+1] == 1) {
                    perimeter-=2;
                }
            }
        }
    }

    return perimeter;
}

int main() {
    vector<vector<int>> grid = {
    {1, 0, 0, 0, 1},
    {1, 0, 1, 0, 1},
    {0, 0, 1, 0, 0},
    {1, 1, 0, 1, 1}
};

    int result = islandPerimeter(grid);

    cout << "Perimeter of the island is : " << result << endl;

    return 0;
}
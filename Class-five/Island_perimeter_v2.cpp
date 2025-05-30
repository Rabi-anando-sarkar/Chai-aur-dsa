#include <iostream>
#include <vector>

using namespace std;

int islandPerimeter(vector<vector<int>>& iGrid) {
    int p = 0;
    int rows = iGrid.size();
    int cols = iGrid[0].size();

    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            if(iGrid[i][j] == 1) {
                if(j==0 || iGrid[i][j-1] == 0) p++; // left
                if(j==cols-1 || iGrid[i][j+1] == 0) p++; // right
                if(i==0 || iGrid[i-1][j] == 0) p++; //top
                if(i==rows-1 || iGrid[i+1][j] == 0) p++; //bottom
            }
        }
    }

    return p;
}

int main() {
    vector<vector<int>> grid = {
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0}
    };

    int result = islandPerimeter(grid);

    cout << "Perimeter of the island is : " << result << endl;
}
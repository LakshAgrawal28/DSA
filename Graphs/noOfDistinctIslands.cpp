#include <iostream>
#include <vector>
#include <set>
using namespace std;

void dfs(int row, int col, int baseRow, int baseCol,
         vector<vector<int>>& grid,
         vector<vector<int>>& vis,
         vector<pair<int,int>>& shape) {

    int n = grid.size();
    int m = grid[0].size();

    vis[row][col] = 1;
    shape.push_back({row - baseRow, col - baseCol});

    int delRow[] = {-1, 1, 0, 0};
    int delCol[] = {0, 0, -1, 1};

    for(int i = 0; i < 4; i++) {
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];

        if(nrow >= 0 && nrow < n &&
           ncol >= 0 && ncol < m &&
           !vis[nrow][ncol] &&
           grid[nrow][ncol] == 1) {

            dfs(nrow, ncol, baseRow, baseCol, grid, vis, shape);
        }
    }
}

int numDistinctIslands(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));
    set<vector<pair<int,int>>> uniqueIslands;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 1 && !vis[i][j]) {
                vector<pair<int,int>> shape;
                dfs(i, j, i, j, grid, vis, shape);
                uniqueIslands.insert(shape);
            }
        }
    }

    return uniqueIslands.size();
}

int main() {
    int n, m;
    cout << "Enter number of rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    
    cout << "Enter the grid (0s and 1s):\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    cout << "\nThe grid/graph is:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    int result = numDistinctIslands(grid);
    cout << "\nNumber of distinct islands: " << result << endl;

    return 0;
}

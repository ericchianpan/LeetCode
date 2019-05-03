class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        vector<vector<bool>> finded(grid.size(), vector(grid.begin()->size(), false));
        int maxArea = 0;
        for(unsigned i = 0; i < grid.size(); ++i) {
            for(unsigned j = 0; j < grid[i].size(); ++j) {
                if(finded[i][j] == true) continue;
                int area = getArea(grid, finded, i, j);
                if(area > maxArea) maxArea = area;
            }
        }      
        return maxArea;
    }
    
    int getArea(vector<vector<int>> &grid, vector<vector<bool>> &finded, int i, int j) {
        if(i < 0 || j < 0 || j > grid.begin()->size() - 1 || i > grid.size() -1) return 0;
        if(finded[i][j] == true || grid[i][j] == 0) return 0;
        finded[i][j] = true;
        return 1 + getArea(grid, finded, i + 1, j) +
               getArea(grid, finded, i - 1, j) +
               getArea(grid, finded, i, j + 1) +
               getArea(grid, finded, i, j - 1);
    }
};

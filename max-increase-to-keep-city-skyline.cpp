class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> horizontalSkyline(grid.size(), 0);
        vector<int> verticalSkyline(grid[0].size(), 0);
        for(unsigned i = 0; i < grid.size(); ++i) {
            for(unsigned j = 0; j < grid[i].size(); ++j) {
                if(grid[i][j] > horizontalSkyline[i]) horizontalSkyline[i] = grid[i][j];
                if(grid[i][j] > verticalSkyline[j]) verticalSkyline[j] = grid[i][j];
            }
        }
        int ans = 0;
        for(unsigned i = 0; i < grid.size(); ++i) {
            for(unsigned j = 0; j < grid[i].size(); ++j) {
                ans += min(horizontalSkyline[i], verticalSkyline[j]) - grid[i][j];
            }
        }
        return ans;
    }
};

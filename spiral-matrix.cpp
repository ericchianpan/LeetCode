class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return {};
        int n = matrix.size();
	    int m = matrix[0].size();
        vector<vector<bool>> traversed(n, vector<bool>(m, false));
        vector<int> ans;
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        int x = 0, y = 0, d = 1;
        while(ans.size() < m * n) {
            ans.push_back(matrix[x][y]);
            traversed[x][y] = true;
            int a = x + dx[d], b = y + dy[d];
            if(a >= n || a < 0 || b >= m || b < 0 || traversed[a][b]) {
                d = (d + 1) % 4;
                a = x + dx[d], b = y + dy[d];
            }
            x = a;
            y = b;
        }
        return ans;
    }
};

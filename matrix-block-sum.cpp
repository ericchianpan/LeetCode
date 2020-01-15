class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
    unsigned m = mat.size(); unsigned n = mat.front().size();
      vector<vector<int>> dp(m, vector<int>(n, 0));
      for(unsigned i = 0; i < m; ++i) {
          for(unsigned j = 0; j < n; ++j) {
              if(i == 0 && j == 0) dp[i][j] = mat[i][j];
              else if(i == 0) dp[i][j] = dp[i][j - 1] + mat[i][j];
              else if(j == 0) dp[i][j] = dp[i - 1][j] + mat[i][j];
              else dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + mat[i][j];
          }
      }

     for(int i = 0; i < m; ++i) {
         for(int j = 0; j < n; ++j) {
             int rl = (i - K < 0) ? 0 : i - K; int ru = (i + K >= m) ? m - 1: i + K;
             int cl = (j - K < 0) ? 0 : j - K; int cu = (j + K >= n) ? n - 1 : j + K;
              int sum = dp[ru][cu];
              if(rl > 0 && cl > 0) sum += dp[rl - 1][cl - 1];
              if(rl > 0) sum -= dp[rl - 1][cu];
              if(cl > 0) sum -= dp[ru][cl - 1];
              mat[i][j] = sum;
          }
      }
    return mat;
    }
};

#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char *argv[])
{
    int n = 3;
    vector<vector<int>> ans(n, vector<int>(n, 0));
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        int x = 0, y = 0, d = 1;
        int element = 1;
        while(ans.size() < n * n) {
            ans[x][y] = element;
            element++;
            int a = x + dx[d], b = y + dy[d];
            if(a >= n || a < 0 || b >= n || b < 0 || ans[a][b] != 0) {
                d = (d + 1) % 4;
                a = x + dx[d], b = y + dy[d];
            }
            x = a;
            y = b;
        }
    return 0;
}


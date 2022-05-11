class Solution {
public:
    int n, m;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    vector<vector<int> > dp;
    inline bool isValid(int x, int y) {
        return x >= 0 and x < n and y >= 0 and y < m;
    }
    int solve(vector<vector<int> > &matrix, int x, int y) {
        if(dp[x][y] != -1)
            return dp[x][y];
        int ans = 0;
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(isValid(nx, ny) and matrix[x][y] < matrix[nx][ny])
                ans = max(ans, solve(matrix, nx, ny) + 1);
        }
        return dp[x][y] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix.back().size();
        dp.assign(n,vector<int>(m, -1));
        int res = -1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                res = max(res, solve(matrix, i, j));
            }
        }
        return res + 1;
    }
};

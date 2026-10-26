class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    long long sum = 0;
                    dfs(grid, i, j, sum);
                    if (sum % k == 0)
                        ans++;
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>>& grid, int i, int j, long long &sum) {
        if (i < 0 || j < 0 || i >= grid.size() ||
            j >= grid[0].size() || grid[i][j] == 0)
            return;
        sum += grid[i][j];
        grid[i][j] = 0;
        dfs(grid, i + 1, j, sum);
        dfs(grid, i - 1, j, sum);
        dfs(grid, i, j + 1, sum);
        dfs(grid, i, j - 1, sum);
    }
};
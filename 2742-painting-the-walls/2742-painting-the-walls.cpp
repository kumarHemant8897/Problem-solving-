class Solution {
public:
    int dp[501][501];

    int dfs(int i, int walls, vector<int>& cost, vector<int>& time) {
        if (walls <= 0) return 0;

        if (i == cost.size()) return 1e9;

        if (dp[i][walls] != -1)
            return dp[i][walls];

        int skip = dfs(i + 1, walls, cost, time);

        int take = cost[i] +
                   dfs(i + 1, walls - time[i] - 1, cost, time);

        return dp[i][walls] = min(skip, take);
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        memset(dp, -1, sizeof(dp));
        return dfs(0, cost.size(), cost, time);
    }
};
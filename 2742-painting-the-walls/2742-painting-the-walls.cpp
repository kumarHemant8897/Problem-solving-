class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int walls, vector<int>& cost, vector<int>& time) {

        if (walls <= 0) return 0;

        if (i == cost.size()) return 1e9;

        if (dp[i][walls] != -1)
            return dp[i][walls];

        int nottake = solve(i + 1, walls, cost, time);

        int take = cost[i] +
                   solve(i + 1, walls - time[i] - 1, cost, time);

        return dp[i][walls] = min(take, nottake);
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {

        int n = cost.size();

        dp.assign(n, vector<int>(n + 1, -1));

        return solve(0, n, cost, time);
    }
};
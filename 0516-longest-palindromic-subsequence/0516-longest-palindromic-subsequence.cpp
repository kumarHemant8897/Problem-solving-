class Solution {
public:

    int solve(string &s, int idx1, string &t, int idx2,
              vector<vector<int>> &dp) {

        if (idx1 < 0 || idx2 < 0)
            return 0;

        if (dp[idx1][idx2] != -1)
            return dp[idx1][idx2];

        if (s[idx1] == t[idx2]) {
            return dp[idx1][idx2] =
                1 + solve(s, idx1 - 1, t, idx2 - 1, dp);
        }

        return dp[idx1][idx2] =
            max(solve(s, idx1 - 1, t, idx2, dp),
                solve(s, idx1, t, idx2 - 1, dp));
    }

    int longestPalindromeSubseq(string s) {

        string t = s;
        reverse(t.begin(), t.end());

        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(s, n - 1, t, n - 1, dp);
    }
};
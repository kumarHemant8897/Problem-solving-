class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();

        const long long mod = 1000000007;

        long long dp = 1;
        long long last[26] = {0};

        for (char c : s) {
            int x = c - 'a';

            long long newdp = (2 * dp - last[x] + mod) % mod;

            last[x] = dp;
            dp = newdp;
        }

        return (dp - 1 + mod) % mod;
    }
};
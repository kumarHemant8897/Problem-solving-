class Solution {
public:
    static const int MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        if (n == 1) return m;

        vector<long long> up(m + 2), down(m + 2);
        vector<long long> pref(m + 2), suff(m + 3);
        vector<long long> nup(m + 2), ndown(m + 2);

        for (int x = 1; x <= m; x++) {
            up[x] = x - 1;
            down[x] = m - x;
        }

        for (int len = 3; len <= n; len++) {

            pref[0] = 0;
            for (int i = 1; i <= m; i++)
                pref[i] = (pref[i - 1] + down[i]) % MOD;

            suff[m + 1] = 0;
            for (int i = m; i >= 1; i--)
                suff[i] = (suff[i + 1] + up[i]) % MOD;

            for (int x = 1; x <= m; x++) {
                nup[x] = pref[x - 1];
                ndown[x] = suff[x + 1];
            }

            swap(up, nup);
            swap(down, ndown);
        }

        long long ans = 0;

        for (int x = 1; x <= m; x++)
            ans = (ans + up[x] + down[x]) % MOD;

        return (int)ans;
    }
};
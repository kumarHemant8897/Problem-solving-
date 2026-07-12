class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        int n=nums.size();

         const long long MOD = 1000000007LL;

        long long cur = k;
        long long ops = 0;

        for (long long x : nums) {
            if (cur < x) {
                long long need = (x - cur + k - 1) / k;
                ops += need;
                cur += need * 1LL * k;
            }
            cur -= x;
        }

        long long m = ops % MOD;
        return (m * ((m + 1) % MOD) / 2) % MOD;

        
    }
};
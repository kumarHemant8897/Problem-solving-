class Solution {
public:
    struct Fenwick {
        int n;
        vector<int> bit;

        Fenwick(int size) {
            n = size;
            bit.assign(n + 1, 0);
        }

        void update(int idx, int val) {
            while (idx <= n) {
                bit[idx] += val;
                idx += idx & -idx;
            }
        }

        int query(int idx) {
            int sum = 0;
            while (idx > 0) {
                sum += bit[idx];
                idx -= idx & -idx;
            }
            return sum;
        }
    };

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        int offset = n + 1;
        Fenwick ft(2 * n + 5);

        long long ans = 0;
        int pref = 0;

       
        ft.update(offset, 1);

        for (int x : nums) {
            if (x == target)
                pref++;
            else
                pref--;

            
            ans += ft.query(pref + offset - 1);

            ft.update(pref + offset, 1);
        }

        return ans;
    }
};
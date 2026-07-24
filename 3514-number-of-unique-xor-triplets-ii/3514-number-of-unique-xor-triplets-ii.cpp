class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {

        if (nums.size() < 3) {
            unordered_set<int> s(nums.begin(), nums.end());
            return s.size();
        }

        const int MAXX = 2048;

        vector<bool> present(MAXX, false);
        for (int x : nums)
            present[x] = true;

        vector<bool> two(MAXX, false);

        
        for (int a = 0; a < MAXX; a++) {
            if (!present[a]) continue;
            for (int b = 0; b < MAXX; b++) {
                if (!present[b]) continue;
                two[a ^ b] = true;
            }
        }

        vector<bool> ans(MAXX, false);

        
        for (int x = 0; x < MAXX; x++) {
            if (!two[x]) continue;
            for (int a = 0; a < MAXX; a++) {
                if (!present[a]) continue;
                ans[x ^ a] = true;
            }
        }

        int res = 0;
        for (bool x : ans)
            res += x;

        return res;
    }
};
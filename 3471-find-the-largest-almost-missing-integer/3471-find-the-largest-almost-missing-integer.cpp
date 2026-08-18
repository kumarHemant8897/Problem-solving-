class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;

        for (int i = 0; i <= n - k; i++) {

            for (int j = i; j < i + k; j++) {

                bool already = false;

                // Check if nums[j] already appeared
                // in the current subarray
                for (int p = i; p < j; p++) {
                    if (nums[p] == nums[j]) {
                        already = true;
                        break;
                    }
                }

                if (!already) {
                    mp[nums[j]]++;
                }
            }
        }

        int ans = -1;

        for (auto it : mp) {
            if (it.second == 1) {
                ans = max(ans, it.first);
            }
        }

        return ans;
    }
};
class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {

        int n = nums.size();

        vector<int> prefMax(n);
        vector<int> sufMin(n);
        vector<int> ans(n);

        prefMax[0] = nums[0];
        sufMin[n-1] = nums[n-1];

        for(int i = 1; i < n; i++) {

            int x = nums[i];
            int y = nums[n-1-i];

            // prefix maximum
            prefMax[i] = max(prefMax[i-1], x);

            // suffix minimum
            sufMin[n-1-i] = min(sufMin[n-i], y);
        }

        ans[n-1] = prefMax[n-1];

        for(int i = n-2; i >= 0; i--) {

            if(prefMax[i] > sufMin[i+1])
                ans[i] = ans[i+1];
            else
                ans[i] = prefMax[i];
        }

        return ans;
    }
};
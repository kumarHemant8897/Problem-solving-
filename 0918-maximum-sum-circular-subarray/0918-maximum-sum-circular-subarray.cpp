class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int maxsum = INT_MIN;
        int minsum = INT_MAX;   
        int sum = 0;
        int minprefix = 0;
        int maxprefix = 0;

        for(int i = 0; i < n; i++){
            minprefix += nums[i];
            maxprefix += nums[i];
            sum += nums[i];

            maxsum = max(maxsum, maxprefix);
            minsum = min(minsum, minprefix);

           
            if(maxprefix < 0) maxprefix = 0;
            if(minprefix > 0) minprefix = 0;
        }

        
        if(maxsum < 0) return maxsum;

       
        return max(maxsum, sum - minsum);
    }
};
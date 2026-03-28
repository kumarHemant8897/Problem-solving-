class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        
        int orgsum = 0;
        for(int i = 0; i < n; i++){
            orgsum += nums[i];
        }
        
       
        int sum = 0;
        int minsum = nums[0];
        for(int i = 0; i < n; i++){
            sum += nums[i];
            minsum = min(minsum, sum);
            
            if(sum > 0){
                sum = 0;
            }
        }
        
       
        sum = 0;
        int maxsum = nums[0];
        for(int i = 0; i < n; i++){
            sum += nums[i];
            maxsum = max(maxsum, sum);
            
            if(sum < 0){
                sum = 0;
            }
        }
        
      
        if(maxsum < 0) return maxsum;
        
        return max(maxsum, orgsum - minsum);
    }
};
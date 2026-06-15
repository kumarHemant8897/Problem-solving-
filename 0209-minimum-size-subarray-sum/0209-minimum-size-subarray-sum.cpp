class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        int l=0;
        int sum=0;

        for(int right=0;right < n ;right++){
            sum += nums[right];


            while(sum >= target){
                ans=min(ans,right-l+1);
                sum -=nums[l];
                l++;
            }
        }

        return (ans==INT_MAX) ? 0 : ans;
        
    }
};
class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        int last1=-1;
        int last2=-1;

        for(int i=0;i<n;i++){
            if(nums[i]==1) last1=i;
            if(nums[i]==2) last2=i;

            if(last1 != -1 && last2 != -1){
               ans=min(ans,abs(last1-last2));
            }
        }
        return ans==INT_MAX ? -1 : ans;
        
    }
};
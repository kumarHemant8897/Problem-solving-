class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int ans=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]==1 && nums[j]==2 || (nums[i]==2 && nums[j]==1) ){
                    int diff=abs(j-i);
                    ans=min(ans,diff);
                }
            }
        }
        return ans==INT_MAX ? -1 : ans;
        
    }
};
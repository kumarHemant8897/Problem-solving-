class Solution {
public:

   int solve(vector<int>& nums, int target,int idx){
    if(idx==0){
        if(target==0 && nums[0]==0) return 2;
        if(target==0 || nums[0]==target) return 1;
        return 0;
    }

    int nottake=solve(nums,target,idx-1);
    int take=0;

    if(target >=  nums[idx]){
        take=solve(nums,target-nums[idx],idx-1);
    }

    return take+nottake;
   }



    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int totsum=0;
        for(int i=0;i<n;i++){
            totsum+=nums[i];
        }
        if((totsum-target) <0 || (totsum-target) %2 ) return 0;

        int newtarget=(totsum-target)/2;

        return solve(nums , newtarget,n-1);

        
    }
};
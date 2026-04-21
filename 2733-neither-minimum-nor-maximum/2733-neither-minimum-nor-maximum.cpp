class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int mini=INT_MAX;
        int maxi=INT_MIN;

        for(int i=0;i<nums.size();i++){
              mini=min(mini,nums[i]);
              maxi=max(maxi,nums[i]);
        }

        for(int i=0;i<nums.size();i++){
            if(nums[i] != maxi && nums[i] != mini){
                return nums[i];
            }
        }

        return -1;
        

    }
};
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mxidx=0;
        for(int i=0;i<nums.size();i++){
            if(i > mxidx){
                return false;
            }
            else{
                mxidx=max(mxidx,i+nums[i]);
            }
        }

        return true;
        
    }
};
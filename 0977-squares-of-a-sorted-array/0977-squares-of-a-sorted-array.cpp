class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int newval=nums[i]*nums[i];
            ans.push_back(newval);
        }
         sort(ans.begin(),ans.end());
        return ans;
        
    }
};
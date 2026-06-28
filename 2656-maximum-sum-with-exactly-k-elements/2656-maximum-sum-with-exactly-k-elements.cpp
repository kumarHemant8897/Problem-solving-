class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
        }

        return (1LL * k * maxi) + (1LL * k * (k - 1) / 2);
        
        
    }
};
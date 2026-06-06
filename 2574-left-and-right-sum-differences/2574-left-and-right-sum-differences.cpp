class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }

        int leftsum=0;
        for(int i=0;i<n;i++){
            int rightsum  = sum - leftsum - nums[i];

            ans.push_back(abs(leftsum - rightsum));

            leftsum+=nums[i];
        }

        return ans;
        
    }
};
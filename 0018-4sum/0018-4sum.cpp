class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> st;

        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;

            for(int j = i + 1; j < n; j++){
                if(j > i + 1 && nums[j] == nums[j-1]) continue;

                int k = j + 1;
                int l = n - 1;

                while(k < l){
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                    if(sum < target){
                        k++;
                    }
                    else if(sum > target){
                        l--;
                    }
                    else{
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        st.insert(temp);
                        k++;
                        l--;
                    }
                }
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};
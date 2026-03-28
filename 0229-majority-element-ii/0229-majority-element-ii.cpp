class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int freq=n/3;
        vector<int> ans;
        unordered_map<int,int> map;

        for(int i=0;i<n;i++){
            map[nums[i]]++;
        }

        for(auto it: map){
            if(it.second > freq){
                ans.push_back(it.first);
            }
        }
        return ans;
        
    }
};
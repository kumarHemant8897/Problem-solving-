class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        
        unordered_map<int,int> map;


        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
            
        }
        vector<pair<int,int>> vec;
        for(auto it: map){
            vec.push_back({it.second,it.first});
        }
         sort(vec.rbegin(), vec.rend());

        for(int i=0;i<k;i++){
            ans.push_back(vec[i].second);
        }
        return ans;

        
        return ans;
        
    }
};
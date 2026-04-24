class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();

        unordered_map<int,int> map;
        for(int i=0;i<n;i++){
           if( map.find(nums[i]) != map.end()){
            return true;
           }
           map[nums[i]]=1;
        }
        return false;
        
    }
};
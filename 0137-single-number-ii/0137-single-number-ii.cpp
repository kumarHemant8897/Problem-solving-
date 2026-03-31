class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> map;
        for(int i=0;i<n;i++){
            map[nums[i]]++;
        }
        int ans=0;
        for(auto it: map){
            if(it.second < 3){
                ans=it.first;
            }
        }
        return ans;
        
    }
};
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        int freq=n/2;

        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }


        for(auto it: mp){
            if(it.second > freq){
                return it.first;
            }
        }


        return 0;
        
    }
};
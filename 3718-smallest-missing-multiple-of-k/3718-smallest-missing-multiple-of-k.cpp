class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int > mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

        int multiple=k;

        while(mp.find(multiple) != mp.end()){
            multiple+=k;
        }

        return multiple;

       
    }
};
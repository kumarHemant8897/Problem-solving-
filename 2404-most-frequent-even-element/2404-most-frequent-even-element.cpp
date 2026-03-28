class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;

        for(int i = 0; i < n; i++){
            if(nums[i] % 2 == 0){
                mp[nums[i]]++;
            }
        }

        int ans = -1;
        int maxFreq = 0;

        for(auto it : mp){
            int num = it.first;
            int freq = it.second;

            if(freq > maxFreq || (freq == maxFreq && num < ans)){
                maxFreq = freq;
                ans = num;
            }
        }

        return ans;
    }
};
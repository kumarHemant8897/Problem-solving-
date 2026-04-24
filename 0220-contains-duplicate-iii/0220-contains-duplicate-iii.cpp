class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<long> st;

        for(int i=0;i<nums.size();i++){

            auto it= st.lower_bound(nums[i]-valueDiff);

            if(it != st.end() && abs(*it-nums[i]) <= valueDiff){
                return true;
            }
            st.insert(nums[i]);
        

        if(i>= indexDiff){
            st.erase(nums[i-indexDiff]);
        }
        }

        return false;
        
    }
};
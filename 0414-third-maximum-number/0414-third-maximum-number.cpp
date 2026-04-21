class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;   

        for(int i = 0; i < nums.size(); i++){
            s.insert(nums[i]);  
        }

        int n = s.size();  
        if(n < 3){
            return *s.rbegin();  
        }
        else{
            auto it = s.rbegin();
            advance(it, 2);  
            return *it;
        }
    }
};
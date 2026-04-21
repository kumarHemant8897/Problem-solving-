class Solution {
public:
    int jump(vector<int>& nums) {
        int jump=0;
        int fartest=0;
        int curend=0;

        for(int i=0;i<nums.size()-1;i++){
            fartest=max(fartest,i+nums[i]);

            if(i==curend){
                jump++;
                curend=fartest;
            }
        }

        return jump;
        
    }
};
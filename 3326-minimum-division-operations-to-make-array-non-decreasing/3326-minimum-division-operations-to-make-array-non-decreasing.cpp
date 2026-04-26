class Solution {
public:

    int canbereduce(int n){
       

        for(int i=2;i*i <=n ;i++){
            if(n%i==0){
                return i;
            }
        }
        return n;

    }
  

    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int count=0;

        for(int i=n-2;i>=0;i--){
            if(nums[i] > nums[i+1]){
                nums[i]=canbereduce(nums[i]);
                count++;

                if(nums[i]>nums[i+1]){
                    return -1;
                }


            }
        }

        return count;
        
    }
};
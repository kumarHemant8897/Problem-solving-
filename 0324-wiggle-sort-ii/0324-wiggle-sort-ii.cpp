class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> temp=nums;
        int left=(n-1)/2;
        int right=n-1;

        sort(temp.begin(),temp.end());
        for(int i=0;i<temp.size();i++){
            if(i%2==0){
                nums[i]=temp[left--];

            }
            else{
                nums[i]=temp[right--];
            }
        }


    }
};
class Solution {
public:
     
     void mergesort(vector<int>& nums,int st,int mid,int end){
        vector<int> temp;
        int i=st;
        int j=mid+1;

        while(i<=mid && j<= end){
            if(nums[i] < nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }

        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }

        while(j<=end){
            temp.push_back(nums[j]);
            j++;
        }

        for(int idx=0;idx<temp.size();idx++){
            nums[idx+st]=temp[idx];

        }
     }



     void merge(vector<int>& nums, int st, int end){
        if(st >= end){
            return;
        }
            int mid=st+(end-st)/2;

            merge(nums,st,mid);
            merge(nums,mid+1,end);
            mergesort(nums,st,mid,end);
        
     }


    vector<int> sortArray(vector<int>& nums) {

        merge(nums,0,nums.size()-1);
        return nums;
        
    }
};
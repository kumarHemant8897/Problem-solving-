class Solution {
public:
    void getallsub(int idx, vector<int> &arr,int target,vector<vector<int>> &ans,vector<int> &combin){
        if(target == 0){
            ans.push_back(combin);
            return;
        }

        if( idx == arr.size() || target  < 0){
            return;
        }

        combin.push_back(arr[idx]);
        getallsub(idx,arr,target - arr[idx],ans,combin);
        combin.pop_back();

        getallsub(idx+1,arr,target  ,ans,combin);



    }



    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<vector<int>> ans;
        vector<int> combin;

        getallsub(0,candidates, target ,ans,combin);
        return ans;
        
    }
};
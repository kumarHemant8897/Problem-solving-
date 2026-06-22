class Solution {
public:

    void solve( vector<int>& candidates, int target, int start,vector<vector<int>> &ans,vector<int>&combin){
        if(target==0){
            ans.push_back(combin);
            return;
        }

        for(int  i=start;i<candidates.size();i++){
            if(i>start && candidates[i] == candidates[i-1]) continue ;

            if(candidates[i] > target){
                break;
            }

            combin.push_back(candidates[i]);
            solve(candidates,target-candidates[i],i+1,ans,combin);
            combin.pop_back();
        }

    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        vector<int> combin;
        solve(candidates,target,0,ans,combin);
        return ans;
        
    }
};
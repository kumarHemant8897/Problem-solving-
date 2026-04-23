class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& interval, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i=0;
        int n=interval.size();

        while(i < n && interval[i][1] <  newInterval[0]){
            res.push_back(interval[i]);
            i=i+1;
        }

        while(i<n && interval[i][0] <= newInterval[1]){
            newInterval[0]=min(newInterval[0], interval[i][0]);
            newInterval[1]=max(newInterval[1],interval[i][1]);
            i=i+1;
        }
        
        res.push_back(newInterval);

        while(i<n){
            res.push_back(interval[i]);
            i++;
        }

        return res;
        
    }
};
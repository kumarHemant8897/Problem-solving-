class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        queue<pair<int,int>> q;
        vector<int> vis(1001, 0);

        q.push({start, 0});
        vis[start] = 1;

        while(!q.empty()){
            int num = q.front().first;
            int steps = q.front().second;
            q.pop();

            for(int i = 0; i < nums.size(); i++){
                vector<int> next = {
                    num + nums[i],
                    num - nums[i],
                    num ^ nums[i]
                };

                for(int val : next){
                    if(val == goal){
                        return steps + 1;
                    }

                    if(val >= 0 && val <= 1000 && !vis[val]){
                        vis[val] = 1;
                        q.push({val, steps + 1});
                    }
                }
            }
        }
        return -1;
    }
};
class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {

        vector<vector<int>> adj(n);
        for(auto it: paths){
            int u=it[0] - 1;
            int v=it[1] - 1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            bool used[5]={false};

            for(auto neighbour : adj[i]){
                int color=ans[neighbour];

                used[color]=true;
            }

            for(int color=1;color<=4;color++){
                if(!used[color]){
                    ans[i]=color;
                }
            }
        }

        return ans;

        
    }
};
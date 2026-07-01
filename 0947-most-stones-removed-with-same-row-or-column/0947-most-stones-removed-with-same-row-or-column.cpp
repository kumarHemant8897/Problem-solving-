class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        vector<int> vis(n,0);
        int components = 0;

        for(int i=0;i<n;i++){
            if(vis[i]) continue;

            components++;
            queue<int> q;
            q.push(i);
            vis[i]=1;

            while(!q.empty()){
                int node=q.front();
                q.pop();

                for(int j=0;j<n;j++){
                    if(!vis[j] &&
                       (stones[node][0]==stones[j][0] ||
                        stones[node][1]==stones[j][1])){
                        vis[j]=1;
                        q.push(j);
                    }
                }
            }
        }

        return n-components;
    }
};
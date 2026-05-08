class Solution {
public:

    void dfs(int node,
             vector<int>& vis,
             vector<int> adj[],
             vector<int>& comp) {

        vis[node] = 1;

        comp.push_back(node);

        for(int i = 0; i < adj[node].size(); i++) {

            int neigh = adj[node][i];

            if(vis[neigh] == 0) {

                dfs(neigh, vis, adj, comp);
            }
        }
    }

    int countCompleteComponents(int n,
                                vector<vector<int>>& edges) {

        
        vector<int> adj[n];

        for(auto e : edges) {

            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);

        int complete = 0;

        
        for(int i = 0; i < n; i++) {

            if(vis[i] == 0) {

                vector<int> comp;

                dfs(i, vis, adj, comp);

               
                int nodes = comp.size();

                
                int edgecount = 0;

                for(int j = 0; j < comp.size(); j++) {

                    int node = comp[j];

                    edgecount += adj[node].size();
                }

                
                edgecount = edgecount / 2;

                
                if(edgecount == (nodes * (nodes - 1)) / 2) {

                    complete++;
                }
            }
        }

        return complete;
    }
};
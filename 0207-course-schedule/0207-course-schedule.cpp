class Solution {
public:

    bool dfscheck(int node, int vis[], int pathvis[], vector<int> adj[]) {

        vis[node] = 1;
        pathvis[node] = 1;

        for(auto it : adj[node]) {

            if(!vis[it]) {

                if(dfscheck(it, vis, pathvis, adj)) {
                    return true;
                }
            }
            else if(pathvis[it]) {
                return true;
            }
        }

        pathvis[node] = 0;

        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> adj[numCourses];

        int n = prerequisites.size();

        // correct graph direction
        for(int i = 0; i < n; i++) {

            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[v].push_back(u);
        }

        int vis[numCourses];
        int pathvis[numCourses];

        for(int i = 0; i < numCourses; i++) {
            vis[i] = 0;
            pathvis[i] = 0;
        }

        for(int i = 0; i < numCourses; i++) {

            if(!vis[i]) {

                if(dfscheck(i, vis, pathvis, adj)) {
                    return false;
                }
            }
        }

        return true;
    }
};
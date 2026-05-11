class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n,vector<int>(n,1e9));

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];

            dist[u][v]=wt;
            dist[v][u]=wt;
        }

        for(int i=0;i<n;i++){
            dist[i][i]=0;
        }

        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){

                   

                    if(dist[i][via] != 1e9 && dist[j][via] != 1e9){
                        dist[i][j] = min(dist[i][j] , dist[i][via] + dist[via][j]);
                    }

                }
            }
        }

        int city=-1;
        int cntcity=1e9;

        for(int i=0;i<n;i++){
            int count=0;

            for(int j=0;j<n;j++){

                if(dist[i][j] <=  distanceThreshold){
                    count++;
                }
            }

            if(count <= cntcity){
                cntcity=count;
                city=i;

            }
        }

        return city;
        
    }
};
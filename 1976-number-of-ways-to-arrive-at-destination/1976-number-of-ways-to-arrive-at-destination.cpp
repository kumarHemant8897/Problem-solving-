class Solution {
public:

    const int MOD = 1e9 + 7;

    int countPaths(int n, vector<vector<int>>& roads) {

        vector<pair<int,int>> adj[n];

        for(int i = 0; i < roads.size(); i++) {

            int u = roads[i][0];
            int v = roads[i][1];
            int wt = roads[i][2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        // {distance, node}
        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        dist[0] = 0;
        ways[0] = 1;

        pq.push({0, 0});

        while(!pq.empty()) {

            auto it = pq.top();
            pq.pop();

            long long dis = it.first;
            int node = it.second;

            if(dis > dist[node]) continue;

            for(auto it : adj[node]) {

                int nextnode = it.first;
                int edgewt = it.second;

               
                if(dis + edgewt < dist[nextnode]) {

                    dist[nextnode] = dis + edgewt;

                    ways[nextnode] = ways[node];

                    pq.push({dist[nextnode], nextnode});
                }

               
                else if(dis + edgewt == dist[nextnode]) {

                    ways[nextnode] =
                        (ways[nextnode] + ways[node]) % MOD;
                }
            }
        }

        return ways[n-1] % MOD;
    }
};
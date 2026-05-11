class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<pair<int,int>> adj[n];

        for(int i = 0; i < flights.size(); i++) {

            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];

            adj[u].push_back({v, wt});
        }

        queue<pair<int,pair<int,int>>> q;

        vector<int> dist(n, 1e9);

        dist[src] = 0;

        q.push({0, {src, 0}});

        while(!q.empty()) {

            auto it = q.front();
            q.pop();

            int stop = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stop > k)
                continue;

            for(int i = 0; i < adj[node].size(); i++) {

                int v = adj[node][i].first;
                int price = adj[node][i].second;

                if(cost + price < dist[v]) {

                    dist[v] = cost + price;

                    q.push({stop + 1, {v, dist[v]}});
                }
            }
        }

        if(dist[dst] == 1e9)
            return -1;

        return dist[dst];
    }
};
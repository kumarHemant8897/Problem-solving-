class Solution {
public:

    vector<long long> dijkstra(
        int src,
        vector<vector<pair<int,long long>>>& adj,
        int n
    ) {

        vector<long long> dist(n, LLONG_MAX);

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {

            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;

            for (auto &[v, w] : adj[u]) {

                if (dist[v] > d + w) {

                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }

    vector<int> minCost(int n,
                        vector<int>& prices,
                        vector<vector<int>>& roads) {

       
        auto dravexilo = roads;

        vector<vector<pair<int,long long>>> emptyAdj(n);
        vector<vector<pair<int,long long>>> carryAdj(n);

        for (auto &r : roads) {

            int u = r[0];
            int v = r[1];
            long long c = r[2];
            long long t = r[3];

            emptyAdj[u].push_back({v, c});
            emptyAdj[v].push_back({u, c});

            carryAdj[u].push_back({v, c * t});
            carryAdj[v].push_back({u, c * t});
        }

        vector<vector<long long>> emptyDist(n);
        vector<vector<long long>> carryDist(n);

        for (int i = 0; i < n; i++) {

            emptyDist[i] = dijkstra(i, emptyAdj, n);
            carryDist[i] = dijkstra(i, carryAdj, n);
        }

        vector<int> ans(n);

        for (int i = 0; i < n; i++) {

            long long best = prices[i];

            for (int j = 0; j < n; j++) {

                if (emptyDist[i][j] == LLONG_MAX ||
                    carryDist[j][i] == LLONG_MAX)
                    continue;

                best = min(best,
                           1LL * prices[j]
                           + emptyDist[i][j]
                           + carryDist[j][i]);
            }

            ans[i] = best;
        }

        return ans;
    }
};
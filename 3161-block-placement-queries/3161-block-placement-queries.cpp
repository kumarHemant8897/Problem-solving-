class SegmentTree {
public:
    int n;
    vector<int> tree;

    SegmentTree(int n) : n(n) {
        tree.resize(4 * n + 4, 0);
    }

    void update(int idx, int val, int node, int l, int r) {
        if (l == r) {
            tree[node] = val;
            return;
        }

        int mid = (l + r) >> 1;

        if (idx <= mid)
            update(idx, val, node * 2, l, mid);
        else
            update(idx, val, node * 2 + 1, mid + 1, r);

        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int idx, int val) {
        update(idx, val, 1, 0, n);
    }

    int query(int L, int R, int node, int l, int r) {
        if (R < l || r < L)
            return 0;

        if (L <= l && r <= R)
            return tree[node];

        int mid = (l + r) >> 1;

        return max(
            query(L, R, node * 2, l, mid),
            query(L, R, node * 2 + 1, mid + 1, r)
        );
    }

    int query(int L, int R) {
        return query(L, R, 1, 0, n);
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        const int MAXX = 50000;

        set<int> obstacles;
        obstacles.insert(0);

        for (auto &q : queries) {
            if (q[0] == 1)
                obstacles.insert(q[1]);
        }

        SegmentTree seg(MAXX);

        vector<int> pos(obstacles.begin(), obstacles.end());

        for (int i = 1; i < pos.size(); i++) {
            seg.update(pos[i], pos[i] - pos[i - 1]);
        }

        vector<bool> ans;

        for (int i = (int)queries.size() - 1; i >= 0; i--) {

            auto &q = queries[i];

            if (q[0] == 2) {

                int x = q[1];
                int sz = q[2];

                int best = seg.query(0, x);

                auto it = obstacles.upper_bound(x);
                --it;

                best = max(best, x - *it);

                ans.push_back(best >= sz);
            }
            else {

                int x = q[1];

                auto it = obstacles.find(x);

                auto prv = prev(it);
                auto nxt = next(it);

                if (nxt != obstacles.end()) {
                    seg.update(*nxt, *nxt - *prv);
                }

                seg.update(x, 0);

                obstacles.erase(it);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
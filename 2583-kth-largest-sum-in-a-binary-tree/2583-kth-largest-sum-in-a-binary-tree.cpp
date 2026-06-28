class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) return -1;

        queue<TreeNode*> q;
        vector<long long> levelSums;

        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            long long sum = 0;   

            for (int i = 0; i < n; i++) {
                TreeNode* cur = q.front();
                q.pop();

                sum += cur->val;

                if (cur->left)  q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }

            levelSums.push_back(sum);  
        }

        if (k > levelSums.size()) return -1;

        sort(levelSums.begin(), levelSums.end(), greater<long long>());

        return levelSums[k - 1];
    }
};

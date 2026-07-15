class Solution {
public:
    unordered_map<int, int> freq;
    int maxfre = 0;

    int getsum(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int left = getsum(root->left);
        int right = getsum(root->right);

        int sum = root->val + left + right;

        freq[sum]++;

        maxfre = max(maxfre, freq[sum]);

        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
       
        getsum(root);

        vector<int> ans;

        for (auto it : freq) {
            if (it.second == maxfre) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};
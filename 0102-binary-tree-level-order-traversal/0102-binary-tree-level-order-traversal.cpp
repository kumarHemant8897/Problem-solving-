class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(root == NULL) {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int n = q.size();
            vector<int> level;

            while(n--) {
                TreeNode* front = q.front();
                q.pop();

                level.push_back(front->val);

                if(front->left) {
                    q.push(front->left);
                }

                if(front->right) {
                    q.push(front->right);
                }
            }

            ans.push_back(level);
        }

        return ans;
    }
};
class Solution {
public:
    void inorder(TreeNode* root, vector<int> &ans) {
        if (root == NULL)
            return;

        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    TreeNode* increasingBST(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);

        TreeNode* dummy = new TreeNode(0);
        TreeNode* curr = dummy;

        for (int x : ans) {
            curr->right = new TreeNode(x);
            curr = curr->right;
        }

        return dummy->right;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *          : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    unordered_map<int, TreeNode*> mp;
    unordered_set<int> child;

    bool validate(TreeNode* root, long long mn, long long mx) {

        if(!root) return true;

        if(root->val <= mn || root->val >= mx)
            return false;

        
        if(!root->left && !root->right && mp.count(root->val)) {

            TreeNode* node = mp[root->val];

            root->left = node->left;
            root->right = node->right;

            mp.erase(root->val);
        }

        return validate(root->left, mn, root->val) &&
               validate(root->right, root->val, mx);
    }

    

    TreeNode* canMerge(vector<TreeNode*>& trees) {

        for(auto tree : trees) {

            mp[tree->val] = tree;

            if(tree->left)
                child.insert(tree->left->val);

            if(tree->right)
                child.insert(tree->right->val);
        }

        TreeNode* root = NULL;

        for(auto tree : trees) {

            if(!child.count(tree->val)) {
                root = tree;
                break;
            }
        }

        if(!root) return NULL;

        mp.erase(root->val);

        if(!validate(root, LLONG_MIN, LLONG_MAX) || !mp.empty())
            return NULL;

        return root;
    }
};
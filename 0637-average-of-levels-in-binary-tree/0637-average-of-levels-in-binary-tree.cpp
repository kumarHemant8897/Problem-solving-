/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    double average(vector<int>& nums) {
        
        double sum = 0;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        return sum / nums.size();
    }

    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<double> ans;

        if(root == NULL) {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            int n = q.size();

            vector<int> solve;

            for(int i = 0; i < n; i++) {

                TreeNode* node = q.front();
                q.pop();

                solve.push_back(node->val);

                if(node->left) q.push(node->left);

                if(node->right) q.push(node->right);
            }

            double val = average(solve);

            ans.push_back(val);
        }

        return ans;
    }
};
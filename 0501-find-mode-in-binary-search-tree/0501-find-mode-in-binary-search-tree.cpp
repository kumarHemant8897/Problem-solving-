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
 void inorder(TreeNode* root,vector<int> & ans){
    if(root==NULL){
        return ;
    }

    inorder(root->left,ans);
    ans.push_back(root->val);
    inorder(root->right,ans);
 }
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
        
        unordered_map<int,int> map;
        int maxi=0;

        for(int i=0;i<ans.size();i++){
            map[ans[i]]++;

        }

        for(auto it: map){
            maxi=max(maxi,it.second);
        }
        
        vector<int> res;

        for(auto it: map){
            if(it.second==maxi){
                res.push_back(it.first);
            }
        }
        return res;
        
    }
};
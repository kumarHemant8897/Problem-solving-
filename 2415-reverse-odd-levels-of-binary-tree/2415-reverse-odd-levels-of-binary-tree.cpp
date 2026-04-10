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
void invertodd(TreeNode* leftroot,TreeNode* rightroot,int level){
    if(leftroot==NULL || rightroot==NULL){
        return;
    }
    if(level %2 ==1){
        swap(leftroot->val,rightroot->val);
    }
    invertodd(leftroot->left,rightroot->right,level+1);
    invertodd(leftroot->right,rightroot->left,level+1);
    



}


    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        int level=0;

           invertodd(root->left,root->right,1);
           return root;
         
        
    }
};
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
int dia=0;

    int height(TreeNode* root){
         if(root==NULL){
            return NULL;
        }
        
        int leftheight=height(root->left);
        int rightheight=height(root->right);

        dia=max(dia , leftheight+rightheight);
        return 1 + max(leftheight,rightheight);

        
    }

 
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return dia;
       
        
    }
};
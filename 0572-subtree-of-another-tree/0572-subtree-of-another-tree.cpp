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

   bool identical(TreeNode* p,TreeNode* q){
    if(p==NULL||q==NULL){
        return p==q;
    }

    bool isleft=identical(p->left,q->left);
    bool isright=identical(p->right,q->right);

    return isleft && isright && (p->val==q->val);

   }


  
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if(root==NULL) return false;
        if(subroot==NULL) return true;
        if((root->val==subroot->val) && identical(root,subroot)){
            return true;
            
        }
        else{
            return isSubtree(root->left,subroot) || 
            isSubtree(root->right,subroot);
            

        }
        return false;
        
    }
};
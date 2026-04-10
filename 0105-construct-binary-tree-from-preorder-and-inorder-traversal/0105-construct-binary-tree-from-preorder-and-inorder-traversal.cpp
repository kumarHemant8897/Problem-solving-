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

TreeNode* buildTree(vector<int>& preorder, int prest,int prend,  vector<int>& inorder,int inst,int inend,map<int,int> &inmap){

    if(prest > prend || inst > inend){
        return NULL;
    }

    TreeNode* root= new TreeNode(preorder[prest]);

    int inroot=inmap[root->val];
    int numsleft=inroot - inst;

    root->left=buildTree(preorder,prest+1,prest+numsleft,inorder,inst,inroot-1,inmap);
    root->right=buildTree(preorder,prest+numsleft+1,prend,inorder,inroot+1,inend,inmap);


    return root;



}







    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> inmap;
        for(int i=0;i<inorder.size();i++){
            inmap[inorder[i]]=i;
        }


        TreeNode* root=buildTree(preorder,0,preorder.size()-1,
                                 inorder,0,inorder.size()-1,inmap );

      return root;
        
    }
};
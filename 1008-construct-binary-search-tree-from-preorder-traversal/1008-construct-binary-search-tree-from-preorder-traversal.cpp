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

   TreeNode* solve(vector<int> &preorder,int prest,int prend,vector<int> &inorder,int inst, int inend,map<int,int>&inmap){

    if(inst > inend || prest > prend){
        return NULL;
    }
    
    TreeNode* root = new TreeNode(preorder[prest]);
    int inroot=inmap[root->val];
    int leftnum=inroot-inst;

    root->left=solve(preorder,prest+1,prest+leftnum,inorder,inst,inroot-1,inmap);
    root->right=solve(preorder,prest+leftnum+1,prend,inorder,inroot+1,inend,inmap);
    return root;



   }

 
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        vector<int> inorder=preorder;
        sort(inorder.begin(),inorder.end());

        map<int,int> inmap;
        for(int i=0;i<inorder.size();i++){
            inmap[inorder[i]]=i;
        }

        TreeNode* root=solve(preorder,0,preorder.size()-1, inorder,0,inorder.size()-1,inmap);
        return root;
        
    }
};
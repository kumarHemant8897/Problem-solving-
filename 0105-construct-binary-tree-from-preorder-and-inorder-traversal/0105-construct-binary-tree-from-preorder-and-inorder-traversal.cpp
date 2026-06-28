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
   TreeNode* solve(vector<int>&inorder,int inst,int inend,vector<int>&preorder,int prest,int prend,map<int,int>&inmap){
    if(inst > inend || prest > prend){
        return NULL;
    }

    TreeNode* root=new TreeNode(preorder[prest]);

    int inroot=inmap[root->val];
    int leftnum=inroot-inst;

    root->left=solve(inorder,inst,inroot-1,preorder,prest+1,prest+leftnum,inmap);
    root->right=solve(inorder,inroot+1,inend,preorder,prest+leftnum+1,prend,inmap);

    return root;
   }

  

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        int m=preorder.size();
        map<int,int> inmap;
        for(int i=0;i<n;i++){
            inmap[inorder[i]]=i;
        }

        return solve(inorder,0,n-1,preorder,0,m-1,inmap);
        
    }
};
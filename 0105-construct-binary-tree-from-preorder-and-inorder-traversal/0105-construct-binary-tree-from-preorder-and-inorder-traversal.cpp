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
   
    TreeNode* solve(vector<int> &preorder,int prest, int prend, vector<int> &inorder,int inst, int inend ,map<int,int> &inmap){
        if(prest > prend || inst > inend){
            return NULL;
        }

        TreeNode* root=new TreeNode(preorder[prest]);

        int inroot=inmap[root->val];
        int lefnum=inroot-inst;

        root->left=solve(preorder,prest+1,prest+lefnum,inorder,inst,inroot-1,inmap);
        root->right=solve(preorder,prest+lefnum+1,prend,inorder,inroot+1,inend,inmap);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        int m=inorder.size();
        map<int,int> inmap;
        for (int i = 0; i < m; i++) {
          inmap[inorder[i]] = i;
        }

        return solve(preorder,0,n-1,inorder,0,m-1,inmap);

        
    }
};
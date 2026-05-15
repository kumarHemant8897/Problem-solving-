/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

     void markparent(TreeNode* root,   unordered_map<TreeNode*,TreeNode*> &map){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n=q.size();

            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();

                if(node->left){
                    map[node->left]=node;
                    q.push(node->left);
                }

                if(node->right){
                    map[node->right]=node;
                    q.push(node->right);
                }
            }
        }
     }


    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> map;
        markparent(root,map);
        
        queue<TreeNode*> q;
        unordered_map<TreeNode*,bool> vis;

        q.push(target);
        vis[target]=true;

        int dis=0;

        while(!q.empty()){
            int n=q.size();
            

            if(dis==k){
                break;
            }
            dis++;

            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();

                if(node->left && !vis[node->left]){
                    vis[node->left]=true;
                    q.push(node->left);
                }

                if(node->right && !vis[node->right]){
                    vis[node->right]=true;
                    q.push(node->right);
                }


                if(map[node] && !vis[map[node]]){
                    vis[map[node]]=true;
                    q.push(map[node]);
                }
            }


        }

        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;

        
    }
};
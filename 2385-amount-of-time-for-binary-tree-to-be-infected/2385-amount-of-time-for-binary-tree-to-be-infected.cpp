class Solution {
public:

TreeNode* parent(TreeNode* root, map<TreeNode*,TreeNode*> &mpp, int target){
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* res = NULL;

    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();

        if(node->val == target){
            res = node;
        }

        if(node->left){
            mpp[node->left] = node;
            q.push(node->left);
        }

        if(node->right){
            mpp[node->right] = node;
            q.push(node->right);
        }
    }
    return res;
}


int maxdist(map<TreeNode*,TreeNode*> &mpp, TreeNode* target){
    queue<TreeNode*> q;
    q.push(target);

    map<TreeNode*,int> vis;
    vis[target] = 1;
    int maxi = 0;

    while(!q.empty()){
        int n = q.size();
        int flag = 0;

        for(int i=0;i<n;i++){
            TreeNode* node = q.front();
            q.pop();

            if(node->left && !vis[node->left]){
                vis[node->left] = 1;
                q.push(node->left);
                flag = 1;
            }

            if(node->right && !vis[node->right]){
                vis[node->right] = 1;
                q.push(node->right);
                flag = 1;
            }

            if(mpp[node] && !vis[mpp[node]]){
                vis[mpp[node]] = 1;
                q.push(mpp[node]);
                flag = 1;
            }
        }

        if(flag) maxi++;
    }
    return maxi;
}


int amountOfTime(TreeNode* root, int start) {

    map<TreeNode*,TreeNode*> mpp;
    TreeNode* targetnode = parent(root, mpp, start);
    return maxdist(mpp, targetnode);
}
};
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;

        if(root == NULL) return ans;

        bool leftToright = true;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> level(size);  

            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();

                int idx = leftToright ? i : (size - 1 - i);
                level[idx] = node->val;   // fill at correct index

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            leftToright = !leftToright; 
            ans.push_back(level);
        }

        return ans;
    }
};
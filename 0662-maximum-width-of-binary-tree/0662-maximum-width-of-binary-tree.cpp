class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        long long wid = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while(!q.empty()){
            int n = q.size();
            long long st = q.front().second;
            long long end = q.back().second;

            wid = max(wid, end - st + 1);

            for(int i = 0; i < n; i++){
                auto cur = q.front();
                q.pop();

                TreeNode* node = cur.first;
                long long idx = cur.second - st;

                if(node->left){
                    q.push({node->left, 2*idx + 1});
                }
                if(node->right){
                    q.push({node->right, 2*idx + 2});
                }
            }
        }

        return (int)wid;
    }
};
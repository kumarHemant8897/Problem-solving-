class Solution {
public:

TreeNode* findlastright(TreeNode* root){
    if(root->right == NULL) return root;
    return findlastright(root->right);
}

TreeNode* solve(TreeNode* root){
    if(root->left == NULL) return root->right;
    if(root->right == NULL) return root->left;

    TreeNode* leftchild = root->left;
    TreeNode* lastright = findlastright(leftchild);
    lastright->right = root->right;

    return leftchild;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if(root == NULL) return NULL;

    if(root->val == key){
        return solve(root);
    }

    TreeNode* temp = root;

    while(root != NULL){
        if(key < root->val){
            if(root->left && root->left->val == key){
                root->left = solve(root->left);
                break;
            }
            else root = root->left;
        }
        else{
            if(root->right && root->right->val == key){
                root->right = solve(root->right);
                break;
            }
            else root = root->right;
        }
    }

    return temp;
}
};
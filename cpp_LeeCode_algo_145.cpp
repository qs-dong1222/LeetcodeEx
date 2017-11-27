vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    if(!root) return ans;
    postorderTraversal(root, ans);
    return ans;
}

void postorderTraversal(TreeNode* root, vector<int>& ans){
    if(!root){
        return;
    }

    postorderTraversal(root->left, ans);
    postorderTraversal(root->right, ans);
    ans.push_back(root->val);
}

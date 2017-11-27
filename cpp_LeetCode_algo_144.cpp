vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    if(!root) return ans;
    preorderTraversal(root, ans);
    return ans;
}

void preorderTraversal(TreeNode* root, vector<int>& ans){
    if(!root){
        return;
    }

    ans.push_back(root->val);
    preorderTraversal(root->left, ans);
    preorderTraversal(root->right, ans);
}

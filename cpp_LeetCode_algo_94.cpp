#include <iostream>
#include <vector>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode* root);
void dfs(TreeNode* root, vector<int>& ans);


int main(){

    TreeNode n0(0), n1(1), n2(2), n3(3), n4(4);

    //     0
    //  1     2
    //      3   4
    n0.left = &n1;
    n0.right = &n2;
    n2.left = &n3;
    n2.right = &n4;

    vector<int> ans = inorderTraversal(&n0);

    for(auto a : ans){
        cout << a << endl;
    }

    return 0;
}



vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    dfs(root, ans);
    return ans;
}

void dfs(TreeNode* root, vector<int>& ans){
    if(!root) return;

    dfs(root->left, ans);
    ans.push_back(root->val);
    dfs(root->right, ans);
}

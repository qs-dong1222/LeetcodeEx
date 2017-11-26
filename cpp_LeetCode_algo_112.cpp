#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){

    return 0;
}


bool DFS(TreeNode* root, int sum) {
    if(!root)
        return false;

    if(!root->left && !root->right){
        // this is a leaf node
        return (sum - root->val == 0? true : false);
    }

    if(DFS(root->left, sum - root->val))
        return true;
    if(DFS(root->right, sum - root->val))
        return true;

    return false;
}

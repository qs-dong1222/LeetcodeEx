#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode* root);

int main(){
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    TreeNode n5(5);

    n1.left = &n5;
    n1.right = &n2;
    n2.right = &n3;
    n3.right = &n4;

    cout << maxDepth(&n1) << endl;

    return 0;
}


int maxDepth(TreeNode* root) {
    if(!root)
        return 0;

    // root itself is not NULL, which means we may at the leaf level and we have depth of at least 1
    int leftDepth = 1;
    if(root->left){
        leftDepth = maxDepth(root->left) + 1;
    }

    int rightDepth = 1;
    if(root->right){
        rightDepth = maxDepth(root->right) + 1;
    }

    return max(rightDepth, leftDepth);
}

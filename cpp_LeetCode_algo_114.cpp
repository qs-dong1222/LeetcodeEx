#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


void preorderTraverse(TreeNode* root, vector<int>& ans);
TreeNode* flattenTree(vector<int>& nums, int idx);
void Traverse(TreeNode* root);

void flatten(TreeNode *root);

int main(){

    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    TreeNode n5(5);
    TreeNode n6(6);

//    n1.left = &n2;
//    n1.right = &n5;
//    n2.left = &n3;
//    n2.right = &n4;
//    n5.right = &n6;

    vector<int> nums;
    preorderTraverse(&n1, nums);
    TreeNode* root = flattenTree(nums, 0);
    Traverse(root);

    return 0;
}


TreeNode* flattenTree(vector<int>& nums, int idx){
    if(nums.empty() || idx >= nums.size())
        return NULL;

    TreeNode* root = new TreeNode(nums[idx]);
    root->left = NULL;
    root->right = flattenTree(nums, idx+1);
    return root;
}


void preorderTraverse(TreeNode* root, vector<int>& ans){
    if(!root)
        return;

    ans.push_back(root->val);
    if(root->left)
        preorderTraverse(root->left, ans);
    if(root->right)
        preorderTraverse(root->right, ans);
}


void Traverse(TreeNode* root){
    if(!root){
        cout << "NULL" << " ";
        return;
    }

    cout << root->val << " ";
    Traverse(root->left);
    Traverse(root->right);
}


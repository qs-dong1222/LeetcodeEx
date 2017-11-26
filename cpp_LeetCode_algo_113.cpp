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

void DFS(TreeNode* root, int sum, vector<int>& curr, vector<vector<int>>& ans);
vector<vector<int>> pathSum(TreeNode* root, int sum);

int main(){

    TreeNode n1(1);
    TreeNode n2(9);
    TreeNode n3(5);
    TreeNode n4(11);
    TreeNode n5(4);

    n1.left = &n2;
    n1.right = &n3;
    n3.left = &n4;
    n3.right = &n5;

    vector<vector<int>> ans = pathSum(&n1, 10);

    for(auto eachRow : ans){
        for(auto each : eachRow){
            cout << each << " ";
        }
        cout << endl;
    }

    return 0;
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> ans;
    if(!root) return ans;

    vector<int> curr;
    DFS(root, sum, curr, ans);

    return ans;
}


void DFS(TreeNode* root, int sum, vector<int>& curr, vector<vector<int>>& ans) {
    if(!root){
        // top root is null
        return;
    }

    if(!root->left && !root->right){
        // this is a leaf node
        curr.push_back(root->val);
        sum -= root->val;
        if(sum == 0){
            ans.push_back(curr);
        }
        sum += root->val;
        curr.pop_back();
        return;
    }

    if(root->left && !root->right){
        // has no right leaf
        curr.push_back(root->val);
        sum -= root->val;
        DFS(root->left, sum, curr, ans);
        sum += root->val;
        curr.pop_back();
    }

    if(!root->left && root->right){
        // has no left leaf
        curr.push_back(root->val);
        sum -= root->val;
        DFS(root->right, sum, curr, ans);
        sum += root->val;
        curr.pop_back();
    }

    if(root->left && root->right){
        // has both left and right child
        curr.push_back(root->val);
        sum -= root->val;
        DFS(root->left, sum, curr, ans);
        DFS(root->right, sum, curr, ans);
        sum += root->val;
        curr.pop_back();
    }

}

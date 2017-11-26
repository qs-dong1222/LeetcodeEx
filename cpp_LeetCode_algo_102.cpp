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

vector<vector<int>> levelOrder(TreeNode* root);

int main(){
    TreeNode n1(10);
    TreeNode n2(5);
    TreeNode n3(15);
    TreeNode n4(6);
    TreeNode n5(20);

    n1.left = &n2;
    n1.right = &n3;
    n3.left = &n4;
    n3.right = &n5;

    vector<vector<int>> ans = levelOrder(&n1);

    for(auto eachRow : ans){
        for(auto each : eachRow){
            cout << each << " ";
        }
        cout << endl;
    }

    return 0;
}

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(!root) return ans;

    vector<int> currLevel;
    queue<TreeNode*> qtree;

    TreeNode* curr;
    qtree.push(root);
    while(!qtree.empty()){
        currLevel.clear();

        for(int i=qtree.size()-1;i>=0;i--){
            curr = qtree.front();
            qtree.pop();
            if(curr) currLevel.push_back(curr->val);
            if(curr->left) qtree.push(curr->left);
            if(curr->right) qtree.push(curr->right);
        }
        if(!currLevel.empty()) ans.push_back(currLevel);
    }

    return ans;
}




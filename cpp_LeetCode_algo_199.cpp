#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <deque>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using namespace std;
vector<int> rightSideView(TreeNode* root);

int main(){
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    TreeNode n5(5);

    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n3.right = &n5;

    vector<int> ans = rightSideView(&n1);

    for(auto each:ans){
        cout << each << " ";
    }

    return 0;
}


vector<int> rightSideView(TreeNode* root) {
    vector<int> rightNodes;
    if(!root){
        return rightNodes;
    }

    deque<TreeNode*> dq;
    TreeNode* curr;

    dq.push_back(root);
    while(!dq.empty()){
        TreeNode* rightNode = dq.back();
        rightNodes.push_back(rightNode->val);

        for(int i=dq.size();i>0;i--){
            curr = dq.front();
            dq.pop_front();

            if(curr){
                if(curr->left){
                    dq.push_back(curr->left);
                }
                if(curr->right){
                    dq.push_back(curr->right);
                }
            }
        }
    }

    return rightNodes;
}


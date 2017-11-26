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

vector<vector<int>> LevelOrderTraverse(TreeNode* root);

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

    vector<vector<int>> ans = LevelOrderTraverse(&n1);

    for(auto eachRow : ans){
        for(auto each : eachRow){
            cout << each << " ";
        }
        cout << endl;
    }


    return 0;
}


vector<vector<int>> LevelOrderTraverse(TreeNode* root){
    vector<vector<int>> ans;
    if(!root) return ans;

    vector<int> currLevel;
    queue<TreeNode*> qtree;

    qtree.push(root);
    TreeNode* currNode;
    while(!qtree.empty()){
        currLevel.clear();

        for(int i=qtree.size()-1; i>=0; i--){
            currNode = qtree.front();
            qtree.pop();
            if(currNode){
                currLevel.push_back(currNode->val);
                // find nodes in next level for currNode
                if(currNode->left)
                    qtree.push(currNode->left);
                if(currNode->right)
                    qtree.push(currNode->right);
            }
        }

        if(!currLevel.empty())
            ans.insert(ans.begin(), currLevel);
    }

    return ans;
}

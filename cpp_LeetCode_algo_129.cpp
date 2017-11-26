#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void DFS(TreeNode* root, string& pathIntStr, vector<string>& collection);
void DFS(TreeNode* root, int& pathInt, int& ans);
int sumNumbers(TreeNode* root);

int main(){
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    TreeNode n5(5);
    TreeNode n6(6);
    TreeNode n7(7);

    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.left = &n6;
    n3.right = &n7;

//    string pathIntStr;
//    vector<string> collection;
//    DFS(&n1, pathIntStr, collection);
//
//    for(auto each : collection){
//        cout << each << endl;
//    }

//    int ans = 0;
//    int pathInt = 0;
//    DFS(&n1, pathInt, ans);
    cout << sumNumbers(&n1) << endl;

    return 0;
}


int sumNumbers(TreeNode* root) {
    int ans = 0;
    int pathInt = 0;
    DFS(root, pathInt, ans);
    return ans;
}


//void DFS(TreeNode* root, string& pathIntStr, vector<string>& collection){
//    if(!root){
//        return;
//    }
//
//    pathIntStr.push_back(root->val+'0');
//    if(!root->left && !root->right){
//        collection.push_back(pathIntStr);
//    }
//    else if(root->left && !root->right){
//        DFS(root->left, pathIntStr, collection);
//    }
//    else if(!root->left && root->right){
//        DFS(root->right, pathIntStr, collection);
//    }
//    else{
//        DFS(root->left, pathIntStr, collection);
//        DFS(root->right, pathIntStr, collection);
//    }
//
//    pathIntStr.pop_back();
//    return;
//}



void DFS(TreeNode* root, int& pathInt, int& ans){
    if(!root){
        return;
    }

    pathInt *= 10;
    pathInt += root->val;
    if(!root->left && !root->right){
        ans += pathInt;
    }
    else if(root->left && !root->right){
        DFS(root->left, pathInt, ans);
    }
    else if(!root->left && root->right){
        DFS(root->right, pathInt, ans);
    }
    else{
        DFS(root->left, pathInt, ans);
        DFS(root->right, pathInt, ans);
    }

    pathInt -= root->val;
    pathInt /= 10;
    return;
}



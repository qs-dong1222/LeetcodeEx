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

bool isValidBST(TreeNode* root);
int minBST(TreeNode* root);
int maxBST(TreeNode* root);

unordered_map<int, int> minMap, maxMap;
unordered_map<int, bool> validMap;

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


    cout << isValidBST(&n1) << endl;
//    cout << minBST(&n1) << endl;
//    cout << maxBST(&n1) << endl;

    return 0;
}


bool isValidBST(TreeNode* root) {
    int key = (int)root;
    if(validMap.count(key)) return validMap[key];

    if(!root){ // 结点不存在时， 肯定是valid
        validMap[key] = true;
        return validMap[key];
    }

    //左子树是否有效
    bool isLeftValid = false;
    if(root->left){
        //左子树存在时, 需要满足: 1)其树本身有效. 2)其树最上面根结点的值 < root->val. 3)其树中最大值 < root->val.
        isLeftValid = isValidBST(root->left)
                    && (root->left->val < root->val)
                    && (maxBST(root->left) < root->val);
    }
    else{
        //左子树不存在时, 肯定满足条件
        isLeftValid = true;
    }

    bool isRightValid = false;
    if(root->right){
        isRightValid = isValidBST(root->right)
                    && (root->right->val > root->val)
                    && (minBST(root->right) > root->val);
    }
    else{
        isRightValid = true;
    }

    validMap[key] = (isRightValid && isLeftValid);
    return validMap[key];
}

/*
找树里的最小值
*/
int minBST(TreeNode* root){
    int key = (int)root;
    if(minMap.count(key))
        return minMap[key];

    if(!root){
        minMap[key] = INT_MAX;
        return minMap[key];
    }

    minMap[key] = min(min(minBST(root->left), minBST(root->right)), root->val);
    return minMap[key];
}

/*
找树里的最大值
*/
int maxBST(TreeNode* root){
    int key = (int)root;
    if(maxMap.count(key))
        return maxMap[key];

    if(!root){
        maxMap[key] = INT_MIN;
        return maxMap[key];
    }

    maxMap[key] = max(max(maxBST(root->left), maxBST(root->right)), root->val);
    return maxMap[key];
}

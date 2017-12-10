#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        if(root){
            buildNextTree(root);
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }

    /** @return the next smallest number */
    int next() {
        if(hasNext()){
            TreeNode* nextNode = stk.top();
            stk.pop();
            return nextNode->val;
        }
        else{
            return 0;
        }
    }


private:
    stack<TreeNode*> stk;

    void buildNextTree(TreeNode* root){
        if(!root){
            return;
        }

        buildNextTree(root->right);
        stk.push(root);
        buildNextTree(root->left);
    }

};


int main(){
    TreeNode* root = NULL;

    BSTIterator i = BSTIterator(root);

    while (i.hasNext()) cout << i.next();
    return 0;
}


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


TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);
int FindIndex(vector<int>& inorder, int istart, int iend, int target);
void Traverse(TreeNode* root);
TreeNode* GetTree(vector<int>& preorder, int pstart, int pend,
                    vector<int>& inorder, int istart, int iend);

int main(){
    vector<int> preorder = {-1};
    vector<int> inorder = {-1};

//    TreeNode* root = buildTree(preorder, inorder);
//
//    Traverse(root);

    return 0;
}



//TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//    if(preorder.empty() || inorder.empty()) return NULL;
//
//    int rootVal = preorder[0];
//    TreeNode* root = new TreeNode(rootVal);
//
//    int inOrderRootIdx = FindIndex(inorder, rootVal);
//
//    if(inOrderRootIdx-1>=0 && inOrderRootIdx<preorder.size() && preorder.size()>=2){
//        vector<int> inorderLeft(inorder.begin(), inorder.begin()+inOrderRootIdx-1);
//        vector<int> preorderLeft(preorder.begin()+1, preorder.begin()+inOrderRootIdx);
//        root->left = buildTree(preorderLeft, inorderLeft);
//    }
//
//    if(inOrderRootIdx+1<inorder.size() && inOrderRootIdx+1<preorder.size() && preorder.size()>=2 && inorder.size()>=2){
//        vector<int> inorderRight(inorder.begin()+inOrderRootIdx+1, inorder.end());
//        vector<int> preorderRight(preorder.begin()+inOrderRootIdx+1, preorder.end());
//        root->right = buildTree(preorderRight, inorderRight);
//    }
//
//    return root;
//}


TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return GetTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
}

TreeNode* GetTree(vector<int>& preorder, int pstart, int pend,
                    vector<int>& inorder, int istart, int iend) {
    if(preorder.empty() || inorder.empty()) return NULL;
    if(pstart>pend || istart>iend) return NULL;

    int rootVal = preorder[pstart];
    TreeNode* root = new TreeNode(rootVal);

    int inOrderRootIdx = FindIndex(inorder, istart, iend, rootVal);

    // left subtree
    root->left = GetTree(preorder, pstart+1, pstart+inOrderRootIdx, inorder, istart, inOrderRootIdx-1);
    // right subtree
    root->right = GetTree(preorder, pstart+inOrderRootIdx+1, pend, inorder, inOrderRootIdx+1, iend);

    return root;
}


int FindIndex(vector<int>& inorder, int istart, int iend, int target){
    int i=istart;
    while(inorder[i] != target && i<iend) i++;
    return i;
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

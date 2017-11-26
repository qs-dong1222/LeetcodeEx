#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> genVec(int n);
vector<TreeNode*> F(vector<int>& nums, int lidx, int ridx);
void Traverse(TreeNode* root);

int main(){

    vector<int> nums = genVec(3);

    vector<TreeNode*> ansTrees = F(nums, 0, nums.size()-1);

    for(auto eachTree : ansTrees){
        Traverse(eachTree);
        cout << endl;
    }

    return 0;
}

/*
此题作为96题的一个变形，不同之处就是要储存各个步骤的结果
函数 F(vector<int>& nums, int lidx, int ridx) 的作用是:
返回 nums[lidx]~nums[ridx] 中各个结点独立作为根结点时的所有subtree
*/
vector<TreeNode*> F(vector<int>& nums, int lidx, int ridx){
    vector<TreeNode*> ansTrees;
    TreeNode* root = NULL;

    if(ridx<lidx){
        ansTrees.push_back(NULL);
        return ansTrees;
    }

    if(lidx == ridx){
        TreeNode* signleRoot = new TreeNode(nums[lidx]);
        ansTrees.push_back(signleRoot);
        return ansTrees;
    }

    for(int i=lidx; i<=ridx; i++){
        vector<TreeNode*> leftSubTrees = F(nums, lidx, i-1);
        vector<TreeNode*> rightSubTrees = F(nums, i+1, ridx);
        for(auto eachLeft : leftSubTrees){
            for(auto eachRight : rightSubTrees){
                // 必须要把 root = new TreeNode(nums[i]); 写在这个地方
                // 原因: 如果写在别的地方，程序无法每次都生成一个新的独立的空间地址，
                // 反之若是不这么做的话，之后我们会在循环里不停的更改root的内容。
                // 那么即使之前的loop向ansTree存进去了计算好的结果，由于我们没有生成
                // 独立的新地址，在ansTree的内容也会跟着外部指针内容改变而改变，因为都指的是一个地方。
                root = new TreeNode(nums[i]);
                root->left = eachLeft;
                root->right = eachRight;
                ansTrees.push_back(root);
            }

        }
    }

    return ansTrees;
}




vector<int> genVec(int n){
    vector<int> ans;
    if(n==0) return ans;

    for(int i=1;i<=n;i++)
        ans.push_back(i);
    return ans;
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

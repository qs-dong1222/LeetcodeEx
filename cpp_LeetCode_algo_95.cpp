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
//vector<TreeNode*> F(vector<int>& nums, int lidx, int ridx);

vector<TreeNode*> generateTrees(int n);
vector<TreeNode*> AllSubtreesGivenNums(vector<int>& nums, int l_end, int r_end);
void Traverse(TreeNode* root);

int main(){
    vector<TreeNode*> ansTrees = generateTrees(0);

    for(auto eachTree : ansTrees){
        Traverse(eachTree);
        cout << endl;
    }

    return 0;
}



vector<int> genVec(int n){
    vector<int> ans;
    if(n==0) return ans;

    for(int i=1;i<=n;i++)
        ans.push_back(i);
    return ans;
}

vector<TreeNode*> generateTrees(int n) {
    vector<int> nums = genVec(n);
    if(n==0) return vector<TreeNode*>(0);
    return AllSubtreesGivenNums(nums, 0, nums.size()-1);
}

/*
思路就是dp:
思路怎么构建起来的?
题目的结果要求一个树根节点的集合, 那也就是说我们要先找到所有的子树组合, 再把一个个根节点放到
这个结果集合里.

这个题用dfs并不好解, 因为dfs会一步步走到叶节点上, 而到了那时, 我们就很难再找到最初的根节点进行返回.
所以放弃dfs的方法. 即从叶到根的这种bottom-up的方法.

那剩下的就是 "固定根节点, 并连接子树到根节点" 的这种top-down的思路.
即 找一个根节点, 把它所有的左/右子树全部找出来, 再一个个接到根节点上, 并返回根节点.

那么就有了下面这个函数:
AllSubtreesGivenNums(vector<int>& nums, int l_end, int r_end)
这个函数会返回 以nums[l_end : r_end]所含元素构成的所有子树集合.
实现方法是: 遍历数组的所有元素, 以nums[i]作为根节点,
进一步递归调用AllSubtreesGivenNums(nums, l_end, i-1) 和 AllSubtreesGivenNums(nums, i+1, r_end)
去构建子树集合.
*/
vector<TreeNode*> AllSubtreesGivenNums(vector<int>& nums, int l_end, int r_end){
    vector<TreeNode*> allTrees;

    if(l_end > r_end){
        allTrees.push_back(NULL);
        return allTrees;
    }

    for(int i=l_end; i<=r_end; i++){
        // TreeNode* root = new TreeNode(nums[i]); 不能写在这里, 答案集合中的元素会共享指针
        vector<TreeNode*> allLeftSubtrees = AllSubtreesGivenNums(nums, l_end, i-1);
        vector<TreeNode*> allRightSubtrees = AllSubtreesGivenNums(nums, i+1, r_end);
        for(auto rightTree : allRightSubtrees){
            for(auto leftTree : allLeftSubtrees){
                // 必须要把 root = new TreeNode(nums[i]); 写在这个地方
                // 原因: 如果写在别的地方，所有在allTrees集合里的元素的root都会共享一个指针
                // 之后我们会在循环里不停的更改root的内容。
                // 那么即使之前向ansTree存进去了计算好的结果也会跟着外部指针内容改变而改变，
                // 因为都指的是一个地方。
                TreeNode* root = new TreeNode(nums[i]);
                root->right = rightTree;
                root->left = leftTree;
                allTrees.push_back(root);
            }
        }
    }

    return allTrees;
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

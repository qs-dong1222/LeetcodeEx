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
˼·����dp:
˼·��ô����������?
��Ŀ�Ľ��Ҫ��һ�������ڵ�ļ���, ��Ҳ����˵����Ҫ���ҵ����е��������, �ٰ�һ�������ڵ�ŵ�
������������.

�������dfs�����ý�, ��Ϊdfs��һ�����ߵ�Ҷ�ڵ���, ��������ʱ, ���Ǿͺ������ҵ�����ĸ��ڵ���з���.
���Է���dfs�ķ���. ����Ҷ����������bottom-up�ķ���.

��ʣ�µľ��� "�̶����ڵ�, ���������������ڵ�" ������top-down��˼·.
�� ��һ�����ڵ�, �������е���/������ȫ���ҳ���, ��һ�����ӵ����ڵ���, �����ظ��ڵ�.

��ô�����������������:
AllSubtreesGivenNums(vector<int>& nums, int l_end, int r_end)
��������᷵�� ��nums[l_end : r_end]����Ԫ�ع��ɵ�������������.
ʵ�ַ�����: �������������Ԫ��, ��nums[i]��Ϊ���ڵ�,
��һ���ݹ����AllSubtreesGivenNums(nums, l_end, i-1) �� AllSubtreesGivenNums(nums, i+1, r_end)
ȥ������������.
*/
vector<TreeNode*> AllSubtreesGivenNums(vector<int>& nums, int l_end, int r_end){
    vector<TreeNode*> allTrees;

    if(l_end > r_end){
        allTrees.push_back(NULL);
        return allTrees;
    }

    for(int i=l_end; i<=r_end; i++){
        // TreeNode* root = new TreeNode(nums[i]); ����д������, �𰸼����е�Ԫ�ػṲ��ָ��
        vector<TreeNode*> allLeftSubtrees = AllSubtreesGivenNums(nums, l_end, i-1);
        vector<TreeNode*> allRightSubtrees = AllSubtreesGivenNums(nums, i+1, r_end);
        for(auto rightTree : allRightSubtrees){
            for(auto leftTree : allLeftSubtrees){
                // ����Ҫ�� root = new TreeNode(nums[i]); д������ط�
                // ԭ��: ���д�ڱ�ĵط���������allTrees�������Ԫ�ص�root���Ṳ��һ��ָ��
                // ֮�����ǻ���ѭ���ﲻͣ�ĸ���root�����ݡ�
                // ��ô��ʹ֮ǰ��ansTree���ȥ�˼���õĽ��Ҳ������ⲿָ�����ݸı���ı䣬
                // ��Ϊ��ָ����һ���ط���
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

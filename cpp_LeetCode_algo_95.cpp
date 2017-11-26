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
������Ϊ96���һ�����Σ���֮ͬ������Ҫ�����������Ľ��
���� F(vector<int>& nums, int lidx, int ridx) ��������:
���� nums[lidx]~nums[ridx] �и�����������Ϊ�����ʱ������subtree
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
                // ����Ҫ�� root = new TreeNode(nums[i]); д������ط�
                // ԭ��: ���д�ڱ�ĵط��������޷�ÿ�ζ�����һ���µĶ����Ŀռ��ַ��
                // ��֮���ǲ���ô���Ļ���֮�����ǻ���ѭ���ﲻͣ�ĸ���root�����ݡ�
                // ��ô��ʹ֮ǰ��loop��ansTree���ȥ�˼���õĽ������������û������
                // �������µ�ַ����ansTree������Ҳ������ⲿָ�����ݸı���ı䣬��Ϊ��ָ����һ���ط���
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

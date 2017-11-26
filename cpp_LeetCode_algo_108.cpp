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

TreeNode* sortedArrayToBST(vector<int>& nums);
TreeNode* BuildTree(vector<int>& nums, int startIdx, int endIdx);
vector<vector<int>> levelOrder(TreeNode* root);





int main(){
    vector<int> nums = {1,3,4,5,6,7,9};
//    vector<int> nums = {0,1,2};

    TreeNode* root = sortedArrayToBST(nums);

    vector<vector<int>> ans = levelOrder(root);

    for(auto eachRow : ans){
        for(auto each : eachRow){
            cout << each << " ";
        }
        cout << endl;
    }

    return 0;
}


TreeNode* sortedArrayToBST(vector<int>& nums) {
    return BuildTree(nums, 0, nums.size()-1);
}


TreeNode* BuildTree(vector<int>& nums, int startIdx, int endIdx){
    if(endIdx<startIdx || nums.empty())
        return NULL;

    int mid = (startIdx+endIdx)>>1;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = BuildTree(nums, startIdx, mid-1);
    root->right = BuildTree(nums, mid+1, endIdx);

    return root;
}





vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(!root) return ans;

    vector<int> currLevel;
    queue<TreeNode*> qtree;

    TreeNode* curr;
    qtree.push(root);
    while(!qtree.empty()){
        currLevel.clear();

        for(int i=qtree.size()-1;i>=0;i--){
            curr = qtree.front();
            qtree.pop();
            if(curr) currLevel.push_back(curr->val);
            if(curr->left) qtree.push(curr->left);
            if(curr->right) qtree.push(curr->right);
        }
        if(!currLevel.empty()) ans.push_back(currLevel);
    }

    return ans;
}

///*
//找出树中node之和最大的path, 并返回且只返回此最大值，无需标注path nodes
//每个node不能访问两次
//*/
//
///*
//解法：
//弄一个函数f(node), 作用为返回此节点处能找到的最大值
//然后用总根节点层层递归即可，辅以memorization
//*/
//
//#include <iostream>
//#include <stdlib.h>
//#include <unordered_map>
//#include <list>
//#include <vector>
//#include <cmath>
//
//using namespace std;
//
//struct TreeNode{
//    int val;
//    TreeNode* pleft;
//    TreeNode* pright;
//};
//
//unordered_map<TreeNode*, int> resMap;
//
//int FindMaxSumAmongAllSubNodes(TreeNode* pnode);
//
//
//int main(){
//    // node 1
//    TreeNode node1;
//    node1.val = 5;
//    // node 2
//    TreeNode node2;
//    node2.val = 3;
//    // node 3
//    TreeNode node3;
//    node3.val = 2;
//    // node 4
//    TreeNode node4;
//    node4.val = -1;
//
//    // connection
//    node1.pleft = &node2;
//    node1.pright = &node3;
//    node2.pleft = NULL;
//    node2.pright = &node4;
//    node3.pleft = NULL;
//    node3.pright = NULL;
//    node4.pleft = NULL;
//    node4.pright = NULL;
//
//    cout<< FindMaxSumAmongAllSubNodes(&node1) << endl;
//
//    return 0;
//}
//
//
//
//int FindMaxSumAmongAllSubNodes(TreeNode* pnode){
//    // memorization
//    if(resMap.find(pnode) != resMap.cend()){
//        return resMap[pnode];
//    }
//
//
//    if(pnode->pleft == NULL && pnode->pright != NULL){
//        int ans = max(pnode->val + FindMaxSumAmongAllSubNodes(pnode->pright), pnode->val);
//        resMap[pnode] = ans;
//        return ans;
//    }
//    else if(pnode->pright == NULL && pnode->pleft != NULL){
//        int ans = max(pnode->val + FindMaxSumAmongAllSubNodes(pnode->pleft), pnode->val);
//        resMap[pnode] = ans;
//        return ans;
//    }
//    else if(pnode->pright == NULL && pnode->pleft == NULL){
//        int ans = pnode->val;
//        resMap[pnode] = ans;
//        return ans;
//    }
//    else{
//        int only_node = pnode->val;
//        int node_left = pnode->val + FindMaxSumAmongAllSubNodes(pnode->pleft);
//        int node_right = pnode->val + FindMaxSumAmongAllSubNodes(pnode->pright);
//        int node_l_r = node_left+node_right - pnode->val;
//        int ans = max(max(only_node, node_l_r), max(node_left, node_right));
//        resMap[pnode] = ans;
//        return ans;
//    }
//}





#include <iostream>
#include <vector>

using namespace  std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxPathSum(TreeNode* root);
int GetMaxSubPathSum(TreeNode* root, int& ans);

int main(){
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    TreeNode n5(-5);

    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n3.right = &n5;


    cout << maxPathSum(&n1) << endl;

    return 0;
}




int maxPathSum(TreeNode* root){
    if(!root)
        return 0;

    int ans = INT_MIN;
    GetMaxSubPathSum(root, ans);

    return ans;
}

/*
解法思路:
一个path有两种构成选择，一个是单独一条支线上来，另一个是在某一个节点形成汇合状。
要想当前节点可以向上传递，必须是当前节点的值+下属单独支线。同时我们还要考虑当前节点形成汇合状的情况。
如果当前节点汇合了，此节点就不能向上传递。
所以需要两种操作，一个操作负责统计各个节点做汇合状时的最大值，另一个操作负责单支线路向上传递.
*/
int GetMaxSubPathSum(TreeNode* root, int& ans) {
    if(!root)
        return 0;

    // 左子树的path sum，只有大于等于0时才有效，小于0就舍弃
    int fromLeft = max(0, GetMaxSubPathSum(root->left, ans));
    // 右子树的path sum，只有大于等于0时才有效，小于0就舍弃
    int fromRight = max(0, GetMaxSubPathSum(root->right, ans));

    // 统计最大的汇合状path情况
    ans = max(fromLeft+fromRight+root->val, ans);

    // 返回可用于连接上一层的path sum
    return root->val + max(fromLeft, fromRight);
}








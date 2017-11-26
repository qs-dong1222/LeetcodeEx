///*
//�ҳ�����node֮������path, ��������ֻ���ش����ֵ�������עpath nodes
//ÿ��node���ܷ�������
//*/
//
///*
//�ⷨ��
//Ūһ������f(node), ����Ϊ���ش˽ڵ㴦���ҵ������ֵ
//Ȼ�����ܸ��ڵ���ݹ鼴�ɣ�����memorization
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
�ⷨ˼·:
һ��path�����ֹ���ѡ��һ���ǵ���һ��֧����������һ������ĳһ���ڵ��γɻ��״��
Ҫ�뵱ǰ�ڵ�������ϴ��ݣ������ǵ�ǰ�ڵ��ֵ+��������֧�ߡ�ͬʱ���ǻ�Ҫ���ǵ�ǰ�ڵ��γɻ��״�������
�����ǰ�ڵ����ˣ��˽ڵ�Ͳ������ϴ��ݡ�
������Ҫ���ֲ�����һ����������ͳ�Ƹ����ڵ������״ʱ�����ֵ����һ����������֧��·���ϴ���.
*/
int GetMaxSubPathSum(TreeNode* root, int& ans) {
    if(!root)
        return 0;

    // ��������path sum��ֻ�д��ڵ���0ʱ����Ч��С��0������
    int fromLeft = max(0, GetMaxSubPathSum(root->left, ans));
    // ��������path sum��ֻ�д��ڵ���0ʱ����Ч��С��0������
    int fromRight = max(0, GetMaxSubPathSum(root->right, ans));

    // ͳ�����Ļ��״path���
    ans = max(fromLeft+fromRight+root->val, ans);

    // ���ؿ�����������һ���path sum
    return root->val + max(fromLeft, fromRight);
}








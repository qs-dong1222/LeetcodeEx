#include <iostream>
#include <stdlib.h>
#include <unordered_map>
#include <list>
#include <vector>
#include <cmath>
#include <sstream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* pleft;
    TreeNode* pright;
};

TreeNode* String2Tree(stringstream& inStr);
int FindMaxUnivaluePathLength(TreeNode* pnode);

int main(){
    stringstream xstr;
//    xstr << "2 6 6 3 $ $ 6 $ $ 7 $ $ 7 $ 2 2 $ $ 9 $ $";
    xstr << "5 5 $ $ 3 $ $";
    TreeNode* xnode = String2Tree(xstr);

    int maxlen = FindMaxUnivaluePathLength(xnode);
    cout << maxlen <<endl;

    return 0;
}



int FindMaxUnivaluePathLength(TreeNode* pnode){
    if(pnode == NULL){
        return 0;
    }

    if(pnode->pleft == NULL && pnode->pright == NULL){
        return 1;
    }

    if(pnode->pleft == NULL && pnode->pright != NULL){
        if( pnode->val == pnode->pright->val){
            int pathLen = FindMaxUnivaluePathLength(pnode->pright) + 1;
            return pathLen;
        }
        else{
            int pathLen = FindMaxUnivaluePathLength(pnode->pright);
            return pathLen;
        }
    }

    if(pnode->pright == NULL && pnode->pleft != NULL){
        if(pnode->val == pnode->pleft->val){
            int pathLen = FindMaxUnivaluePathLength(pnode->pleft) + 1;
            return pathLen;
        }
        else{
            int pathLen = FindMaxUnivaluePathLength(pnode->pleft);
            return pathLen;
        }
    }

    if(pnode->val == pnode->pleft->val && pnode->val != pnode->pright->val){
        int pathLen = FindMaxUnivaluePathLength(pnode->pleft) + 1;
        return pathLen;
    }
    else if(pnode->val != pnode->pleft->val && pnode->val == pnode->pright->val){
        int pathLen = FindMaxUnivaluePathLength(pnode->pright) + 1;
        return pathLen;
    }
    else if(pnode->val != pnode->pleft->val && pnode->val != pnode->pright->val){
        int pathLen = max(FindMaxUnivaluePathLength(pnode->pright), FindMaxUnivaluePathLength(pnode->pleft));
        return pathLen;
    }
    else{
        int pathLen = FindMaxUnivaluePathLength(pnode->pright) + FindMaxUnivaluePathLength(pnode->pleft) + 1;
        return pathLen;
    }

}










/*
String2Tree函数作用:
从stringstream 里抽一个有效substring，如果此substring不是"$"，就建立一个树节点, 并返回此节点地址
*/
TreeNode* String2Tree(stringstream& inStr){
    string str;
    inStr >> str;
    if(str != "$"){
        TreeNode* pnode = new TreeNode;
        pnode->val = atoi(str.c_str());
        pnode->pleft = String2Tree(inStr);
        pnode->pright = String2Tree(inStr);
        return pnode;
    }
    else{
        return NULL;
    }
}

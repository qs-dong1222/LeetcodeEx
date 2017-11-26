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

unordered_map<TreeNode*, vector<int> > resMap;

vector<int> FindMaxLinkedSubnodes(TreeNode* pnode);
TreeNode* String2Tree(stringstream& inStr);

int main(){
    stringstream xstr;
    xstr << "6 7 $ $ 10 $ 9 $ $";
    TreeNode* xnode = String2Tree(xstr);

    vector<int> pathnodes(FindMaxLinkedSubnodes(xnode));

    for(auto& each : pathnodes){
        cout << each << " ";
    }
    cout << endl;
    cout << "longest path size = " << pathnodes.size()-1 <<endl;

    return 0;
}



vector<int> FindMaxLinkedSubnodes(TreeNode* pnode){
    // memorization
    if(resMap.find(pnode) != resMap.cend()){
        return resMap[pnode];
    }


    if(pnode->pleft == NULL && pnode->pright == NULL){
        vector<int> pathNodes;
        pathNodes.push_back(pnode->val);
        resMap[pnode] = pathNodes;
        return  pathNodes;
    }
    else if(pnode->pleft == NULL && pnode->pright != NULL){
        vector<int> pathNodes( FindMaxLinkedSubnodes(pnode->pright) );
        pathNodes.insert(pathNodes.begin(), pnode->val);
        resMap[pnode] = pathNodes;
        return pathNodes;
    }
    else if(pnode->pleft != NULL && pnode->pright == NULL){
        vector<int> pathNodes( FindMaxLinkedSubnodes(pnode->pleft) );
        pathNodes.push_back(pnode->val);
        resMap[pnode] = pathNodes;
        return pathNodes;
    }
    else{
        vector<int> leftPathNodes = FindMaxLinkedSubnodes(pnode->pleft);
        vector<int> rightPathNodes = FindMaxLinkedSubnodes(pnode->pright);
        leftPathNodes.push_back(pnode->val);
        leftPathNodes.insert(leftPathNodes.end(), rightPathNodes.begin(), rightPathNodes.end());
        resMap[pnode] = leftPathNodes;
        return leftPathNodes;
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

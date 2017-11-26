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

string Tree2String(TreeNode* pnode, stringstream& outStr);
TreeNode* String2Tree(stringstream& inStr);

int main(){
    stringstream xstr;
    xstr << "6 7 $ $ 10 $ 9 $ $";
    TreeNode* xnode = String2Tree(xstr);

    stringstream out;
    string outStr = Tree2String(xnode, out);
    cout << outStr <<endl;

    return 0;
}


/*
以前序遍历的方式去构建一个从树中抽取data，并构建data sequence
*/
string Tree2String(TreeNode* pnode, stringstream& outStr){
    if(pnode != NULL){
        outStr << pnode->val << " ";
        Tree2String(pnode->pleft, outStr);
        Tree2String(pnode->pright, outStr);
    }
    else{
        outStr << '$' << " ";
    }

    return outStr.str();
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

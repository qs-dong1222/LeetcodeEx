#include <iostream>
#include <vector>
#include <queue>

using namespace std;

 struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };

 void connect(TreeLinkNode *root);

int main(){

    return 0;
}


void connect(TreeLinkNode *root) {
    queue<TreeLinkNode*> q;

    TreeLinkNode* curr;
    q.push(root);
    while(!q.empty()){

        int qsize = q.size();
        for(int i=q.size()-1;i>=0;i--){
            curr = q.front();
            q.pop();
            qsize--;
            if(curr){
                if(qsize > 0)
                    curr->next = q.front();
                else
                    curr->next = NULL;

                q.push(curr->left);
                q.push(curr->right);
            }
        }
    }
}



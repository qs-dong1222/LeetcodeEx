#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int main(){


    return 0;
}


ListNode* removeNthFromEnd(ListNode* head, int n) {
    vector<ListNode*> pnode;
    ListNode* ptemp = head;

    while(ptemp->next != NULL){
        pnode.push_back(ptemp);
        ptemp = ptemp->next;
    }
    pnode.push_back(ptemp);

    int size = pnode.size();
    if(size <= 1){
        return NULL;
    }
    if(n == size){
        delete pnode[0];
        return pnode[1];
    }
    if(n == 1){
        pnode[size-n-1]->next = NULL;
        return head;
    }

    pnode[size-n-1]->next = pnode[size-n+1];
    delete pnode[size-n];
    return head;
}


#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n);

int main(){

    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    ListNode n5(5);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    ListNode* p = removeNthFromEnd(&n1, 2);

    while(p){
        cout << p->val << " ";
        p = p->next;
    }

    return 0;
}








ListNode* removeNthFromEnd(ListNode* head, int n){
    if(!head) return head;

    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode* p = dummyHead;

    int count = 0;
    unordered_map<int, ListNode*> nodes;
    while(p){
        nodes[count] = p;
        p = p->next;
        count++;
    }

    // nodes[count-n-1] is the node before the removal node
    nodes[count-n-1]->next = nodes[count-n]->next;
    return dummyHead->next;
}














//ListNode* removeNthFromEnd(ListNode* head, int n) {
//    vector<ListNode*> pnode;
//    ListNode* ptemp = head;
//
//    while(ptemp->next != NULL){
//        pnode.push_back(ptemp);
//        ptemp = ptemp->next;
//    }
//    pnode.push_back(ptemp);
//
//    int size = pnode.size();
//    if(size <= 1){
//        return NULL;
//    }
//    if(n == size){
//        delete pnode[0];
//        return pnode[1];
//    }
//    if(n == 1){
//        pnode[size-n-1]->next = NULL;
//        return head;
//    }
//
//    pnode[size-n-1]->next = pnode[size-n+1];
//    delete pnode[size-n];
//    return head;
//}


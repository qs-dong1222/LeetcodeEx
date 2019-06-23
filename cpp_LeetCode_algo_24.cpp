
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head);

int main(){

    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    ListNode n5(5);
    ListNode n6(6);
    ListNode n7(7);
    ListNode n8(8);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n7;


    ListNode* p = swapPairs(&n1);
    while(p){
        cout << p->val << " ";
        p = p->next;
    }

    return 0;
}



/*
    solution 1
*/
//ListNode* swapPairs(ListNode* head) {
//    if(!head) return head;
//
//    ListNode* dummyHead = new ListNode(0);
//    dummyHead->next = head;
//    ListNode* p = dummyHead;
//
//    while(p->next && p->next->next){
//        ListNode* t1 = p->next->next->next;
//        p->next->next->next = p->next;
//        ListNode* t2 = p->next;
//        p->next = p->next->next;
//        t2->next = t1;
//
//        p = p->next->next;
//    }
//
//    return dummyHead->next;
//}


/*
    solutioin 2: recurrsion method
*/
ListNode* swapPairs(ListNode* head) {
    if(!head || !head->next) return head;

    ListNode* tmp = head->next;

    head->next = head->next->next;
    tmp->next = head;

    tmp->next->next = swapPairs(tmp->next->next);

    return tmp;
}

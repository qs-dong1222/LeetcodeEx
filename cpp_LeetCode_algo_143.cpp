#include <iostream>
#include <vector>

using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

 ListNode* Reverse(ListNode* head);
 void reorderList(ListNode* head);

 int main(){
    ListNode n0(1);
    ListNode n1(2);
    ListNode n2(3);
    ListNode n3(4);
    ListNode n4(5);
    ListNode n5(6);

    n0.next = &n1;
//    n1.next = &n2;
//    n2.next = &n3;
//    n3.next = &n4;
//    n4.next = &n5;

    reorderList(&n0);
    ListNode* p = &n0;
    while(p){
        cout << p->val << " ";
        p = p->next;
    }

 }

 void reorderList(ListNode* head){
    if(!head) return;

    ListNode* p1 = head;
    ListNode* p2 = head;

    // find middle position
    while(p2->next && p2->next->next){
        p2 = p2->next->next;
        p1 = p1->next;
    }
    // p2 is middle, p1 is head, 2 lists
    p2 = p1->next;
    p1->next = NULL;
    p1 = head;

    p2 = Reverse(p2);

    // merge 2 sublists
    ListNode* tmp;
    while( !(!p1 && !p2) ){
        if(p1){
            tmp = p1->next;
            p1->next = p2;
            p1 = tmp;
        }

        if(p2){
            tmp = p2->next;
            p2->next = p1;
            p2 = tmp;
        }
    }
 }



 ListNode* Reverse(ListNode* head){
    if(!head || !head->next) return head;

    ListNode *p, *q, *r;
    p = head;
    q = head->next;
    r = head->next;

    p->next = NULL;
    while(r->next){
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    r->next = p;
    return r;
 }


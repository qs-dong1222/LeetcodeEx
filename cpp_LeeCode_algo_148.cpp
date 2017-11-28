#include <iostream>
#include <vector>

using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* sortList(ListNode* head);

 int main(){
    ListNode n0(3);
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(6);
    ListNode n4(4);
    ListNode n5(5);

    n0.next = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    ListNode* p = sortList(&n0);

    while(p){
        cout << p->val << " ";
        p = p->next;
    }

    return 0;
 }


ListNode* sortList(ListNode* head) {
    if(!head) return head;
    ListNode* p = head;
    ListNode* q = head->next;
    while(p && p->next){
        q = p->next;
        while(q){
            if(p->val > q->val){
                int tmp = q->val;
                q->val = p->val;
                p->val = tmp;
            }
            q = q->next;
        }
        p = p->next;
    }

    return head;
}





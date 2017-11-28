#include <iostream>
#include <vector>

using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* sortList(ListNode* head);
ListNode* Merge(ListNode* leftHead, ListNode* rightHead);
ListNode* Split(ListNode* head);

 int main(){
    ListNode n0(3);
    ListNode n1(6);
    ListNode n2(1);
    ListNode n3(2);
    ListNode n4(7);
    ListNode n5(9);

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



/*
Merge sort: o(nlogn)
*/
ListNode* sortList(ListNode* head){
    if(!head || !head->next) return head;

    ListNode* second = Split(head);
    return Merge(sortList(head), sortList(second));
}

 ListNode* Split(ListNode* head){
    if(!head) return head;

    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next && fast->next->next){
        fast = fast->next->next;
        slow = slow->next;
    }

    ListNode* second = slow->next;
    slow->next = NULL;

    if(!second && head){
        // only one node
        second = head;
    }
    return second;
 }

 ListNode* Merge(ListNode* leftHead, ListNode* rightHead){
    if(leftHead == rightHead) return leftHead;

    ListNode* dummyHead = new ListNode(0);
    ListNode* head = dummyHead;

    while(leftHead && rightHead){
        if(rightHead->val <= leftHead->val){
            head->next = rightHead;
            rightHead = rightHead->next;
        }
        else{
            head->next = leftHead;
            leftHead = leftHead->next;
        }
        head = head->next;
    }

    if(leftHead){
        head->next = leftHead;
    }
    else{
        head->next = rightHead;
    }

    head = dummyHead->next;
    delete dummyHead;
    return head;
 }




 /*
 select sort, o(n^2)
 */
//ListNode* sortList(ListNode* head) {
//    if(!head) return head;
//    ListNode* p = head;
//    ListNode* q = head->next;
//    while(p && p->next){
//        q = p->next;
//        while(q){
//            if(p->val > q->val){
//                int tmp = q->val;
//                q->val = p->val;
//                p->val = tmp;
//            }
//            q = q->next;
//        }
//        p = p->next;
//    }
//
//    return head;
//}





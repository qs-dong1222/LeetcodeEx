#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

int main(){
    ListNode l10(5);
//    ListNode l11(4);
//    ListNode l12(3);
//    l10.next = &l11;
//    l11.next = &l12;

    ListNode l20(5);
//    ListNode l21(6);
//    ListNode l22(4);
//    l20.next = &l21;
//    l21.next = &l22;

    ListNode* p = addTwoNumbers(&l10, &l20);

    while(p){
        cout << p->val << " ";
        p = p->next;
    }

    return 0;
}



/*
solution 1: 思路清晰版
*/
//ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//    if(!l1) return l2;
//    if(!l2) return l1;
//
//    int carry = 0;
//    int bitsum = 0;
//    ListNode* dummyHead = new ListNode(0);
//    ListNode* p = dummyHead;
//    while(l1 && l2){
//        bitsum = (l1->val + l2->val + carry) % 10;
//        p->next = new ListNode(bitsum);
//        carry = (l1->val + l2->val + carry) / 10;
//
//        p = p->next;
//        l1 = l1->next;
//        l2 = l2->next;
//    }
//
//    if(!l2){
//        // l1 is longer
//        while(l1){
//            bitsum = (l1->val + carry) % 10;
//            p->next = new ListNode(bitsum);
//            carry = (l1->val + carry) / 10;
//
//            p = p->next;
//            l1 = l1->next;
//        }
//    }
//
//    if(!l1){
//        // l2 is longer
//        while(l2){
//            bitsum = (l2->val + carry) % 10;
//            p->next = new ListNode(bitsum);
//            carry = (l2->val + carry) / 10;
//
//            p = p->next;
//            l2 = l2->next;
//        }
//    }
//
//    // MSB carry bit
//    if(carry>0){
//        p->next = new ListNode(carry);
//    }
//
//    return dummyHead->next;
//}



/*
solution 2: 精简版, 手动为短的list空位补零
*/
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if(!l1) return l2;
    if(!l2) return l1;

    int carry = 0;
    int bitsum = 0;

    ListNode* dummyHead = new ListNode(0);
    ListNode* p = dummyHead;

    while(l1 || l2 || carry){
        int val_1 = l1? l1->val:0;
        int val_2 = l2? l2->val:0;
        bitsum = (val_1 + val_2 + carry) % 10;
        p->next = new ListNode(bitsum);
        carry = (val_1 + val_2 + carry) / 10;

        p = p->next;
        l1 = l1? l1->next:NULL;
        l2 = l2? l2->next:NULL;
    }

    return dummyHead->next;
}

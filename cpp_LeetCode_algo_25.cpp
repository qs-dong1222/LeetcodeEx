#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseKnodes(ListNode* head, int k);
ListNode* reverseKGroup(ListNode* head, int k);
void printList(ListNode* head);

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

    ListNode* p = reverseKGroup(&n1, 3);
    printList(p);


    return 0;
}




/*
solution: 利用递归，从最后一个可以进行reverse的sublist先执行reverse，再层层向前递归
*/
ListNode* reverseKGroup(ListNode* head, int k) {
    if(!head || k<=1) return head;

    ListNode* p = head;
    int count = 0;
    while(p && count < k-1){
        count++;
        p = p->next;
    }

    if(p && count == k-1){
        if(p->next){
            p->next = reverseKGroup(p->next, k);
        }
        head = reverseKnodes(head, k);
    }

    return head;
}



ListNode* reverseKnodes(ListNode* head, int k) {
    if(!head || k<=1) return head;

    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* p = dummy;
    ListNode* q = dummy->next;
    ListNode* g = q;
    while(g && k>0){
        k--;
        g = g->next;
    }
    if(k>0) return head;

    while(q!=g){
        ListNode* t = q->next;
        q->next = p;
        p=q;
        q=t;
    }

    dummy->next->next = g;
    dummy->next = p;
    return dummy->next;
}



void printList(ListNode* head){
    ListNode* p = head;
    while(p){
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}


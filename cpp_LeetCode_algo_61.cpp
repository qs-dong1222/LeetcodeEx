#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* rotateRight(ListNode* head, int k);

int main(){
    ListNode n0(0);
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    ListNode n5(5);
    ListNode n6(6);
    n0.next = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;

    ListNode* p = rotateRight(&n0, 10);
    while(p){
        cout << p->val << endl;
        p = p->next;
    }

    return 0;
}



/*
solution 1 : 利用循环链表解题
*/
ListNode* rotateRight(ListNode* head, int k) {
    if(!head || k==0) return head;

    ListNode* p = head;
    int len=1;
    while(p->next){
        len++;
        p = p->next;
    }
    p->next = head; // circle it

    int cnt = 0;
    k = k % len;
    while(head){
        cnt++;
        if(cnt == len-k) break;
        head = head->next;
    }

    ListNode* tmp = head->next;
    head->next = NULL;
    head = tmp;
    return head;
}






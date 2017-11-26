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

    rotateRight(&n0, 1);

    return 0;
}



/*
利用循环链表解题
*/
ListNode* rotateRight(ListNode* head, int k) {
    if(head==NULL || head->next==NULL || k==0)
        return head;

    ListNode* lastP = head;
    int cnt=1;
    while(lastP->next != NULL){
        lastP = lastP->next;
        cnt++;
    }
    lastP->next = head;
    ListNode* firstP = head;

    k %= cnt; // 防止 k > list.size() 的情况, 例如size=2，k=3，相当于k=1
    while((cnt-k++) > 0){
        firstP = firstP->next;
        lastP = lastP->next;
    }
    lastP->next = NULL;

    return firstP;
}

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
solution 1 的思路清晰写法: 利用循环链表解题
*/
ListNode* rotateRight(ListNode* head, int k) {
    if(!head) return head;

    ListNode *dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode *p = dummyHead;

    // 统计链表尺寸, 同时找到最后一个元素
    int sizeCnt = 0;
    while(p->next){
        p = p->next;
        sizeCnt++;
    }

    p->next = dummyHead->next; // 链表首位相接形成循环链表
    k = sizeCnt - (k % sizeCnt); // 计算向后rotate的元素个数

    // 用一个指针从前向后数到新链表的结尾元素
    ListNode *q = dummyHead;
    while(k>0){
        q = q->next;
        k--;
    }

    // 结尾元素的下一个元素就是新链表的开头元素
    head = q->next;
    // 结尾元素后接空指针
    q->next = NULL;

    return head;
}














/*
solution 1 : 利用循环链表解题
*/
//ListNode* rotateRight(ListNode* head, int k) {
//    if(!head || k==0) return head;
//
//    ListNode* p = head;
//    int len=1;
//    while(p->next){
//        len++;
//        p = p->next;
//    }
//    p->next = head; // circle it
//
//    int cnt = 0;
//    k = k % len;
//    while(head){
//        cnt++;
//        if(cnt == len-k) break;
//        head = head->next;
//    }
//
//    ListNode* tmp = head->next;
//    head->next = NULL;
//    head = tmp;
//    return head;
//}






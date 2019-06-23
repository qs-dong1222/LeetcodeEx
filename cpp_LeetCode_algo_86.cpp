#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* partition(ListNode* head, int x);

int main(){
    ListNode n0(2);
    ListNode n1(1);
//    ListNode n2(2);
//    ListNode n3(3);
//    ListNode n4(4);
//    ListNode n5(5);
//    ListNode n6(6);
    n0.next = &n1;
//    n1.next = &n2;
//    n2.next = &n3;
//    n3.next = &n4;
//    n4.next = &n5;
//    n5.next = &n6;

    ListNode* p = partition(&n0, 2);

    while(p){
        cout << p->val << " ";
        p = p->next;
    }

    return 0;
}


/*
首先要明白这个题是什么要求.
给定一个链表和一个值x.
以 "< x" 和 ">= x", 形成两个部分. 把原链表中符合的数字放进去.
每个部分内部各个数字之间的相互位置关系与原链表中一样.
例子: 1->1->4->3->2->5->1->2, x=3
变成 1->1->2->1->2 -> 4->3->5
     |___part1___|   |__p2__|

思路为:
建立两个链子，一个串 <x 的，另一个串 >=x 的
最后合并两个链子
*/
ListNode* partition(ListNode* head, int x) {
    ListNode node1(0);
    ListNode node2(0);
    ListNode *p1 = &node1, *p2 = &node2;

    while(head){
        if(head->val < x){
            p1->next = head;
            p1 = p1->next;
        }
        else{
            p2->next = head;
            p2 = p2->next;
        }
        head = head->next;
    }
    p1->next = node2.next;
    p2->next = NULL;
    return node1.next;
}









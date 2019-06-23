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
����Ҫ�����������ʲôҪ��.
����һ�������һ��ֵx.
�� "< x" �� ">= x", �γ���������. ��ԭ�����з��ϵ����ַŽ�ȥ.
ÿ�������ڲ���������֮����໥λ�ù�ϵ��ԭ������һ��.
����: 1->1->4->3->2->5->1->2, x=3
��� 1->1->2->1->2 -> 4->3->5
     |___part1___|   |__p2__|

˼·Ϊ:
�����������ӣ�һ���� <x �ģ���һ���� >=x ��
���ϲ���������
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









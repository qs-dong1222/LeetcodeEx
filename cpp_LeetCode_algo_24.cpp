
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapAdjacentNodes(ListNode* headPair);

int main(){

    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    ListNode n5(5);
    ListNode n6(6);
    ListNode n7(7);
    ListNode n8(8);
    n1.next = &n3;
    n3.next = &n5;
    n5.next = &n7;
    n7.next = NULL;

    n2.next = &n4;
    n4.next = &n6;
    n6.next = &n8;
    n8.next = NULL;

    ListNode *p = &n1;
    ListNode **pp = &(p), *a, *b;
    while ((a = *pp) && (b = a->next)) {
        a->next = b->next;
        b->next = a;
        *pp = b;
        cout << *pp << endl;
        pp = &(a->next);
        cout << *pp << endl;
    }





    return 0;
}

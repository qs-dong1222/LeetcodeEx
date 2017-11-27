#include <iostream>
#include <vector>

using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* insertionSortList(ListNode* head);

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

    ListNode* p = insertionSortList(&n0);

    while(p){
        cout << p->val << " ";
        p = p->next;
    }

    return 0;
 }


ListNode* insertionSortList(ListNode* head) {
    if(!head) return head;

    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode* prev = dummyHead;
    ListNode* curr = prev->next;

    while(curr){
        if(curr->next && curr->next->val < curr->val){
            // search from dummyHead until the first node whose value is less than the node's that
            // is going to insert
            while(prev->next && prev->next->val < curr->next->val){
                prev = prev->next;
            }
            // found the first node whose value is less ...... start inserting node
            // prev->next is the node after curr->next
            ListNode* insertNode = curr->next;
            curr->next = insertNode->next;
            insertNode->next = prev->next;
            prev->next = insertNode;

            //reset prev to dummyHead
            prev = dummyHead;
        }
        else{
            curr = curr->next;
        }
    }

    head = dummyHead->next;
    delete dummyHead;
    return head;
}





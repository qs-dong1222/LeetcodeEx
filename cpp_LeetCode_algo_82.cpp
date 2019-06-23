#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head);

int main(){
    ListNode n0(1);
    ListNode n1(1);
    ListNode n2(1);
    ListNode n3(1);
    ListNode n4(4);
    ListNode n5(5);
    ListNode n6(6);
    n0.next = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;

    ListNode* p = deleteDuplicates(&n0);

    while(p->next!=NULL){
        cout << p->val << " ";
        p = p->next;
    }
    cout << p->val << endl;

    return 0;
}




/*
这是我见过比较 elegant 的递归解法, 思路清晰且容易理解, 唯一要注意的是每次删掉 listnode 时, 要 free 这个 node 的
内存空间.
*/
//ListNode* deleteDuplicates(ListNode* head) {
//    if (!head || !head->next) return head;
//
//    int val = head->val;
//    ListNode* p = head->next;
//
//    if (p->val != val) {
//        head->next = deleteDuplicates(p);
//        return head;
//    }
//    else {
//        while (p && p->val == val) {
//            p = p->next;
//            free(head->next);
//            head->next = p;
//        }
//
//        return deleteDuplicates(p);
//    }
//}










//ListNode* deleteDuplicates(ListNode* head) {
//    ListNode *ptmp = head, *prev, *curr;
//    bool removalOccur = false;
//    while(ptmp !=NULL && ptmp->next != NULL){
//        removalOccur = false;
//        if(ptmp==head){
//            curr = ptmp;
//            prev = ptmp;
//        }
//        else{
//            prev = curr;
//            curr = ptmp;
//        }
//
//        // remove all same nodes following current node
//        while(curr->next!=NULL && curr->next->val == curr->val){
//            removalOccur = true;
//            curr->next = curr->next->next;
//        }
//        // remove current node
//        if(removalOccur){
//            //remove current node
//            if(curr != head){
//                // this current node is not head node
//                prev->next = curr->next;
//            }
//            else{
//                // this current node is head node
//                head = curr->next;
//            }
//            ptmp = curr->next;
//            curr = prev;
//        }
//        else{
//            ptmp = ptmp->next;
//        }
//
//    }
//
//    return head;
//}

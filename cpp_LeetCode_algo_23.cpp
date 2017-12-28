#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
ListNode* mergeKLists(vector<ListNode*>& lists);

int main(){
    ListNode n1(1);
    ListNode n2(1);
    ListNode n3(2);
    ListNode n4(1);
    ListNode n5(2);
    ListNode n6(2);
    //ListNode n7(7);
    //ListNode n8(8);
    n1.next = &n3;
    n3.next = &n5;
    //n5.next = &n7;

    n2.next = &n4;
    n4.next = &n6;
    //n6.next = &n8;

    vector<ListNode*> lists = {&n1, &n2};

    ListNode* p = mergeKLists(lists);
    while(p){
        cout << p->val << " ";
        p = p->next;
    }


    return 0;
}


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(!l1) return l2;
    if(!l2) return l1;

    if(l1->val < l2->val){
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else{
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}



ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.empty()) return NULL;

    ListNode* dummyHead = new ListNode(INT_MIN);
    for(int i=0;i<(int)lists.size();i++){
        dummyHead= mergeTwoLists(dummyHead, lists[i]);
    }
    return dummyHead->next;
}

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

    mergeTwoLists(&n1, &n2);


    return 0;
}


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(l1==NULL){
        return l2;
    }
    if(l2==NULL){
        return l1;
    }

    ListNode* p1=l1;
    ListNode* p2=l2;
    ListNode* pans = new ListNode(0);
    ListNode* ptemp;
    ptemp = pans;
    ptemp->next = p1;

    int qNbr;
    while(ptemp->next!=NULL){
        if(p1->val < p2->val){
            ptemp->next = p1;
            p1 = p1->next;
            qNbr = 1;
        }
        else{
            ptemp->next = p2;
            p2 = p2->next;
            qNbr = 2;
        }
        ptemp = ptemp->next;
    }

    if(qNbr==1){
        ptemp->next = p2;
    }
    else if(qNbr==2){
        ptemp->next = p1;
    }

    return pans->next;
}


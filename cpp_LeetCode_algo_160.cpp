#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* findCycleEncounter(ListNode *head);
ListNode* findCycleBegin(ListNode* head);
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);
int GetListLength(ListNode* head);

int main(){
    ListNode n0(1);
    ListNode n1(2);
    ListNode n2(3);
    ListNode n3(4);
    ListNode n4(5);
    ListNode n5(6);

    n0.next = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    ListNode nx(7);

    int len = GetListLength(&n0);
    cout << len << endl;

    return 0;
}





ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
    if(!headA || !headB){
        return NULL;
    }

    ListNode* pA = headA;
    ListNode* pB = headB;

    while(pA && pB){
        if(pA == pB){
            return pA;
        }

        pA = pA->next;
        pB = pB->next;
        if(!pA){
            pA = headB;
        }
        if(!pB){
            pB = headA;
        }
    }
}



/*
solution No.2
*/
// int GetListLength(ListNode* head){
//    if(!head){
//        return 0;
//    }
//
//    int len = 0;
//    while(head){
//        len++;
//        head = head->next;
//    }
//    return len;
//}
//
//ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//    if(!headA || !headB){
//        return NULL;
//    }
//
//    int lenA = GetListLength(headA);
//    int lenB = GetListLength(headB);
//    int longLen = lenA>=lenB? lenA:lenB;
//    int shortLen = lenA<lenB? lenA:lenB;
//
//    ListNode* shortHead = lenA<=lenB? headA:headB;
//    ListNode* longHead = lenA>lenB? headA:headB;
//
//    while(longLen != shortLen){
//        longHead = longHead->next;
//        longLen--;
//    }
//
//    while(shortHead && longHead){
//        if(shortHead == longHead){
//            return shortHead;
//        }
//
//        shortHead = shortHead->next;
//        longHead = longHead->next;
//    }
//
//    return NULL;
//}




/*
Solution No.1 using list cycle
*/
//ListNode* findCycleEncounter(ListNode *head){
//    if(!head){
//        return head;
//    }
//
//    ListNode* fast = head;
//    ListNode* slow = head;
//
//    while(fast && fast->next && fast->next->next){
//        if(fast->next->next == slow->next){
//            return fast->next->next;
//        }
//        fast = fast->next->next;
//        slow = slow->next;
//    }
//
//    return NULL;
//}
//
//
//
//ListNode* findCycleBegin(ListNode* head){
//    if(!head){
//        return head;
//    }
//
//    ListNode* encounter = findCycleEncounter(head);
//    if(!encounter){
//        // no encounter, no cycle
//        return NULL;
//    }
//
//    ListNode* p1 = head;
//    while(true){
//        if(p1 == encounter){
//            return p1;
//        }
//        p1 = p1->next;
//        encounter = encounter->next;
//    }
//    return p1;
//}
//
//
//ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//    if(!headA || !headB){
//        return NULL;
//    }
//
//    ListNode* pA = headA;
//    while(pA->next){
//        pA = pA->next;
//    }
//    pA->next = headA;
//
//    ListNode* ans = findCycleBegin(headB);
//    pA->next = NULL;
//    return ans;
//}

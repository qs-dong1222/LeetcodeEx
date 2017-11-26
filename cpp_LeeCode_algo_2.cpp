#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int retDigit = 0;
        int retCarry = 0;

        int i;

        vector<int> digits;
        ListNode* p1 = l1;
        ListNode* p2 = l2;

        bool l1_end = false;
        bool l2_end = false;

        int l1_val = 0;
        int l2_val = 0;

        while( !(l1_end && l2_end) ){
            if(!l1_end){
                l1_val = p1->val;
            }else{
                l1_val = 0;
            }

            if(!l2_end){
                l2_val = p2->val;
            }else{
                l2_val = 0;
            }

            retDigit = (l1_val + l2_val + carry) % 10;
            carry = (l1_val + l2_val + carry) / 10;
            digits.push_back(retDigit);

            if(p1->next != NULL){
                p1 = p1->next;
            }else{
                l1_end =true;
            }

            if(p2->next != NULL){
                p2 = p2->next;
            }else{
                l2_end =true;
            }
        }


        if(carry==1){
            digits.push_back(carry);
        }


        ListNode* retl = new ListNode;;
        ListNode* p = retl;
        for(i=0;i<digits.size()-1;i++){
            p->next = new ListNode;
            p = p->next;
        }
        p->next = NULL;

        p = retl;
        for(i=0;i<digits.size();i++){
            p->val = digits[i];
            p = p->next;
        }

        return retl;

    }



    void addDigit(ListNode* node1, ListNode* node2, int carry, int* retDigit, int* retCarry){

        if(node1 == NULL){
            *retDigit = (node2->val + carry) % 10;
            *retCarry = (node2->val + carry) / 10;
        }
        else if(node2 == NULL){
            *retDigit = (node1->val + carry) % 10;
            *retCarry = (node1->val + carry) / 10;
        }
        else{
            *retDigit = (node1->val + node2->val + carry) % 10;
            *retCarry = (node1->val + node2->val + carry) / 10;
        }
    }

};




int main(){

    ListNode a;
    a.val = 1;
    ListNode* l1 = &a;
    ListNode b;
    b.val = 8;
    l1->next = &b;
    l1->next->next = NULL;

    ListNode c;
    c.val = 0;
    c.next = NULL;
    ListNode* l2 = &c;


    Solution su;

    ListNode* aaaaa = su.addTwoNumbers(l1, l2);

    cout << aaaaa->val << endl;
    cout << aaaaa->next->val << endl;

    return 0;
}

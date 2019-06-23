#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseBetween(ListNode* head, int m, int n);

int main(){
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    ListNode n5(5);
    ListNode n6(6);
//    n1.next = &n2;
//    n2.next = &n3;
//    n3.next = &n4;
//    n4.next = &n5;
//    n5.next = &n6;

    ListNode* p = reverseBetween(&n1, 1,1);

    while(p){
        cout << p->val << " ";
        p = p->next;
    }


    return 0;
}

ListNode* reverseBetween(ListNode* head, int m, int n) {
    if(!head || m==n) return head;


    ListNode *dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode *p = dummyHead;
    ListNode *mHead, *m_prev_head;
    ListNode *pprev, *pnext;

    int cnt = -1;
    while(cnt<n){
        cnt++;
        if(cnt == m-1){
            m_prev_head = p;
        }

        if(cnt >= m){
            if(cnt == m){
                mHead = p;
                pprev = p;
                p = p->next;
            }

            if(cnt > m){
                pnext = p->next;
                p->next = pprev;
                pprev = p;
                p = pnext;
            }
        }
        else{
            pprev = p;
            p = p->next;
        }
    }

    if(cnt==n){
        mHead->next = pnext;
        m_prev_head->next = pprev;
    }


    // 这里必须要说一下.
    // 咱们上面想出来的方法使用了dummy head, 如果m=1, m_prev_head就是dummy head.
    // 但如果m!=1, m_prev_head是反转起点的前一个节点, 这个节点前可嫩还有别的非反转节点.
    // 需要用dummy head来找到真正的链表首节点.
    if(m==1){
        return m_prev_head->next;
    }
    else{
        return dummyHead->next;
    }
}











//ListNode* reverseBetween(ListNode* head, int m, int n) {
//    if(m==n) return head;
//    ListNode* ori = head;
//    ListNode* breach1 = head;
//    ListNode* breach2 = NULL;
//    ListNode* p = NULL;
//    int cnt=0;
//    while(head){
//        cnt++;
//        if(cnt==m-1)
//            breach1 = head;
//        if(cnt>=m && cnt<=n){
//            ListNode* tmp = new ListNode(head->val);
//            tmp->next = p;
//            p = tmp;
//            if(cnt==m){
//                breach2 = tmp;
//            }
//        }
//        if(cnt==n+1)
//            break;
//        head = head->next;
//    }
//
//    breach2->next = head;
//    if(breach1 != ori || (breach1==ori&&m>=2)){
//        breach1->next = p;
//        return ori;
//    }
//    else{
//        return p;
//    }
//}


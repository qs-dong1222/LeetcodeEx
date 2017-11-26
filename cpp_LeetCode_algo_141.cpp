bool hasCycle(ListNode *head) {
    if(!head) return head;

    ListNode* p1 = head;
    ListNode* p2 = head;
    while(p1 && p2){
        if(!p1->next || !p2->next || !p2->next->next)
            return false;
        if(p1->next == p2->next->next)
            return true;
        else{
            p2 = p2->next->next;
            p1 = p1->next;
        }
    }

    return false;
}

ListNode *detectCycle(ListNode *head) {
    if(!head) return head;

    ListNode* p1 = head;
    ListNode* p2 = head;
    ListNode* encounterP;
    while(p1 && p2){
        if(!p1->next || !p2->next || !p2->next->next)
            return NULL;
        if(p1->next == p2->next->next){
            encounterP = p1->next;
            p1 = head;
            break;
        }
        else{
            p2 = p2->next->next;
            p1 = p1->next;
        }
    }

    while(p1 && encounterP){
        if(p1 == encounterP){
            return encounterP;
        }
        p1 = p1->next;
        encounterP = encounterP->next;
    }

}


ListNode* deleteDuplicates(ListNode* head) {
    if(!head || !head->next) return head;

    while(head->next){
        if(head->val == head->next->val){
            ListNode* del = head->next;
            head->next = head->next->next;
            delete del;
        }
        else{
            head->next = deleteDuplicates(head->next);
            break;
        }
    }

    return head;
}

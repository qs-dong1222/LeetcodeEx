// ��֮ǰ����ͼ�������һ���ģ��ڸ���ǰ��Ľڵ�ʱ���п��ܰѺ���Ľڵ����������ˡ�
// Ϊ��ֹ�ظ����죬��һ��hash�����洢�ѽ����ĵ�


                //��ǰ���ڱ����Ľڵ�   // ��ǰ�����ڵ�ĸ��ƽڵ�
unordered_map<  RandomListNode *,          RandomListNode *>      hsmap;

RandomListNode *copyRandomList(RandomListNode *head) {
    if(!head){
        return head;
    }

    RandomListNode* origin = head;

    while(origin){
        // ���ԭ�����еĵ�ǰ�����ڵ㻹û�б�����������Ǿͽ��������
        if(!hsmap.count(origin)){
            hsmap[origin] = new RandomListNode(origin->label);
        }
        else{
            //���ԭ�����еĵ�ǰ�����ڵ��Ѿ��������������ʲôҲ���øɣ��þͺ��ˡ�
            ;
        }

        // ԭ�����еĵ�ǰ�����ڵ��next�ڵ㻹û�б�����������Ǿͽ��������
        if(origin->next && !hsmap.count(origin->next)){
            hsmap[origin->next] = new RandomListNode(origin->next->label);
        }
        // ԭ�����еĵ�ǰ�����ڵ��next�ڵ��Ѿ�������������Ǿ�ֱ����
        hsmap[origin]->next = hsmap[origin->next];

        // ԭ�����еĵ�ǰ�����ڵ��random�ڵ㻹û�б�����������Ǿͽ��������
        if(origin->random && !hsmap.count(origin->random)){
            hsmap[origin->random] = new RandomListNode(origin->random->label);
        }
        // ԭ�����еĵ�ǰ�����ڵ��random�ڵ��Ѿ�������������Ǿͽ��������
        hsmap[origin]->random = hsmap[origin->random];

        //�ܵ���һ���ڵ�ȥ����
        origin = origin->next;
    }

    return hsmap[head];
}

// 和之前复制图的情况是一样的，在复制前面的节点时，有可能把后面的节点给先造出来了。
// 为防止重复建造，用一个hash表来存储已建立的点


                //当前正在遍历的节点   // 当前遍历节点的复制节点
unordered_map<  RandomListNode *,          RandomListNode *>      hsmap;

RandomListNode *copyRandomList(RandomListNode *head) {
    if(!head){
        return head;
    }

    RandomListNode* origin = head;

    while(origin){
        // 如果原链表中的当前遍历节点还没有被建造过，我们就建造出来。
        if(!hsmap.count(origin)){
            hsmap[origin] = new RandomListNode(origin->label);
        }
        else{
            //如果原链表中的当前遍历节点已经被建造过，我们什么也不用干，用就好了。
            ;
        }

        // 原链表中的当前遍历节点的next节点还没有被建造过，我们就建造出来。
        if(origin->next && !hsmap.count(origin->next)){
            hsmap[origin->next] = new RandomListNode(origin->next->label);
        }
        // 原链表中的当前遍历节点的next节点已经被建造过，我们就直接用
        hsmap[origin]->next = hsmap[origin->next];

        // 原链表中的当前遍历节点的random节点还没有被建造过，我们就建造出来。
        if(origin->random && !hsmap.count(origin->random)){
            hsmap[origin->random] = new RandomListNode(origin->random->label);
        }
        // 原链表中的当前遍历节点的random节点已经被建造过，我们就建造出来。
        hsmap[origin]->random = hsmap[origin->random];

        //跑到下一个节点去搞事
        origin = origin->next;
    }

    return hsmap[head];
}

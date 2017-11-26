#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node);
//unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> node_clone_map;

int main(){
    UndirectedGraphNode* head = new UndirectedGraphNode(1);

    cloneGraph(head);

    return 0;
}


/*
BFS solution: 遍历原图的同时，进行新图的建立
*/
UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if(!node){
        return node;
    }

    deque<UndirectedGraphNode*> dq;
    UndirectedGraphNode* cloneHead = new UndirectedGraphNode(*node);
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> node_clone_map;
    node_clone_map[node] = cloneHead;

    dq.push_back(node);
    while(!dq.empty()){

        for(int i=dq.size();i>0;i--){
            UndirectedGraphNode* curr = dq.front();
            dq.pop_front();
            if(curr && !curr->neighbors.empty()){
                for(auto eachNeighbor : curr->neighbors){
                    if(!node_clone_map.count(eachNeighbor)){
                        UndirectedGraphNode* subNode = new UndirectedGraphNode(eachNeighbor->label);
                        node_clone_map[eachNeighbor] = subNode;
                        node_clone_map[curr]->neighbors.push_back(subNode);
                        dq.push_back(subNode);
                    }
                    else{
                        node_clone_map[curr]->neighbors.push_back(node_clone_map[eachNeighbor]);
                    }
                }
            }
        }
    }

    return cloneHead;
}


/*
DFS solution: 遍历原图的同时，进行新图的建立
*/
//UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
//    if(!node){
//        return NULL;
//    }
//
//    if(!node_clone_map.count(node)){
//        UndirectedGraphNode* cloneNode = new UndirectedGraphNode(*node);
//        node_clone_map[node] = cloneNode;
//        for(auto eachNeighbor : node->neighbors){
//            cloneNode->neighbors.push_back( cloneGraph(eachNeighbor) );
//        }
//    }
//
//    return node_clone_map[node];
//}

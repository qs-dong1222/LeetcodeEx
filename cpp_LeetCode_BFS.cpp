#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

int main(){

    return 0;
}


bool BFS(start, end){
    int nodeLvl=0;
    queue q;
    set visited;

    q.push(start);
    while(!q.empty()){
        //��next level�Ľڵ�
        nodeLvl++;

        //��next level�Ľڵ�����ȡ��
        for(currNode in q){
            q.pop(currNode);
            visited.insert(currNode);

            //��eachnode�� possible node in next level
            for(possibleNode of currNode in next level){
                if(isValid(possibleNode) && !visited.count(possibleNode)){
                    if(possibleNode == end)
                        return step + 1;
                    //�ҵ�һ��possible node ������һ��Ҫ���ʵĽڵ��б���
                    q.push(possibleNode);
                }
            }
        }

    }
}







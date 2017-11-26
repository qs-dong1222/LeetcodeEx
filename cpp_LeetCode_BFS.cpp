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
        //有next level的节点
        nodeLvl++;

        //把next level的节点依次取出
        for(currNode in q){
            q.pop(currNode);
            visited.insert(currNode);

            //找eachnode的 possible node in next level
            for(possibleNode of currNode in next level){
                if(isValid(possibleNode) && !visited.count(possibleNode)){
                    if(possibleNode == end)
                        return step + 1;
                    //找到一个possible node 放入下一层要访问的节点列表内
                    q.push(possibleNode);
                }
            }
        }

    }
}







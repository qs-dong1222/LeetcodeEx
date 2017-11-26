#include <iostream>
#include <unordered_set>
#include <vector>
#include <set>

using namespace std;

struct NODE{
    int x;
    int y;
    int value;
    bool operator==(const NODE& n) const{
        return (this->x==n.x && this->y==n.y);
    }
    bool operator<(const NODE& n) const{
        return (this->value < n.value);
    }
};

struct NODEHASH{
    size_t operator()(const NODE& n) const{
        return (((11*n.x+7*n.y)+23)>>1)<<2;
    }
};


vector<NODE> FindPossiNextNodes(vector<vector<int>>& chess, NODE& currNode);
int BFS(vector<vector<int>>& chess, NODE& start, NODE& end, bool countStart);

int main(){
    vector<vector<int>> chess = {
        {2,3,4},
        {0,0,5},
        {1,7,6}
    };

    if(chess[0][0]==0){
        cout << "impossible!!! chess[0][0]=0" << endl;
    }

    set<NODE> s;
    for(int r=0;r<(int)chess.size();r++){
        for(int c=0;c<(int)chess[0].size();c++){
            if(chess[r][c])
                s.insert(NODE{c,r,chess[r][c]});
        }
    }


    NODE start,end;
    set<NODE>::iterator itStart = s.begin();
    set<NODE>::iterator itEnd = s.begin();
    advance(itEnd,1);

    start = {0,0,chess[0][0]};
    end = *itStart;

    int ans = BFS(chess, start, end, false);

    int temp;
    for(;itStart!=s.end()&&itEnd!=s.end();itStart++, itEnd++){
        start = *itStart;
        end = *itEnd;
        temp = BFS(chess, start, end, false);
        if(temp == -1) return -1;
        ans += temp;
    }
    cout << ans << endl;

    return 0;
}






int BFS(vector<vector<int>>& chess, NODE& start, NODE& end, bool countStart){
    if(start == end) return 0;

    int step;
    if(countStart) step = 0;
    else step = -1;

    unordered_set<NODE, NODEHASH> q1;
    unordered_set<NODE, NODEHASH> q2;
    unordered_set<NODE, NODEHASH> nextLevelq;
    unordered_set<NODE, NODEHASH> visited;

    vector<NODE> possiNodes;

    q1.insert(start);
    q2.insert(end);
    while(!q1.empty() && !q2.empty()){
        step++;

//        if(q1.size() > q2.size()){
            swap(q1,q2);
//        }

        nextLevelq.clear();
        for(auto currNode:q1){
            visited.insert(currNode);
            // find possible nodes of currNode in next level
            possiNodes = FindPossiNextNodes(chess, currNode);
            for(auto possiNode : possiNodes){
                if( !visited.count(possiNode) )   {
                    if(q2.count(possiNode)){
                        return step+1;
                    }
                    nextLevelq.insert(possiNode);
                }
            }
        }

        swap(nextLevelq,q1);

    }

    return -1;
}




vector<NODE> FindPossiNextNodes(vector<vector<int>>& chess, NODE& currNode){
    int Xbound = chess[0].size()-1;
    int Ybound = chess.size()-1;
    vector<NODE> res;

    if( (currNode.x-1 >=0 && currNode.x-1 <= Xbound)
        && (currNode.y >= 0 && currNode.y <= Ybound) ){
        if(chess[currNode.y][currNode.x-1] != 0)
            res.push_back(NODE{currNode.x-1, currNode.y, chess[currNode.y][currNode.x-1]});
    }

    if( (currNode.x >=0 && currNode.x <= Xbound)
        && (currNode.y-1 >= 0 && currNode.y-1 <= Ybound) ){
        if(chess[currNode.y-1][currNode.x] != 0)
            res.push_back(NODE{currNode.x, currNode.y-1, chess[currNode.y-1][currNode.x]});
    }

    if( (currNode.x+1 >=0 && currNode.x+1 <= Xbound)
        && (currNode.y >= 0 && currNode.y <= Ybound) ){
        if(chess[currNode.y][currNode.x+1] != 0)
            res.push_back(NODE{currNode.x+1, currNode.y, chess[currNode.y][currNode.x+1]});
    }

    if( (currNode.x >=0 && currNode.x <= Xbound)
        && (currNode.y+1 >= 0 && currNode.y+1 <= Ybound) ){
        if(chess[currNode.y+1][currNode.x] != 0)
            res.push_back(NODE{currNode.x, currNode.y+1, chess[currNode.y+1][currNode.x]});
    }

    return res;
}


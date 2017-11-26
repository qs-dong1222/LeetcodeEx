#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_set>

using namespace std;
bool IsValid(vector<vector<int>>& chess, int r, int c, vector<vector<bool>>& visited);
int BFS(vector<vector<int>>& chess, tuple<int,int,int>& start, tuple<int,int,int>& end, bool countStart);

int main(){
    vector<vector<int>> chess = {
        {2,3,4},
        {0,0,5},
        {8,7,6}
    };

    set<tuple<int,int,int>> s;

    for(int r=0;r<(int)chess.size();r++){
        for(int c=0;c<(int)chess[0].size();c++){
            if(chess[r][c]>1)
                s.insert(make_tuple(chess[r][c], r, c));
        }
    }


//    for(auto eachTuple:s){
//        cout << "r="<< get<1>(eachTuple) << ", c="<< get<2>(eachTuple) << ", value=" << get<0>(eachTuple)<<endl;
//    }

    tuple<int,int,int> start{chess[0][0],0,0};
    int ans = 0;
    int tmp;
    for(auto eachTuple:s){
//        cout << "end: r="<< get<1>(eachTuple) << ", c="<< get<2>(eachTuple) << ", value=" << get<0>(eachTuple)<<endl;
        tmp = BFS(chess,start,eachTuple,false);
        if(tmp == -1) cout << "impossible" << endl;
        ans += tmp;
        start = eachTuple;
    }

    cout << ans << endl;

    return 0;
}



int BFS(vector<vector<int>>& chess, tuple<int,int,int>& start, tuple<int,int,int>& end, bool countStart){
    vector<vector<int>> dire = { {0,1}, {0,-1}, {1,0}, {-1,0} };
    int step;
    if(countStart) step=0;
    else step=-1;
    queue<tuple<int, int, int>> q;
    vector<vector<bool>> visited(chess.size(), vector<bool>(chess[0].size(), false));

    q.push(start);
    tuple<int,int,int> curr;
    int r, c;
    while(!q.empty()){
        step++;

        for(int i=q.size();i>0;i--){
            curr = q.front();
            q.pop();
            r = get<1>(curr);
            c = get<2>(curr);
            visited[r][c] = true;
            if(r == get<1>(end) && c == get<2>(end) ) return step;

            for(auto each:dire){
                if(IsValid(chess,r+each[0],c+each[1],visited)){
                    if(r+each[0] == get<1>(end)
                       && c+each[1] == get<2>(end) ) return step+1;
//                    cout<<"r="<<r+each[0]<<", c="<<c+each[1]<<", value="<<chess[r+each[0]][c+each[1]]<<endl;
                    q.push(make_tuple(chess[r+each[0]][c+each[1]],r+each[0],c+each[1]));
                }
            }
//            cout << endl;
        }
    }

    return -1;

}


bool IsValid(vector<vector<int>>& chess, int r, int c, vector<vector<bool>>& visited){
    if( r<0 || r>=((int)chess.size())
       || c<0 || c>=((int)chess[0].size())
       || chess[r][c]==0
       ||  visited[r][c]){
        return false;
    }
    else{
        return true;
    }
}

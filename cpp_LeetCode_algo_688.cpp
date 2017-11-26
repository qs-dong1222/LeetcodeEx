#include <iostream>
#include <stdlib.h>
#include <unordered_map>
#include <list>
#include <vector>
#include <cmath>
#include <sstream>
#include <memory>


using namespace std;

double GetNbrOfAllPossiAtCoord(int chessSize, int steps, int destX, int destY);
bool IsCoordInchess(int chessSize, int x, int y);
double knightProbability(int N, int K, int r, int c) ;

vector< vector<int> > neighbors= { {-2,-1}, {-1,-2},
                                   {1,-2}, {2,-1},
                                   {2,1}, {1,2},
                                   {-1,2},{-2,1}
                                 };

unordered_map<string, int> resMap;



int main(){

//    double res = knightProbability(8,30,6,4);
    double res = GetNbrOfAllPossiAtCoord(8,30,6,4);
    cout << res << endl;

    return 0;
}


double knightProbability(int N, int K, int r, int c) {
    double tot = GetNbrOfAllPossiAtCoord(N,K,r,c);
    return tot/(pow(8.0,K));
}


/*
走step步，到达某点处后，棋子仍在棋牌上的所有可能步数
*/
double GetNbrOfAllPossiAtCoord(int chessSize, int steps, int destX, int destY){
    stringstream ss;
    ss << destX << "," << destY;
    string key = ss.str();

    if(resMap.find(key) != resMap.cend()){
        return resMap[key];
    }

    if(steps == 0){
        return 1;
    }

    int lastx,lasty;
    double total = 0;
    for(auto each:neighbors){
        lastx = destX + each[0];
        lasty = destY + each[1];
        if(IsCoordInchess(chessSize, lastx, lasty)){
            total += GetNbrOfAllPossiAtCoord(chessSize, steps-1, lastx, lasty);
        }
    }
    resMap[key] = total;
    return total;
}



bool IsCoordInchess(int chessSize, int x, int y){
    if(x<0 || x>chessSize-1){
        return false;
    }
    if(y<0 || y>chessSize-1){
        return false;
    }

    return true;
}

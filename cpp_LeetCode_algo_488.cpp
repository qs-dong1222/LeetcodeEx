#include <iostream>
#include <stdlib.h>
#include <unordered_map>
#include <list>
#include <vector>
#include <cmath>
#include <sstream>
#include <memory>

using namespace std;

string Shrink(string ballStr, int size2del);
string GetLeftBallStr(string& zumaBalls, string balls);

int main(){


//    string ball = "YYWWWWKRRRRRRWWWWB";
//    cout << Shrink(ball, 3) <<endl;

    string ball = "YRRGWWRR";
    string zuma = "GRGWRYY";
    int zumaOriSize = zuma.size();
    string res = GetLeftBallStr(zuma,ball);
    cout << "balls left = "<< res <<endl;
    if(res.size()>0){
        cout<< "impossible to conquer" <<endl;
    }
    else{
        cout << "conquered" <<endl;
    }

    return 0;
}


string GetLeftBallStr(string& zumaBalls, string balls){
    balls = Shrink(balls,3);
    int ballSize = balls.size();
    if(ballSize == 0){
        return "";
    }

    string copyBallStr = balls;
    int pos;
    int i;

    for(i=0; i<(int)zumaBalls.size(); i++){
        for(pos=0;pos<ballSize;pos++){
//            cout << "copyBallStr = " << copyBallStr << endl;
            copyBallStr.insert(pos,1,zumaBalls[i]);
            copyBallStr = Shrink(copyBallStr,3);
//            cout << "insert= " << zumaBalls[i] << endl;
//            cout << "copyBallStr shrink= " << copyBallStr << endl;
            if((int)copyBallStr.size()<ballSize){
                zumaBalls.erase(i,1);
                return GetLeftBallStr(zumaBalls, copyBallStr);
            }
            copyBallStr = balls;
        }
        // 就算当前这个球，什么位置也不能做出消除，我们到最后还是要把这个球找个位置打出去，
        // 好让后面的球出来，这里我们选和当前求颜色相同的位置，打出去
        for(pos=0;pos<copyBallStr.size();pos++){
            if(zumaBalls[i] == copyBallStr[pos]){
                copyBallStr.insert(pos,1,zumaBalls[i]);
                break;
            }
        }
    }

    return copyBallStr;
}











string Shrink(string ballStr, int size2del){
    int i=0,j=1;
    int strSize = ballStr.size();
    string shrinkedStr;
    bool isEnd = false;
    while(!isEnd){
//        cout <<"i= "<< i << ", j= "<< j<<endl;
        if(ballStr[i] == ballStr[j]){
            if(j-i+1 >= size2del){
                while(ballStr[i] == ballStr[j+1]) j++;
                ballStr = ballStr.substr(0,i) + ballStr.substr(j+1,strSize);
//                cout << "new ballStr = " << ballStr <<endl;
                return Shrink(ballStr, size2del);
            }
            else if((++j)>=strSize){
                isEnd = true;
            }
        }
        else{
            i++;
            j = (j-i>=2)? j : j++;
            if(j>=strSize){
                isEnd = true;
            }
        }
    }
    return ballStr;
}

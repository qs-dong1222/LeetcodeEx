/*
有一个强盗，抢一排房子，只能隔一个抢一个，求前n个房子，抢到财务的最优解
*/

#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <cmath>

using namespace std;

unordered_map<int, int> res;

template<typename dType>
dType FindMaxRob(vector<dType> money, int n_house2rob);


int main(){

    vector<int> money = {1,4,4,9,0,1,3,2};

    int res = FindMaxRob<int>(money, 8);

    cout << res <<endl;

    return 0;
}




template<typename dType>
dType FindMaxRob(vector<dType> money, int n_house2rob){
    if(res.find(n_house2rob) != res.cend()){
        // answer already exists
        return res[n_house2rob];
    }

    if(n_house2rob == 0){
        res[n_house2rob] = 0;
        return 0;
    }
    else if(n_house2rob == 1){
        res[n_house2rob] = money[0];
        return money[0];
    }
    else{
        res[n_house2rob] = max(FindMaxRob(money,n_house2rob-2) + money[n_house2rob-1], FindMaxRob(money,n_house2rob-1) );
        return res[n_house2rob];
    }
}

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
unordered_map<int, double> resMap;
double Pow(double x, int exp);

int main(){
    cout << Pow(2,-2) << endl;
    return 0;
}


double Pow(double x, int exp){
    if(x==0) return 0;
    if(resMap.count(exp)){
        return resMap[exp];
    }

    if(exp == 1){
        return x;
    }
    if(exp == 0){
        return 1;
    }
    if(exp==-1){
        return 1/x;
    }

    int halfExp = exp/2;
    resMap[exp] = Pow(x, halfExp) * Pow(x, exp - halfExp);
    return resMap[exp];
}

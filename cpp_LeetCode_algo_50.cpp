#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
unordered_map<int, double> resMap;
double myPow(double x, int exp);

int main(){
    cout << myPow(2,-2) << endl;
    return 0;
}


double myPow(double x, int exp){
    if(resMap.count(exp)) return resMap[exp];

    if(x==0) return x;
    if(exp==0) return 1;
    if(exp==1) return x;
    if(exp==-1) return (double)1/x;

    resMap[exp] = myPow(x, exp/2) * myPow(x, exp-exp/2);
    return resMap[exp];
}


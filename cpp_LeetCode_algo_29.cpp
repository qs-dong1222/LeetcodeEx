#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <stdint.h>
#include <cmath>

using namespace std;

vector<int> GetQandR(const double& dividend, const double& divisor);
int divide(int dividend, int divisor);

int main(){
//    vector<int> res = GetQandR(2147483647, 2);
//    cout << res[0] << endl;
//    cout << res[1] << endl;

    cout << divide(-999511578, -2147483648) << endl;

    return 0;
}





/*
地板除的概念就是找到一个正整数x，令x与被除数的积无限趋进于被除数，且小于被除数.
由于我们这里不能用乘除操作符。能用的就是移位和加减，那么我们就用移位做乘法运算，
不够的用加法来补。
*/
int divide(int dividend, int divisor) {
    if(divisor==0) return INT_MAX;
    int sign = 1;
    if( (dividend>0&&divisor<0) || (dividend<0&&divisor>0) ){
        // 不同号
        sign = -1;
    }

    long long did = abs((long long)dividend);
    long long div = abs((long long)divisor);
    if(did < div) return 0;

    long long ans = 1;
    while(div<did){
        div <<= 1;
        ans <<= 1;
    }

    if(div > did){
        div >>= 1;
        ans >>= 1;

        while(div<did){
            div += abs(divisor);
            ans++;
        }
        if(div>did){
            ans--;
        }
    }
    if(ans*sign > INT_MAX) return INT_MAX;
    if(ans*sign < INT_MIN) return INT_MIN;
    return ans*sign;
}

















//vector<int> GetQandR(const double& dividend, const double& divisor){
//    vector<int> q_and_r;
//    double d = -divisor;
//    int q=0;
//    for(int i=0; i<=dividend; i++){
//        d += divisor;
//        if(dividend >= d){
//            q = max(q, i);
//        }
//        else{
//            d -= divisor;
//            break;
//        }
//    }
//
//    q_and_r.push_back(q);
//    q_and_r.push_back( dividend-d );
//
//    return q_and_r;
//}
//
//
//





//int divide(int dividend, int divisor) {
//    if(!dividend) return dividend;
//    if(divisor==0 || (dividend == INT_MIN && divisor == -1) ){
//        return INT_MAX;
//    }
//
//    int sign = 1;
//    if( (dividend>0) ^ (divisor>0)) sign = -1;
//    // 这里divisor_ 必须是long long or unsigned int
//    // 当dividend 输入为 INT_MAX时, divisor_ 会不断左移, 此时的移动效果 最多就是 10000... = 1073741824
//    // int的数位限制其不可能到 2147483648，而是变成了负数 所用永远不会跳出 while(dividend >= (divisor_<<1))
//    // 或者我们用 unsigned int 去除符号位
//    unsigned int dividend_ = abs(dividend);
//    unsigned int divisor_ = abs(divisor);
//    unsigned int abs_divisor = divisor_;
//
//    if(dividend_ < abs_divisor) return 0;
//
//    int ans = 0;
//    unsigned int temp = 1;
//    while(dividend_ >= divisor_){
//        temp = 1;
//        while(dividend_ > (divisor_<<1) && divisor_!= INT_MAX+1){
//            temp <<= 1;
//            divisor_ <<= 1;
//        }
//        ans += temp;
//        dividend_ -= divisor_;
//        divisor_ = abs_divisor;
//    }
//
//    return sign*ans;
//}


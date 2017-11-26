#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <stdint.h>

using namespace std;

vector<int> GetQandR(const double& dividend, const double& divisor);
int divide(int dividend, int divisor);

int main(){
//    vector<int> res = GetQandR(2147483647, 2);
//    cout << res[0] << endl;
//    cout << res[1] << endl;

    cout << divide(-2147483648, -2147483648) << endl;


    return 0;
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
//
//
//
//
//
//int divide(int dividend, int divisor) {
//    if(divisor == 0) return INT_MAX;
//    if(dividend == 0) return 0;
//
//    if(abs(divisor) == 1){
////        cout << "dividend*divisor = " << (double)dividend*divisor << endl;
//        if((double)dividend*divisor > INT_MAX)
//            return INT_MAX;
//        else if((double)dividend*divisor < INT_MIN)
//            return INT_MIN;
//        else
//            return dividend*divisor;
//    }
//
//    int qsign = 1;
//    if( (dividend>0 && divisor<0) || (dividend<0 && divisor>0) ) qsign = -1;
//    int divisor_ = abs(divisor);
//    int dividend_ = abs(dividend);
//
//    stringstream ss;
//    ss<<dividend_;
//    string strdiv = ss.str();
//    cout << strdiv << endl;
//    string ans;
//    double divint;
//    vector<int> q_r;
//
//    ss.str("");
//    for(auto eachBit : strdiv){
//        cout << "eachBit " << eachBit << endl;
//        ss << eachBit;
//        divint = atoi(ss.str().c_str());
//        q_r = GetQandR(divint, divisor_);
//        cout << "q=" << q_r[0] << ", r=" << q_r[1] <<endl;
//        if(q_r[0] > 0){
//            ans.push_back('0'+q_r[0]);
//            ss.str("");
//            ss << q_r[1];
//        }
//    }
//
//    if(qsign > 0) return atoi(ans.c_str());
//    else return -1*atoi(ans.c_str());
//}




int divide(int dividend, int divisor) {
    if(!dividend) return dividend;
    if(divisor==0 || (dividend == INT_MIN && divisor == -1) ){
        return INT_MAX;
    }

    int sign = 1;
    if( (dividend>0) ^ (divisor>0)) sign = -1;
    // 这里divisor_ 必须是long long or unsigned int
    // 当dividend 输入为 INT_MAX时, divisor_ 会不断左移, 此时的移动效果 最多就是 10000... = 1073741824
    // int的数位限制其不可能到 2147483648，而是变成了负数 所用永远不会跳出 while(dividend >= (divisor_<<1))
    // 或者我们用 unsigned int 去除符号位
    unsigned int dividend_ = abs(dividend);
    unsigned int divisor_ = abs(divisor);
    unsigned int abs_divisor = divisor_;

    if(dividend_ < abs_divisor) return 0;

    int ans = 0;
    unsigned int temp = 1;
    while(dividend_ >= divisor_){
        temp = 1;
        while(dividend_ > (divisor_<<1) && divisor_!= INT_MAX+1){
            temp <<= 1;
            divisor_ <<= 1;
        }
        ans += temp;
        dividend_ -= divisor_;
        divisor_ = abs_divisor;
    }

    return sign*ans;
}


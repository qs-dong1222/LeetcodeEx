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
�ذ���ĸ�������ҵ�һ��������x����x�뱻�����Ļ����������ڱ���������С�ڱ�����.
�����������ﲻ���ó˳������������õľ�����λ�ͼӼ�����ô���Ǿ�����λ���˷����㣬
�������üӷ�������
*/
int divide(int dividend, int divisor) {
    if(divisor==0) return INT_MAX;
    int sign = 1;
    if( (dividend>0&&divisor<0) || (dividend<0&&divisor>0) ){
        // ��ͬ��
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
//    // ����divisor_ ������long long or unsigned int
//    // ��dividend ����Ϊ INT_MAXʱ, divisor_ �᲻������, ��ʱ���ƶ�Ч�� ������ 10000... = 1073741824
//    // int����λ�����䲻���ܵ� 2147483648�����Ǳ���˸��� ������Զ�������� while(dividend >= (divisor_<<1))
//    // ���������� unsigned int ȥ������λ
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


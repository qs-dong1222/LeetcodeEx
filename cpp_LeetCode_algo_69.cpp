#include <iostream>
#include <vector>

using namespace std;

int main(){

}

/*
    solution: 牛顿法
    对任意函数f(x), 求f(x)=0的解
    利用牛顿法的切线逼近原理, 可得 X[n] = X[n-1] - f(X[n-1])/f'(X[n-1])
    本题是求 x^2 = a 的解, 即 x^2 - a = 0 --> f(x) = x^2-a
    可得 X[n] = (X[n-1] + a/X[n-1]) / 2

    目的是找到最接近a的整数解. 那么我们可以每次都比较 X[n]^2 与 a的大小.
    如果大了说明 X[n] 太大, 还能找到比 X[n] 更合适的.
    一旦小了, 说明之前那个 X[n] 就是最接近的解.
*/
int mySqrt(int a) {
    long r = a;
    while (r*r > a)
        r = (r + a/r) / 2;
    return r;
}



/*
    还有一种2分法, 思路是2分查找中点, 看中点的平方与目标的差距.
    如果大了, 说明中点该小一点, 那么右边界缩小点, 再求中点, 循环往复
    反之, 说明左边界该大一点
*/

#include <iostream>
#include <vector>

using namespace std;
int trap(vector<int>& height);

int main(){
    vector<int> height = {3,1,0,1,0,1};

    cout << trap(height) << endl;

    return 0;
}


/*
这个方法主要关注点是双索引的利用
左右两端开始夹逼，每次比较中取夹逼中小的那一侧，从而保证从小的那一侧开始向另一侧跑，最后
肯定可以碰到比小的那一侧高的墙壁，那么从小的那一侧一步步积累的水都可以被累加起来。
maxH用来记录：小的那一侧移动过程中，当前遇到的最高值
tempH用来记录：小的那一侧移动过程中，比遇到的最高值低的那些高度
例子：小侧当前最高遇到为5，在之后的移动中碰见比5小的，比如3，说明在3这个桩顶上肯定能攒5-2的水量。
因为我们移动的是小的那一侧，即5已经判断出来是小的那一侧，到最后肯定能碰到比5大的最终右侧桩。
如果中途碰到比5大的，说明要更新遇到的最高桩，更新之后，最高桩和当前桩是一个桩，积累水量为0.
*/
int trap(vector<int>& height){
    if(height.empty()) return 0;
    int lidx=0;
    int ridx=height.size()-1;
    while(height[lidx]==0) lidx++;
    while(height[ridx]==0) ridx--;

    int tempH, maxH = INT_MIN;
    int ans = 0;

    while(lidx < ridx){
        tempH = height[ height[lidx] < height[ridx] ? lidx++:ridx-- ];
        maxH = max(maxH, tempH);
        ans += maxH - tempH;
    }
    return ans;
}

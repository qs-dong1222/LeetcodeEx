#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int maxArea(vector<int>& height);
int waterTankVolume(vector<int>& height);

int main(){
    vector<int> height =
    //{1, 8, 6, 2, 5, 4, 8, 3, 7};
    //{7,4,2,1,5,3,8,2,1,4,1};
    //{6,5,6,6,6,5,6};
    {1,2,3,4,5,6};

    cout << waterTankVolume(height) << endl;

    //cout << maxArea(height) << endl;

    return 0;
}



//int maxArea(vector<int>& height) {
//    int maxA = 0;
//    int i=0, j=height.size()-1;
//    int tmpArea;
//
//    while(i<j){
//        maxA = max( (j-i)*min(height[i], height[j]), maxA );
//        if(height[j] > height[i]) i++;
//        else j--;
//    }
//    return maxA;
//}


/*
这道题是heights为边，找两边构成最大矩形面积
solution : 两边进行夹逼扫描，实时更新结果即可
*/
int maxArea(vector<int>& height) {
    int ans = 0;
    if(height.empty()) return ans;

    int l = 0;
    int r = height.size()-1;
    while(l < r){
        int len = r-l;
        if(height[l] > height[r]){
            ans = max(len*height[r], ans);
            r--;
        }
        else{
            ans = max(len*height[l], ans);
            l++;
        }
    }
    return ans;
}




/*
延伸题:
heights为柱子, 找出所有柱子能构成的总储水量.
同样是两边夹逼的方法
*/
int waterTankVolume(vector<int>& height){
    int ans = 0;
    if(height.empty()) return ans;

    // 两边添0，更方便的跳过两边无法储水的上升型柱子群
    height.insert(height.begin(), 0);
    height.push_back(0);

    //跳过两边无法储水的上升型柱子群
    int l=0, r=height.size()-1;
    for(l=0;l<r;l++){
        if(height[l+1]<height[l]) break;
    }
    for(r=height.size()-1;l<r;r--){
        if(height[r-1]<height[r]) break;
    }

    //从低的一边开始扫描，h记录低边的高度，扫描之处低于h的都能储水。
    //碰到比h高的柱子则重新比较两边高低，从而确定扫描方向
    while(l<r){
        int h;
        if(height[l] < height[r]){
            h = height[l];
            while(l<r && height[l]<=h){
                ans += (h-height[l]);
                l++;
            }
        }
        else{
            h = height[r];
            while(l<r && height[r]<=h){
                ans += (h-height[r]);
                r--;
            }
        }
    }

    return ans;
}

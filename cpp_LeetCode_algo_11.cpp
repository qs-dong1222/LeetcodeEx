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
�������heightsΪ�ߣ������߹������������
solution : ���߽��мб�ɨ�裬ʵʱ���½������
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
������:
heightsΪ����, �ҳ����������ܹ��ɵ��ܴ�ˮ��.
ͬ�������߼бƵķ���
*/
int waterTankVolume(vector<int>& height){
    int ans = 0;
    if(height.empty()) return ans;

    // ������0������������������޷���ˮ������������Ⱥ
    height.insert(height.begin(), 0);
    height.push_back(0);

    //���������޷���ˮ������������Ⱥ
    int l=0, r=height.size()-1;
    for(l=0;l<r;l++){
        if(height[l+1]<height[l]) break;
    }
    for(r=height.size()-1;l<r;r--){
        if(height[r-1]<height[r]) break;
    }

    //�ӵ͵�һ�߿�ʼɨ�裬h��¼�ͱߵĸ߶ȣ�ɨ��֮������h�Ķ��ܴ�ˮ��
    //������h�ߵ����������±Ƚ����߸ߵͣ��Ӷ�ȷ��ɨ�跽��
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

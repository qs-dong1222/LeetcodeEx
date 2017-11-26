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
���������Ҫ��ע����˫����������
�������˿�ʼ�бƣ�ÿ�αȽ���ȡ�б���С����һ�࣬�Ӷ���֤��С����һ�࿪ʼ����һ���ܣ����
�϶�����������С����һ��ߵ�ǽ�ڣ���ô��С����һ��һ�������۵�ˮ�����Ա��ۼ�������
maxH������¼��С����һ���ƶ������У���ǰ���������ֵ
tempH������¼��С����һ���ƶ������У������������ֵ�͵���Щ�߶�
���ӣ�С�൱ǰ�������Ϊ5����֮����ƶ���������5С�ģ�����3��˵����3���׮���Ͽ϶�����5-2��ˮ����
��Ϊ�����ƶ�����С����һ�࣬��5�Ѿ��жϳ�����С����һ�࣬�����϶���������5��������Ҳ�׮��
�����;������5��ģ�˵��Ҫ�������������׮������֮�����׮�͵�ǰ׮��һ��׮������ˮ��Ϊ0.
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

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void nextPermutation(vector<int>& nums);
int main(){
    vector<int> nums =
    //{5,4,3,2,1};
    //{1,3,6,2,1};
    //{1,2,3};
    {2,1,3};
    //{1,1};

    nextPermutation(nums);

    for(auto each:nums){
        cout << each << " ";
    }

    return 0;
}


/*
solution:
�������һ���۲���ɵ��⣬����������������ɣ�������Ҳ�Ͱ׳��ˡ�
һ��۲�ʱ�Ⱦټ�������:
original: 1 2 3 4 6 5
next:     1 2 3 5 4 6

original: 1 3 6 3 3 2 1
next:     1 6 1 2 3 3 3

���ǿ�����һ�����������Ƕ�����4���ڶ����������Ƕ����ǵ�һ��3.
���ǵĸ���Ŀ�����ҵ���һ����ӽ�original�ұ�original���ֵ.
�����������и��ص㣬���������е�����һ���ǵ�����������������ֵ��С��.
�෴��������һ�������ġ�����123, �������е�123�϶�������λ�����е���Сֵ���.

�������������һ����ֵ���϶������ܴ����λ��ʼ�䣬�������λһ�䣬�������ʹ��˺ܶ�.
��originalǰ�벿���������������У���벿�������ǽ������С��������еĲ��ֿ϶����Ǽ�λ��������ֵ��
����Ҫ���������������϶�Ҫ�ڽ��򲿷ֵĻ�����������ֵ��������������ֵֻ�ܿ���λ�ķ�ʽ�����Բ��ɱ���
�ģ����ǿ϶�Ҫ�ڽ��򲿷ֵ�ǰһλ(����������һλ)���б�λ���Ӷ��ﵽ��λ�����Ч����
��ô���ˣ�����֪��Ҫ����һλ�ˣ����ǴӺ���ǰ�ҵ�һ����С��������Ҫ��ġ�
��ô���ʲô����
���ǵ�Ŀ��������original��������Ĳ����ֲ�������̫�����Կ϶�Ҫ��һ����ԭ�������ոպô�һ�������
��ô�ʹӺ���ǰ�ң��ҵ���һ���ȴ���λ��ֵ��������������ɡ�
���Ϊ�˱�֤����Ĳ����ֲ�������̫�����ǻ�Ҫ��λ�������Ǽ�λ��������һ�£��Ա�֤��벿�ֵ�ֵ
����С�ġ�
*/
void nextPermutation(vector<int>& nums){
    if(nums.empty()) return;

    int ridx = nums.size()-1;
    while(ridx>0 && nums[ridx-1]>=nums[ridx]){
        ridx--;
    }

    if(ridx==0){
        sort(nums.begin(), nums.end());
        return;
    }

    // nums[ridx-1] needs to change
    int pivot = nums[ridx-1];
    int r = nums.size()-1;
    while(nums[r]<= pivot){
        r--;
    }

    swap(nums[ridx-1], nums[r]);
    sort(nums.begin()+ridx,nums.end());
}






//void nextPermutation(vector<int>& nums) {
//    if(nums.empty()) return;
//    int revIdx = nums.size()-1;
//    int lidx, ridx = nums.size()-1;
//    while(nums[revIdx-1] >=  nums[revIdx] && revIdx>0)
//        revIdx--;
//    if(revIdx == 0){
//        sort(nums.begin(), nums.end());
//    }
//    else{
//        lidx = revIdx-1;
//        while(nums[ridx] <= nums[lidx]) ridx--;
//        swap(nums[lidx], nums[ridx]);
//        sort(nums.begin()+lidx+1, nums.end());
//    }
//}

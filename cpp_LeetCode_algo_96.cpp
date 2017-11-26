#include <iostream>
#include <vector>

using namespace std;

int G(vector<int>& nums, int lidx, int ridx);
int F(int rootIdx, vector<int>& nums);

int main(){

    vector<int> nums = {1,2,3,4};
    int ans = G(nums, 0, nums.size()-1);
    cout << ans << endl;
    return 0;
}


/*
����ⷨ˼·ʵ����ţB�������Զԣ�����Ͷ��:
F(idx,nums) ������nums[idx] Ϊ�����ʱ�����п������tree�ĸ���
G(lidx, ridx, nums) ���طֱ��� nums[lidx]~nums[ridx] Ϊ�����ʱ�����еĿ������tree�ĸ����������п�����
���Կ��� F(idx,nums) = G(0, idx-1, nums) * G(idx+1, nums.size()-1, nums)
���������ƶϳ� G(lidx, ridx, nums) = G(..)*G(..) + G(..)*G(..) + ... + G(..)*G(..)
*/

int G(vector<int>& nums, int lidx, int ridx){
    if(lidx >= ridx)
        return 1;

    int ans = 0;
    for(int i=lidx-1;i<=ridx-1;i++){
        ans += ( G(nums, lidx, i)*G(nums, i+2, ridx) );
    }
    return ans;
}

//int F(int rootIdx, vector<int>& nums){
//    return G(nums, 0, rootIdx-1) * G(nums, rootIdx+1, nums.size()-1);
//}



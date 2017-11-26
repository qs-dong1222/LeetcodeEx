#include <iostream>
#include <vector>

using namespace std;

int main(){

    return 0;
}

int maxSubArray(vector<int>& nums) {
    if(nums.empty()) return 0;

    int ans = INT_MIN;
    int maxV = INT_MIN;

    for(int begin=0; begin<nums.size(); begin++){
        maxV = max(maxV, nums[begin]);
        // �Ը�����ʼ��subarray����������ȷ��
        if(nums[begin]<0) continue;
        int sum = 0;
        for(int i=begin; i<nums.size(); i++){
            sum += nums[i];
            // �����Ϊ�����ǻ�����ֱ�ӴӺ����Ǹ���ʼ�����Ժ�Ϊ���Ͳ��ü�����
            if(sum < 0){
                begin = i;
                break;
            }
            ans = max(sum, ans);
        }
    }
    if(maxV <=0 ) return maxV;
    return ans;
}

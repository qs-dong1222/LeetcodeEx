#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums);


int main(){
    vector<int> nums =
    //{-2,1,-3,4,-1,2,1,-5,4};
    //{-1};
    {-2, 1};

    cout << maxSubArray(nums) << endl;
    return 0;
}



//int maxSubArray(vector<int>& nums) {
//    if(nums.empty()) return 0;
//
//    int ans = INT_MIN;
//    int maxV = INT_MIN;
//
//    for(int begin=0; begin<nums.size(); begin++){
//        maxV = max(maxV, nums[begin]);
//        // �Ը�����ʼ��subarray����������ȷ��
//        if(nums[begin]<0) continue;
//        int sum = 0;
//        for(int i=begin; i<nums.size(); i++){
//            sum += nums[i];
//            // �����Ϊ�����ǻ�����ֱ�ӴӺ����Ǹ���ʼ�����Ժ�Ϊ���Ͳ��ü�����
//            if(sum < 0){
//                begin = i;
//                break;
//            }
//            ans = max(sum, ans);
//        }
//    }
//    if(maxV <=0 ) return maxV;
//    return ans;
//}


/*
    �������ʵһ����·��ֵ�˼��. ����˵������Ѫ��, ���������Ѫ.
    ��Ѫ��<0ʱ, ���������, ��Ҫ���������һ�������㸴��. ����״̬��,
    ��ʹ���˹ֻ�����. ��������ʱ��, Ѫ��һֱ����Ϊ 0.

    �ܽ���˵, ����ȥ���, ����ָ���Ѫ��, ���Ѫ��<0, ˵������, Ѫ�����Ը���Ϊ0.
    �ٽ��Ŵ���һ����.

    ����, �ѵ�����ȫΪ����ʱ, ����Ҫ��һ����С�ĸ���. ��ô��?
    ������һ��ʼ����Ѫ��Ϊ��, ��һ�������¾ͺ���.
*/
int maxSubArray(vector<int>& nums) {
    int smax = INT_MIN;
    int sum = INT_MIN;
    for (auto num : nums) {
        if (sum < 0) {
            sum = 0;
        }
        sum += num;
        smax = max(smax, sum);

    }
    return smax;
}


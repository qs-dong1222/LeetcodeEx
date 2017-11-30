#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
int maxProduct(vector<int>& nums);

int main(){
    vector<int> nums = {-3,0,1,-2};
    //{0, 3, 1, -7, 2, -3, 0, 1, -3};
    cout << maxProduct(nums) << endl;

    return 0;
}



/*
DP: o(~ n^2)
*/
//int maxProduct(vector<int>& nums) {
//    if(nums.empty()) return 0;
//    int ans = INT_MIN;
//
//    //vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 1));
//    int curr = 1;
//
//    for(int i=0; i<(int)nums.size(); i++){
//        if(nums[i]==1){
//            ans = max(ans, nums[i]);
//            continue;
//        }
//        for(int j=i; j<(int)nums.size(); j++){
//            if(i==j){
//                //dp[i][j] = nums[i];
//                curr = nums[i];
//            }
//            else{
//                //dp[i][j] = dp[i][j-1] * nums[j];
//                curr = curr * nums[j];
//            }
//            //ans = max(ans, dp[i][j]);
//            ans = max(ans, curr);
//        }
//    }
//
//    return ans;
//}


/*
maxProduct, minProduct�������ڼ�¼֮ǰ����ֵ�ĳɼ������/Сֵ, ÿ�ζ�����, ��Ҫ�뵱ǰ����Ԫ�ر�
�൱��˵���Ҿ���һ����Ӳ�ˣ���ײ��ǽ����ͷ�������ǽ����0.
��ʵ����ÿ���ڵ�ǰֵ����0������£����¼����ֵ: ���/Сֵ������һ�غ�Ӳ�ˣ�
����¸����Ǹ��ģ����ǻ����Ҳ�Ǹ�������Сֵ������¸��������ģ����ǻ����Ҳ�����������ֵ��
���µ�ֵ���ض��������˻��Ľ��������ϵ�����������һ��0��������ȫ��0����һ�غϣ����ǻ��õ�ǰ
�ķ�0��ֵȥ�������ֵ�����÷�0��ֵȥ������Сֵ�����Ӵ˵�ǰֵ���¼���˻���

��ʵ�ϣ�minProduct������ �����ָ���ʱ��Ϊ��֤���ϵ��ҵȴ���������������һ�����ݡ�
*/
int maxProduct(vector<int>& nums) {
    if (nums.empty()) return 0;
    int maxProduct = nums[0], minProduct = nums[0], ans = nums[0];
    for (int i = 1; i < (int)nums.size(); i++) {
        int temp = maxProduct;
        maxProduct = max(max(maxProduct * nums[i], minProduct * nums[i]), nums[i]);
        minProduct = min(min(temp * nums[i], minProduct * nums[i]), nums[i]);
        if (maxProduct > ans) {
            ans = maxProduct;
        }
    }
    return ans;
}

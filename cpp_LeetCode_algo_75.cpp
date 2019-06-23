#include <iostream>
#include <vector>

using namespace std;
void sortColors(vector<int>& nums);

int main(){
    vector<int> nums = {1,2,2,1,1,1,2,0,0};
    sortColors(nums);

    for(auto each : nums){
        cout << each <<" ";
    }
    return 0;
}






/*
    solution: ����˼��
*/
//void sortColors(vector<int>& nums){
//    vector<int> ans(nums.size(), 1);
//
//    int l=0, r=nums.size()-1;
//
//    for(int i=0; i<nums.size(); i++){
//        if(nums[i]==0){
//            ans[l] = 0;
//            l++;
//        }
//        else if(nums[i]==2){
//            ans[r] = 2;
//            r--;
//        }
//    }
//
//    nums = ans;
//}




/*
    solution: ����λ�������˼��, ������ һ��λ��1, ����λ��2, ����λ��3, ...
              ʹ�þ�����ÿ��λ�ö������÷ŵ���.
*/
void sortColors(vector<int>& nums){
    int zero_target_idx=0, two_target_idx=nums.size()-1;
    int i = 0;
    while(i<=two_target_idx){
        if(nums[i]==0){
            swap(nums[zero_target_idx], nums[i]);
            zero_target_idx++;
        }
        else if(nums[i]==2){
            swap(nums[two_target_idx], nums[i]);
            two_target_idx--;
            i--; // ����--��Ŀ���Ǳ��� i ����,
                 // ԭ��: �������ȥ����2, ����������0,
                 // ��ô0Ӧ�û���һ����ǰ���Ļ���, ����ͻ��������������0
        }
        i++;
    }
}




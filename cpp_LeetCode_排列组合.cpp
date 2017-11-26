#include <iostream>
#include <vector>

using namespace std;



/*
ȫ���к���
nums: ����������
n: �������г�ȡn������������
used��ȫΪfalse�����飬Ԫ�ظ���=nums.size()����ʾ�Ƿ�ǰԪ�ر�ʹ��
curr: ��ʼ��Ϊ�����飬����ʱ�ֿ�ʹ��
ans: ��ʼ��Ϊ��2d����, ���ս��2d����
d: �ݹ���ȣ���ʾ��d��ʼ����n-d�εݹ�, ÿ�εݹ�����һ��������ݼ������ݵĸ���
    ����d��ʼ��Ϊ0, ����ֻ�ÿ���n���ɣ�n��ʱ�ɱ�ʾ�������г�ȡn������������
*/
template<typename dType>
void Permutation(vector<dType> nums
                  , int n
                  , vector<bool>& used
                  , vector<dType>& curr
                  , vector<vector<dType>>& ans
                  , int d=0);



/*
ȫ��Ϻ���
nums: ����������
n: �������г�ȡn�����������
curr: ��ʼ��Ϊ�����飬����ʱ�ֿ�ʹ��
ans: ��ʼ��Ϊ��2d����, ���ս��2d����
start_idx: ���ĸ������е�Ԫ�ؿ�ʼ�������γ�ȡ
    start_idx��ʼ��Ϊ0����ʾ���Զ���nums[0th]��ʼ������������ϳ�ȡ������ֱ����ȡ��n����Ϊֹ
d: �ݹ���ȣ���ʾ��d��ʼ����n-d�εݹ�, ÿ�εݹ�����һ��������ݼ������ݵĸ���
    ����d��ʼ��Ϊ0, ����ֻ�ÿ���n���ɣ�n��ʱ�ɱ�ʾ�������г�ȡn�����������
    n-d��ʾC(m,n)�е�m, ��n-dΪ��ȡ����
*/
template<typename dType>
void Combination(vector<dType> nums
                  , int n
                  , vector<dType>& curr
                  , vector<vector<dType>>& ans
                  , int start_idx=0
                  , int d=0);



/*
��������:
ȫ���к���:
ȫ���к�����Ŀ���ǳ�ȡ������n�������в�ͬ�������ȫ�ţ���ô��Ȼ������ÿ��λ���Ϸ��ϲ�ͬ���Ĳ�����
���仰˵�����ǳ�ȡ������һ������������ڵ�ǰ��ȫ�����оͲ������ٳ��֣���������Ҫ��һ������ȥ��¼
ÿ�����ĳ�����������ǳ����˾Ͳ������������Ǽ�����ȡ��һ�����������С�
����鵽n�����ˣ���ʾһ��������ɡ������˻�ȥһ�������Ƿ���û�Ӵ�������������У�
�ѵ�nth����ɾ������ȡ��һ��û�Ӵ����������ϡ�
���Կ���������һ�� ���ϣ��ظ���һ��ȡ���������ɾ��һ���Ź��ģ����ܵ���һ�����ظ�... �Ĺ���
��һ�����Ե� ��ݹ飬Ĩ�� �Ļ��ݹ���.

ȫ��Ϻ�����
������ȫ���к�����ֻ���������ǲ������У�ֻ�ǳ�ȡ��
����ֻ�����ǲ��ǳ�ȡ����ͬ��Ԫ�أ��������ĳ�ȡ˳����ô����������һ����Ԫ�ذ����ã�
��Ϊ�����е�Ԫ�ض��ǲ�ͬ�ģ���ʹ��ֵһ����indexҲ��һ���������ǳ���һ�����ڲ�һ��������ȡ�ͺ��ˡ�
���Բ���Ҫ���������ǲ����Ѿ�����������ˣ�������used��
����϶�Ҳ�� ȡһ�����ظ��ϻس�ȡ���̣�ɾ����һ����ȡ�ģ�����һ�����ٳ�ȡ...
Ҳ��һ����׼�� ���ݡ�
*/


int main(){

    vector<int> nums = {0};
    vector<bool> used(nums.size(), false);
    vector<int> curr;
    vector<vector<int>> ans;

//    Permutation(nums, 2, used, curr, ans);
//    for(auto each1:ans){
//        for(auto each:each1){
//            cout<<each <<" ";
//        }
//        cout <<endl;
//    }
//
//    cout <<endl;

    curr.clear();
    ans.clear();
    Combination(nums, nums.size(), curr, ans, 0, nums.size()-1);
    for(auto each1:ans){
        for(auto each:each1){
            cout<<each <<" ";
        }
        cout <<endl;
    }

    return 0;
}





template<typename dType>
void Permutation(vector<dType> nums
                  , int n
                  , vector<bool>& used
                  , vector<dType>& curr
                  , vector<vector<dType>>& ans
                  , int d=0){
    if(d==n){
        ans.push_back(curr);
        return;
    }

    int i;
    for(i=0;i<(int)nums.size();i++){
        if(used[i]) continue;
        //���ݶԳ�
        used[i] = true;
        curr.push_back(nums[i]);
        Permutation(nums, n, used, curr, ans, d+1);
        curr.pop_back();
        used[i] = false;
    }
}


template<typename dType>
void Combination(vector<dType> nums
                  , int n
                  , vector<dType>& curr
                  , vector<vector<dType>>& ans
                  , int start_idx=0
                  , int d=0){
    if(d==n){
        ans.push_back(curr);
        return;
    }

    int i;
    for(i=start_idx;i<(int)nums.size();i++){
        //���ݶԳ�
        curr.push_back(nums[i]);
        Combination(nums,n,curr,ans,i+1,d+1);
        curr.pop_back();
    }
}

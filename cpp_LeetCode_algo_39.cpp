#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void dfs(vector<int>& nums, int start, int target, vector<int>&curr, vector<vector<int>>& ans);
vector<vector<int>> combinationSum(vector<int>& nums, int target);

int main(){
    vector<int> nums =
    //{2,3,4,5,6,7};
    {5,4,6,2,7,3};

    vector<vector<int>> ans = combinationSum(nums, 7);

    for(auto a : ans){
        for(auto b : a){
            cout<< b << " ";
        }
        cout<< endl;
    }

    return 0;
}



/*
    �������ѵ����ڲ��ܴ洢�ظ�����Ͻ��.
    [2,2,3] �� [2,3,2] �ᱻ������һ�����.
    ����ʵ������������, ȥ�����н���� "�������ͬ��" ���Խ��.
    ����ʵ�е���.
    �ٸ�����, �� [5,6,1,3] ȡ������
    ��һ������:
    ��(1): [5,6,1,3] -> 5��ͷ
    ��(2): [5,6,1,3] -> 5��ͷ
    ��(3): [5,6,1,3] -> 5, 6, 1, 3 ���ȡ

    �ڶ�������:
    ��(1): [5,6,1,3] -> 5��ͷ
    ��(2): [5,6,1,3] -> �����6��ͷ
    ��(3): [5,6,1,3] -> ���������ȡ5�Ļ�, ����[5,6,5], ��[5,5,6] ��ͻ.
    ��ͻ��ԭ����: [5,6,5] �൱�� ��(2)����(3) �Ĵ�ͷ˳����һ��, ����˵ ��(2)����(3) ����һ���ڲ�����.

    ��ô���������ڲ�����?
    ��Ϊ��������һ��Ԫ�ر��ظ�ѡ��, �����ڵݹ������, ��һ��ݹ����Ҫ������ѡ����ǰ�����.
    ������һ��ݹ���, �����ȥ�õ�ǰ��֮ǰ�Ѿ�"����"���Թ�����, �Ϳ��Ա����ڲ�����.
*/
vector<vector<int>> combinationSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    if(nums.empty()) return ans;

    vector<int> curr;

    dfs(nums, 0, target, curr, ans);
    return ans;
}

void dfs(vector<int>& nums, int start, int target, vector<int>&curr, vector<vector<int>>& ans){
    if(target == 0){
        ans.push_back(curr);
        return;
    }

    if(target < 0){
        return;
    }

    for(int i=start; i<(int)nums.size(); i++){
        curr.push_back(nums[i]);
        dfs(nums, i, target-nums[i], curr, ans);
        curr.pop_back();
    }
}



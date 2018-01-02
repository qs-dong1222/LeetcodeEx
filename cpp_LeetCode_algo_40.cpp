#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;
void DFS(vector<int>& candidates, int target, int start_idx, vector<int>& temp, vector<vector<int>>& ans);

int main(){
    vector<int> candidates = {10,1,2,7,6,1,5};
    vector<int> curr;
    vector<vector<int>> ans;

    return 0;
}




vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    if(nums.empty()) return ans;

    vector<int> curr;
    sort(nums.begin(), nums.end());

    dfs(nums, 0, target, curr, ans);
    return ans;
}



void dfs(vector<int>& nums, int start, int target, vector<int>&curr, vector<vector<int>>& ans){
    if(target==0 && start<=(int)nums.size()){
        ans.push_back(curr);
        return;
    }
    else if(start>=(int)nums.size()){
        return;
    }

    for(int i=start;i<(int)nums.size();i++){
        // ��һ��continue������ܹؼ�
        // ������ĿҪ���ǲ��ܳ����ظ���, ��ô���� nums={1,1,2,3}, target=6 ��������
        // ����������'1', ���������ȡʱ��ȡ��һ��'1'�͵ڶ���'1'�ֱ𹹳�[1,2,3]
        // Ϊ�����������, �ڵ�ǰ��λ����(��ǰ�ݹ����), �������֮ǰ�Ѿ��Թ�
        // һ��'1'��, �Ǿ�û��Ҫ����һ��'1'��. ��Ȼ��һ�ε��Ǹ�'1'�Ǳ���Ҫ�Ե�
        if(i>start && nums[i]==nums[i-1]){
            continue;
        }
        if(target-nums[i]<0){
            return;
        }

        // collect this num
        curr.push_back(nums[i]);
        // if use "i+1" for next start index, we will not allow repetitive collection at the same index
        dfs(nums, i+1, target-nums[i], curr, ans);
        curr.pop_back();
    }
}

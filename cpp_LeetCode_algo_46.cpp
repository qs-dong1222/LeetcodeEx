#include <iostream>
#include <vector>

using namespace std;
void per(vector<int>& nums, int start, vector<vector<int>>& ans);
vector<vector<int>> permute(vector<int>& nums);

int main(){

    vector<int> nums =
    {1,2,3};

    vector<vector<int>> ans = permute(nums);

    for(auto eachvec:ans){
        for(auto each : eachvec){
            cout << each << " ";
        }
        cout << endl;
    }

    return 0;
}



vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    if(nums.empty()) return ans;
    per(nums, 0, ans);
    return ans;
}

/*
    ��һ�����ԭʼ����û���ظ�Ԫ��. �������������ַ���������һ�ֽⷨ�����.
    ����, �������ֽⷨ��û�취��� "ԭʼ���麬���ظ�Ԫ��ʱ, ȫ���н�����ظ�" �����.
    Ҫ����, ֻ����hashset�ڴ��ʱȥ���ظ����.
*/


/*
    solution 1: �ڵ�ǰ�ݹ����, ��swap�ķ�ʽ ���ø���λ���ϵ�Ԫ�ش�ͷ.
                ����һ��ݹ���, �� ��ȥ��һ��Ĵ�ͷԪ�� ��ʣ�µ�Ԫ��,����һ��ͬ���Ĵ�ͷ��������.

                ����˵, ���ǰ�ÿһ��ݹ鿴���� "���ڵ�ǰ���ͷλ��, ѡ��ͬ��ͷԪ��" �Ĳ���.
                �ڴ�ͷ��ǰλ���ϰ����е��ܴ�ͷ�Ķ���һ��. ���ߵ���һ��λ��, �������ܴ�ͷ������һ��.
*/
void per(vector<int>& nums, int start, vector<vector<int>>& ans){
    if(start>=nums.size()){
        ans.push_back(nums);
        return;
    }

    for(int i=start; i<(int)nums.size(); i++){
        swap(nums[start], nums[i]);
        per(nums, start+1, ans);
        swap(nums[start], nums[i]);
    }
}



/*
   solution 2: ��ͳ��dfs
*/
void dfs(vector<int>& nums, vector<bool>& used, vector<int>& curr, vector<vector<int>>& ans){
    if(curr.size() == nums.size()){
        ans.push_back(curr);
        return;
    }

    for(int i=0; i<(int)nums.size(); i++){
        if(used[i]) continue;

        curr.push_back(nums[i]);
        used[i] = true;

        dfs(nums, used, curr, ans);

        used[i] = false;
        curr.pop_back();
    }
}

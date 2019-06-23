#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

//�����:
//����һ������, �ҳ����е����������. ÿ��Ԫ���з���/����������ѡ��,
//������������Ԫ������˳������ν. [1,2] �� [2,1] ��һ�����
//
//��������������ͬ������: 1.û�ظ�Ԫ�� 2.���ظ�Ԫ��





// 1. û�ظ�Ԫ��, ����[1,3,2,4]
// ����ܼ�,����û���ظ�Ԫ��.��ôһ����Ԫ�صݹ����,���з���/�������
// �����Ϳ�����. ����Ԫ�ص�����˳��Ҳ����Ҫ.
// �ؼ������ÿ��ݹ�ֻ��һ��Ԫ��, ��Ҫ��ÿ��ݹ����ѭ������.

void combineNoDup(vector<int>& nums, int start, vector<int>& curr, vector<vector<int>>& ans){
    if(start == (int)nums.size()){
        ans.push_back(curr);
        return;
    }

    curr.push_back(nums[start]);
    combineNoDup(nums, start+1, curr, ans);
    curr.pop_back();
    combineNoDup(nums, start+1, curr, ans);
}



//    2. ���ظ�Ԫ��
//    ����ͱȽ�ܳ����. ��[2,3,2]Ϊ��, ��һ��2��3, ������2��3, ���ܹ���[2, 3].
//    ��ô���������ظ�Ԫ�ص����ֵķ����� ������ѡ��/��ѡ�и���Ԫ�� ��Ȼ�ǲ���, �޷�����ظ���.
//    ��ô�Ƚ�ֱ�۵��뷨������set���洢���, ȥ�Զ��޳��ظ�Ԫ��. ����set��[2,3]��[3,2]�ᱻ����
//    �ǲ�ͬԪ��. �������ǲ���Ҫ��. ���������������ԭ����ѡ��2��3���Ⱥ�˳��ͬ. ��һ��2��3
//    �ṹ��[2,3], ������2��3�ṹ��[3,2]. ��ô���ǿ����ȶ�������������, ����ֻ�ܳ�����2��3�����.
//    ���Խⷨ����:
//        (1) ������
//        (2) ��setȥ�洢���ս��, �Ӷ�ȥ���ظ���
//        (3) �����ĺ����ظ�Ԫ�صĽ��һ��





void combineWithSet(vector<int>& nums, int start, vector<int>& curr, set<vector<int>>& ans){
    if(start == (int)nums.size()){
        ans.insert(curr);
        return;
    }

    curr.push_back(nums[start]);
    combineWithSet(nums, start+1, curr, ans);
    curr.pop_back();
    combineWithSet(nums, start+1, curr, ans);
}


void combineHasDup(vector<int>& nums, set<vector<int>>& ans){
    sort(nums.begin(), nums.end());
    vector<int> curr;
    combineWithSet(nums, 0, curr, ans);
}



int main(){
    vector<int> nums = {2,3,2};
    set<vector<int>>ans;

    combineHasDup(nums, ans);

    for(auto eachRow:ans){
        for(auto eachNum:eachRow){
            cout << eachNum << " ";
        }
        cout << endl;
    }

    return 0;
}

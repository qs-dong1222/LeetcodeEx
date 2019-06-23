#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

//组合数:
//给定一个数组, 找出所有得子数组组合. 每个元素有放入/不放入两种选择,
//最终子数组内元素排列顺序无所谓. [1,2] 和 [2,1] 是一种组合
//
//这种题有两个不同的条件: 1.没重复元素 2.有重复元素





// 1. 没重复元素, 比如[1,3,2,4]
// 这个很简单,由于没有重复元素.那么一个个元素递归回溯,进行放入/不放入的
// 操作就可以了. 数组元素的排列顺序也不重要.
// 关键点就是每层递归只动一个元素, 不要在每层递归进行循环遍历.

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



//    2. 有重复元素
//    这个就比较艹淡了. 以[2,3,2]为例, 第一个2和3, 第三个2和3, 都能构成[2, 3].
//    那么用上面无重复元素的那种的方法来 单纯的选中/补选中各个元素 显然是不够, 无法解决重复性.
//    那么比较直观的想法就是用set来存储结果, 去自动剔除重复元素. 但是set中[2,3]和[3,2]会被看成
//    是不同元素. 这是我们不想要的. 而出现这种问题的原因是选中2和3的先后顺序不同. 第一个2和3
//    会构成[2,3], 第三个2和3会构成[3,2]. 那么我们可以先对整个数组排序, 这样只能出现先2后3的情况.
//    所以解法就是:
//        (1) 先排序
//        (2) 用set去存储最终结果, 从而去除重复性
//        (3) 其他的和无重复元素的解放一样





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

#include <iostream>
#include <vector>

using namespace std;



/*
全排列函数
nums: 待处理数组
n: 从数组中抽取n个数进行排列
used：全为false的数组，元素个数=nums.size()，表示是否当前元素被使用
curr: 初始化为空数组，做临时仓库使用
ans: 初始化为空2d数组, 最终结果2d数组
d: 递归深度，表示从d开始进行n-d次递归, 每次递归增加一个结果数据集内数据的个数
    由于d初始化为0, 我们只用考虑n即可，n此时可表示从数组中抽取n个数进行排列
*/
template<typename dType>
void Permutation(vector<dType> nums
                  , int n
                  , vector<bool>& used
                  , vector<dType>& curr
                  , vector<vector<dType>>& ans
                  , int d=0);



/*
全组合函数
nums: 待处理数组
n: 从数组中抽取n个数进行组合
curr: 初始化为空数组，做临时仓库使用
ans: 初始化为空2d数组, 最终结果2d数组
start_idx: 从哪个数组中的元素开始进行依次抽取
    start_idx初始化为0，表示会自动从nums[0th]开始依次向后进行组合抽取操作，直到抽取完n个数为止
d: 递归深度，表示从d开始进行n-d次递归, 每次递归增加一个结果数据集内数据的个数
    由于d初始化为0, 我们只用考虑n即可，n此时可表示从数组中抽取n个数进行组合
    n-d表示C(m,n)中的m, 即n-d为抽取个数
*/
template<typename dType>
void Combination(vector<dType> nums
                  , int n
                  , vector<dType>& curr
                  , vector<vector<dType>>& ans
                  , int start_idx=0
                  , int d=0);



/*
究极分析:
全排列函数:
全排列函数的目的是抽取数组中n个数进行不同序的乱序全排，那么必然会有在每个位置上放上不同数的操作。
换句话说，我们抽取并放了一个数后，这个数在当前的全排序中就不可能再出现，所以我们要用一个数组去记录
每个数的出现情况，若是出现了就不再用它，而是继续抽取下一个数进行排列。
如果抽到n个数了，表示一种排列完成。我们退回去一步，看是否还有没接触过的数。如果有，
把第nth个数删掉，抽取下一个没接触过的数放上。
可以看出这里有一个 放上，重复上一抽取排序操作，删上一个放过的，再跑到下一个数重复... 的过程
是一个明显的 填，递归，抹除 的回溯过程.

全组合函数：
类似于全排列函数，只是这里我们不再排列，只是抽取。
我们只考虑是不是抽取到不同的元素，并不关心抽取顺序。那么就在数组里一个个元素挨个拿，
因为数组中的元素都是不同的，即使数值一样，index也不一样，即他们长的一样内在不一样，挨个取就好了。
所以不需要考虑我们是不是已经摸过这个数了，即不用used。
这里肯定也有 取一个，重复上回抽取过程，删除上一个抽取的，换下一个数再抽取...
也是一个标准的 回溯。
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
        //回溯对称
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
        //回溯对称
        curr.push_back(nums[i]);
        Combination(nums,n,curr,ans,i+1,d+1);
        curr.pop_back();
    }
}

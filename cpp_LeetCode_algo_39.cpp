/*
求一正整数数组中，元素和为target的所有子元素数组
*/


/*
这个题第一次做，挺难。
思想是利用回溯法进行搜索。
怎么用回溯法？怎么搜索？
回溯法肯定要递归了，题目还要求子元素数组了，那肯定要拿一个空数组去一个个元素去收集，
还要一个2d的数组去收集所有 已找到且符合条件的数组
既然要递归，我们先假设我们有个函数能根据target的要求，把当前数组里的一个数放进收集数组里
回溯法，我们得先试着去做，并且假设做的是成立的。
好，假设有一个数组[2,3,6,7] target=7
我们就一个个数来摸。 先放第一个数 2 到收集数组里去，并假设放的是对的，那么我们就可以放第二个数了，
并且由于假设我们放的对，此时的target就从7变成了7-5=2. 然后再对其余的数递归调用函数，再假设成立，
再放进去，再改target。
边界条件是啥？ 假设我们放了一个数，放完后我们的target剩下0，那就说明我们前面收集的数正好，把收集数组
打个包返回就好了。
如果刚才我们放的数放完之后，target变成了负数，那么说明刚才收集的那个数是不应该被收集的。
那么我们就返回上一步，抹去刚才放了的数，target也变上一步，接着跑到下一个数，再递归。

所以整体上来看，就是从每一个数开始，进行层层递归，收集完成就打包，收集失败就返回抹除(回溯)
*/

#include <vector>
#include <iostream>

using namespace std;
void DFS(vector<int>& candidates, int target, int start_idx, vector<int>& curr, vector<vector<int>>& ans);

int main(){
    vector<int> cadidates = {2,3,6,7};
    vector<int> curr;
    vector<vector<int>> ans;
    DFS(cadidates, 7, 0, curr, ans);

    for(auto a : ans){
        for(auto b : a){
            cout<< b << " ";
        }
        cout<< endl;
    }

    return 0;
}







/*
start_idx: 起始搜索位置
*/
void DFS(vector<int>& candidates, int target, int start_idx, vector<int>& curr, vector<vector<int>>& ans) {
    // 刚才放的数不对 放超了 返回上一步
    if(target < 0){
        return;
    }
    // 刚才放的数刚刚好 收集数组也放好了 打个包 结束
    if(target == 0){
        ans.push_back(curr);
        return;
    }

    int i;
    // 对每一个元素进行深度检测递归
    for(i=start_idx;i<candidates.size();i++) {
        // 如果当前这个元素已经比target还大了，我们还试个P？ 直接试下一个元素去
        if(candidates[i] > target){
            continue;
        }
        // 假设当前的这个元素能被收集，我们先收集着试试。
        curr.push_back(candidates[i]);
        // 基于当前数能被收集的条件，我们进行新一轮的检测，并且由于当前元素被收集，target也要变
        DFS(candidates, target-candidates[i], i, curr, ans);
        // 跑到这就两种形况，要么找到合适的数打包存好了，返回了。此时我们应该去试下一个数，
        // 看看是不是下一个数是不是也能满足收集要求，那么我们得把上一个成立的数删掉
        // 要么失败了没找着，说明放进去那个假设成立的数是错的，得删掉
        // 综上，无论假设是成功还是失败，都得删放进去的假设的那个数
        curr.pop_back();
    }
}

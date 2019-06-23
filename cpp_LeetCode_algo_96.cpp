#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int, int> ansmap;

int numTrees(int n);
vector<int> genVec(int n);
int NbrOfAllSubtreesGivenNums(vector<int>& nums, int l_end, int r_end);
int encode(int a, int b);


int main(){

    int ans = numTrees(3);
    cout << ans << endl;
    return 0;
}


/*
����ⷨ˼·(���յ�95��):
F(idx,nums) ������nums[idx] Ϊ�����ʱ�����п������tree�ĸ���
G(lidx, ridx, nums) ���طֱ��� nums[lidx]~nums[ridx] Ϊ�����ʱ�����еĿ������tree�ĸ����������п�����
���Կ��� F(idx,nums) = G(0, idx-1, nums) * G(idx+1, nums.size()-1, nums)
���������ƶϳ� G(lidx, ridx, nums) = G(..)*G(..) + G(..)*G(..) + ... + G(..)*G(..)
*/
int numTrees(int n) {
    if(n==0) return 1;
    vector<int> nums = genVec(n);
    return NbrOfAllSubtreesGivenNums(nums, 0, nums.size()-1);
}


vector<int> genVec(int n){
    vector<int> ans;
    if(n==0) return ans;

    for(int i=1;i<=n;i++)
        ans.push_back(i);
    return ans;
}


int NbrOfAllSubtreesGivenNums(vector<int>& nums, int l_end, int r_end){
    if(ansmap.find(encode(l_end, r_end)) != ansmap.end())
        return ansmap[encode(l_end, r_end)];

    int ans = 0;

    if(l_end > r_end){
        // there is no subtree, it only has NULL. so return 1
        return 1;
    }

    for(int i=l_end; i<=r_end; i++){
        int n_allLeftSubtrees = NbrOfAllSubtreesGivenNums(nums, l_end, i-1);
        int n_allRighttSubtrees = NbrOfAllSubtreesGivenNums(nums, i+1, r_end);
        ansmap[encode(l_end, i-1)] = n_allLeftSubtrees;
        ansmap[encode(i+1, r_end)] = n_allRighttSubtrees;
        ans += n_allLeftSubtrees * n_allRighttSubtrees;
    }

    return ans;
}


int encode(int a, int b){
    return ((a*7)<<3)+b;
}


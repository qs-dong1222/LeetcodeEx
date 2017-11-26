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

    sort(candidates.begin(), candidates.end());

    DFS(candidates, 8, 0, curr, ans);

    set<vector<int>> s;
    for(auto each : ans){
        s.insert(each);
    }
    ans.clear();
    for(auto each:s){
        ans.push_back(each);
    }

    for(auto a : ans){
        for(auto b : a){
            cout<< b << " ";
        }
        cout<< endl;
    }

    return 0;
}




void DFS(vector<int>& candidates, int target, int start_idx, vector<int>& temp, vector<vector<int>>& ans){
    if(target < 0){
        return;
    }

    if(target == 0){
        ans.push_back(temp);
        return;
    }

    int i;
    for(i=start_idx;i<(int)candidates.size();i++){
        if(candidates[i] > target){
            return;
        }

        temp.push_back(candidates[i]);
        DFS(candidates,target-candidates[i],i+1,temp,ans);
        temp.pop_back();
    }
}

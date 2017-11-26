#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
vector<int> grayCode(int n);

int main(){
    vector<int> ans = grayCode(2);

    for(auto each:ans){
        cout << each << " ";
    }

    return 0;
}



vector<int> grayCode(int n){
    if(n==0) return vector<int>(1,0);

    vector<int> ans;
    int totTimes = 1<<(n-1);
    ans = grayCode(n-1);
    for(int i=totTimes-1; i>=0; i--){
        ans.push_back(ans[i]+totTimes);
    }
    return ans;
}

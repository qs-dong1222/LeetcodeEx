#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
string largestNumber(vector<int>& nums) ;
bool compare(const string& s1, const string& s2);

int main(){
    vector<int> nums = {998,9,9821,75};
    cout << largestNumber(nums) << endl;

    return 0;
}


static bool compare(const string& s1, const string& s2){
    return s1+s2 > s2+s1;
}

string largestNumber(vector<int>& nums) {
    string ans;
    if(nums.empty()) return ans;

    vector<string> numstr;
    for(auto each : nums){
        numstr.push_back(to_string(each));
    }

    sort(numstr.begin(), numstr.end(), compare);

    for(auto each:numstr){
        ans += each;
    }

    if(ans[0]=='0') return "0";
    return ans;
}

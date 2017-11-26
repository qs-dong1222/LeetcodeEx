#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>
#include <unordered_set>


using namespace std;
int longestConsecutive(vector<int>& nums);

int main(){
    vector<int> nums = {4,0,-4,-2,2,5,2,0,-8,-8,-8,-8,-1,7,4,5,5,-4,6,6,-3};
    cout << longestConsecutive(nums) << endl;

    return 0;
}



int longestConsecutive(vector<int>& nums) {
    if(nums.empty()) return 0;
    // map key is the number met, value is the length of the sequence where it belongs
    unordered_map<int, int> nmap;
    int ans = INT_MIN;
    for(auto each : nums){
        if(!nmap.count(each)){
            // this is a new number
            // see if it is a number that can connect 2 sequences
            int leftLen = nmap.count(each-1)? nmap[each-1] : 0;
            int rightLen = nmap.count(each+1)? nmap[each+1] : 0;

            int newSeqLen = leftLen + rightLen + 1;
            nmap[each] = newSeqLen;

            int leftBoundKey = each - leftLen;
            int rightBoundKey = each + rightLen;
            nmap[leftBoundKey] = newSeqLen;
            nmap[rightBoundKey] = newSeqLen;

            ans = max(ans, newSeqLen);
        }
    }

    return ans;
}

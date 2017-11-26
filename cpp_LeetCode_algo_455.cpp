#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;
int findContentChildren(vector<int>& g, vector<int>& s) ;

int main(){
    vector<int> child = {1,2,3};
    vector<int> cookies = {1,1};

    int ans = findContentChildren(child, cookies);
    cout << ans << endl;

    return 0;
}




int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    vector<int> atIdx;

    int j=0;
    for(int i=0;i<(int)g.size();i++){
        while(j<(int)s.size()){
            if(s[j]>=g[i]){
                atIdx.push_back(j);
                j++;
                break;
            }
            else j++;
        }
    }

//    // find number of possibilities of all the potential assignment
//    vector<int>::reverse_iterator it;
//    int ans = 1;
//    int size = s.size();
//    for(it=atIdx.rbegin(); it!=atIdx.rend(); it++){
//        ans *= (size - *it);
//        size--;
//    }

    return atIdx.size();
}

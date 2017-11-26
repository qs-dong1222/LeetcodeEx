#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>

using namespace std;
int candy(vector<int>& ratings);

int main(){

    vector<int> ratings = {1,4,3,1,2,4,1,2,6,5,5,5};

    candy(ratings);
    return 0;
}


int candy(vector<int>& ratings) {
    if(ratings.empty()) return 0;
    if(ratings.size()==1) return 1;

    vector<int> ans(ratings.size(), 1);

    for(int i=ratings.size()-2;i>=0;i--){
        if(ratings[i] > ratings[i+1]){
            ans[i] = ans[i+1] + 1;
        }
//        else if(ratings[i] == ratings[i+1]){
//            ans[i] = ans[i+1];
//        }
        else if(ratings[i] < ratings[i+1]){
            int j = i;
            while(ans[j+1] <= ans[j] && ratings[j+1]>ratings[j]){
                ans[j+1] = ans[j]+1;
                j++;
            }
        }
    }

    int ret = 0;
    for(auto each:ans){
        ret += each;
        cout << each << " ";
    }

    return ret;
}

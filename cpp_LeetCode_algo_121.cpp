#include <iostream>
#include <vector>

using namespace std;
int maxProfit(vector<int>& prices);

int main(){

    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << maxProfit(prices) << endl;

    return 0;
}


int maxProfit(vector<int>& prices) {
    if(prices.empty()) return 0;

    int ans = 0;
    int metMin = prices[0];
    for(int i=1;i<prices.size(); i++){
        metMin = min(prices[i], metMin);
        ans = max(prices[i]-metMin, ans);
    }

    return ans;
}


/*
DP :long time execution
*/
//int maxProfit(vector<int>& prices) {
//    if(prices.empty()) return 0;
//    int* ans = new int[prices.size()]{0};
//
//    ans[0] = 0;
//    int res = 0;
//    int metMin = prices[0];
//    for(int i=1;i<prices.size(); i++){
//        if(prices[i] < metMin){
//            metMin = prices[i];
//            continue;
//        }
//
//        for(int j=i-1; j>=0; j--){
//            if(prices[j] < prices[i]){
//                ans[i] = ans[j] + (prices[i] - prices[j]);
//                res = max(res, ans[i]);
//                break;
//            }
//        }
//    }
//
//    delete [] ans;
//    return res;
//}

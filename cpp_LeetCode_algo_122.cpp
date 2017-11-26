#include <iostream>
#include <vector>

using namespace std;
int maxProfit(vector<int>& prices);

int main(){

    vector<int> prices = {1, 5, 2, 3, 10};

    cout << maxProfit(prices) << endl;

    return 0;
}


int maxProfit(vector<int>& prices){
    if(prices.empty()) return 0;

    int ans = 0;
    int metMin = prices[0];

    for(int i=1; i<prices.size(); i++){
        if(prices[i] > metMin){
            ans += (prices[i] - metMin);
            metMin = prices[i];
        }
        else
            metMin = min(prices[i], metMin);
    }

    return ans;
}

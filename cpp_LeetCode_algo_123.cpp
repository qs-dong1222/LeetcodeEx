#include <iostream>
#include <vector>

using namespace std;
int maxProfit(vector<int>& prices);

int main(){

    vector<int> prices = {0};

    cout << maxProfit(prices) << endl;

    return 0;
}





/*
没啥话说，无奈，就两个字，牛B

First assume that we have no money, so buy1 means that we have to borrow money from others,
we want to borrow less so that we have to make our balance as max as we can(because this is negative).

sell1 means we decide to sell the stock, after selling it we have price[i] money and we have to give back the money we owed,
so we have price[i] - |buy1| = prices[i ] + buy1, we want to make this max.

buy2 means we want to buy another stock, we already have sell1 money,
so after buying stock2 we have buy2 = sell1 - price[i] money left,
we want more money left, so we make it max

sell2 means we want to sell stock2, we can have price[i] money after selling it,
and we have buy2 money left before, so sell2 = buy2 + prices[i], we make this max.

So sell2 is the most money we can have.
*/
int maxProfit(vector<int>& prices){
    int sell1 = 0, sell2 = 0, buy1 = INT_MIN, buy2 = INT_MIN;
    for (int i = 0; i < prices.size(); i++) {
        buy1 = max(buy1, -prices[i]);
        sell1 = max(sell1, buy1 + prices[i]);
        buy2 = max(buy2, sell1 - prices[i]);
        sell2 = max(sell2, buy2 + prices[i]);
    }
    return sell2;
}





/*
brute force : time limit exceeded
*/
//int maxProfit(vector<int>& prices){
//    if(prices.empty()) return 0;
//
//    int* firstTrasaction = new int[prices.size()]{0};
//
//    int ans = 0;
//    int metMin = prices[0];
//    for(int i=1;i<(int)prices.size(); i++){
//        metMin = min(prices[i], metMin);
//        firstTrasaction[i] = prices[i]-metMin;
//        ans = max(ans, firstTrasaction[i]);
//    }
//
//    for(int i=2; i<=(int)prices.size()-2; i++){
//        metMin = prices[i];
//        for(int j=i+1; j<(int)prices.size(); j++){
//            metMin = min(prices[j], metMin);
//            ans = max(ans, (prices[j]-metMin)+firstTrasaction[i-1]);
//        }
//    }
//
//    return ans;
//}

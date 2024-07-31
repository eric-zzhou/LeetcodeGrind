// https://neetcode.io/problems/buy-and-sell-crypto-with-cooldown
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solutions/75927/share-my-thinking-process/comments/173646

#include <vector>
using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<int> buy(n + 1);
    vector<int> sell(n + 1);
    int price;

    // Force it to buy the first time
    buy[1] = -prices[0];

    // Iterate through prices
    for (int i = 2; i <= n; i++) {
      price = prices[i - 1];
      // End buy is the optimal of buy and wait from prev and sell and buy
      buy[i] = max(sell[i - 2] - price, buy[i - 1]);
      // End sell is the optimal of sell and wait from prev and buy and sell
      sell[i] = max(sell[i - 1], buy[i - 1] + price);
    }
    return sell[n];
  }
};

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int buy(INT_MIN), sell(0), prev_sell(0), prev_buy;
    for (int price : prices) {
      prev_buy = buy;
      buy = max(prev_sell - price, buy);
      prev_sell = sell;
      sell = max(prev_buy + price, sell);
    }
    return sell;
  }
};

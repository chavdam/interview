#include <iostream>
#include <vector>
#include <unordered_map>
#include<algorithm>
#include<map>
#include<queue>

using namespace std;

int maxProfit(vector<int>& prices){
  int maxProfit = INT_MIN;
  int minPrice = INT_MAX;
  for(int i=0; i<prices.size(); i++){
    if(minPrice > prices[i]){
      minPrice = prices[i];
    }
    int currProfit = prices[i] - minPrice;
    if(maxProfit < currProfit){
      maxProfit = currProfit;
    }
  }
  return maxProfit;
}

int main(){

  int prices[] = {200, 500, 1000, 700, 30, 400, 900, 400, 50};
  vector<int> v(prices, prices + sizeof(prices)/sizeof(prices[0]));
  cout << maxProfit(v);
  return 0;
}
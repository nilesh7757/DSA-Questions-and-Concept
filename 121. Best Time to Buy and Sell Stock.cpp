#include<climits>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = INT_MAX ;
        int maxP = 0;
        for(int i = 0; i<prices.size(); i++){
            if(min > prices[i]) min = prices[i];
            maxP = max(maxP,prices[i]-min);
        }
        return maxP;
    }
};

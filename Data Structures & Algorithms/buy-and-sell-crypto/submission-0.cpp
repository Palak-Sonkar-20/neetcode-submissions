class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int low= INT_MAX;
       int diff = 0;
       int maxprofit = 0;
       for(int i =0 ; i<prices.size() ; i++){
            if(prices[i]<low){
                low= prices[i];
            }
            diff = prices[i]-low;
            maxprofit = max(diff , maxprofit);

       }
       return maxprofit;
        
    }
};

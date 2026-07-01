class Solution {
public:
    int maxProfit(vector<int>& price) {
        //imagine everyday as selling day
        int maxPr=0;
        int bestbuy=INT_MAX;
        int n=price.size();
        for(int i=0;i<n;i++){
            bestbuy=min(bestbuy,price[i]);
            if(price[i]>bestbuy)
            maxPr=max(maxPr,price[i]-bestbuy);
        }
        return maxPr;
    }
};

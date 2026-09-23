class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxp=0;
        int minp=INT_MAX;
        for(int price:prices){
            if(price<minp)minp=price;
            else{
                maxp=max(maxp,price-minp);
            }
        }
        return maxp;
    }
};
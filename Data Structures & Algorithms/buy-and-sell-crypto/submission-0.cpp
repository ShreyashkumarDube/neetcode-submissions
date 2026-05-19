class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        for (int i = 0; i < n; i++) {
            int buy = prices[i];
            for (int j = i + 1; j <n; j++) {
                int sell = prices[j];
                ans = max(ans, sell - buy);
            }
        }
        return ans;
    }
};
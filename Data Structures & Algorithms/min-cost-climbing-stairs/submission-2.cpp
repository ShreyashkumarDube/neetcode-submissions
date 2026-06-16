class Solution {
public:
int dp[101];
    int solve(vector<int> &cost, int i){
        if(i>= cost.size()) return 0;

        if(dp[i] != -1) return dp[i];

        return dp[i] = cost[i] + min(solve(cost, i+1), solve(cost, i+2));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        for(int i=0; i<101; i++){
            dp[i] = -1;
        }
        return min(solve(cost, 0), solve(cost, 1));
    }
};

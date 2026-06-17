class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int curmini = 1, curMax = 1;

        for (int i : nums) {
            int tmp = curMax * i;
            curMax = max(max(i * curMax, i * curmini), i);
            curmini = min(min(tmp, i * curmini), i);
            ans = max(ans, curMax);
        }
        return ans;
    }
};
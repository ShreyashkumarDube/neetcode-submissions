class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        int cur = 0;
        unordered_map<int, int> mpp;
        mpp[0] = 1;

        for(auto i: nums){
            cur += i;
            int dif = cur - k;
            ans += mpp[dif];
            mpp[cur]++;
        }
        return ans;
    }
};
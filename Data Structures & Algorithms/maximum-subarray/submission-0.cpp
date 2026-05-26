class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = 0;
        int sum = nums[0];

        for(int i=0; i<nums.size(); i++){
            if(cur<0) cur = 0;
            cur += nums[i];

            sum = max(sum, cur);
        }
        return sum;
    }
};

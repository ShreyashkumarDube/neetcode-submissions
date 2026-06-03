class Solution {
public:

    bool fun(vector<int> &nums, int k, int mid){
        int ans = 1;
        int cur = 0;

        for(auto i: nums){
            cur += i;
            if(cur > mid){
                ans++;
                if(ans > k) return false;
                cur = i;
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);
        int ans = r;


        while(l<=r){
            int mid = l + (r-l)/2;

            if(fun(nums, k, mid)){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};
class Solution {
public:

    bool fun(vector<int> &weights, int days, int mid){
        int ships = 1, curr = mid;
        for (int i : weights) {
            if (curr - i < 0) {
                ships++;
                if (ships > days) {
                    return false;
                }
                curr = mid;
            }
            curr -= i;
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());

        int r= accumulate(weights.begin(), weights.end(), 0);

        int ans = r;

        while(l<=r){
            int mid = (l+r)/2;

            if(fun(weights, days, mid)){
                ans = min(ans, mid);
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};
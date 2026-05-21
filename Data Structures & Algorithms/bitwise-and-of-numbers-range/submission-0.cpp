class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = left;

        for(int j= left + 1; j<= right; j++){
            ans &= j;
        }
        return ans; 
    }
};
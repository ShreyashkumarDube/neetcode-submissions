class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp = nums;

        for(int i=0; i<n; i++){
            tmp.push_back(nums[i]);
        }
        return tmp;
    }
};
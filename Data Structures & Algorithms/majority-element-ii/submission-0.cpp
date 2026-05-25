class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int valid = floor(n/3);

        unordered_map<int, int> mpp;

        for(auto i: nums){
            mpp[i]++;
        }


        vector<int> ans;
        for(auto i: mpp){
            if(i.second >valid){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};
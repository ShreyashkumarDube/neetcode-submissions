class Solution {
public:
    int maxDifference(string s) {
        vector<int> cnt(26, 0);

        for(auto i: s){
            cnt[i-'a']++;
        }

        int ans = INT_MIN;

        for(auto i: cnt){
            if(i==0 || i%2 == 0) continue;
            for(auto j:cnt){
                if(j==0 || j%2 == 1) continue;
                ans = max(ans, i-j);
            }
        }
        return ans;
    }
};
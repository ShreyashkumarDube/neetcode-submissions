class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;

        unordered_set<char> st(s.begin(), s.end());

        for(auto i: st){
            int cnt = 0;
            int l = 0;

            for(int r = 0; r<s.size(); r++){
                if(s[r] == i) cnt++;

                while((r-l+1)-cnt > k){
                    if(s[l] == i) cnt--;
                    l++;
                }
                ans = max(ans, r-l+1);
            }
        }
        return ans;
    }
};

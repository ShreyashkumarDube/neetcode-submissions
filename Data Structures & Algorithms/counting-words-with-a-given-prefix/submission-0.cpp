class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;

        for(auto i: words){
            if(i.starts_with(pref)) ans++;
        }
        return ans;
    }
};
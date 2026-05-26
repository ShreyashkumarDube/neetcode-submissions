class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt = 0;
        for(auto i: s){
            if(i=='1') cnt++;
        }

        string ans((cnt - 1), '1');
        ans += string(s.length() - cnt, '0');
        ans += '1';

        return ans;
    }
};
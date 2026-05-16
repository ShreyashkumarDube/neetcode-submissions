class Solution {
public:
    bool isAnagram(string s, string t) {
       if(s.length() != t.length()) return false;

       unordered_map<char, int> cntS, cntT;

       for(int i=0; i<s.length(); i++){
        cntS[s[i]]++;
        cntT[t[i]]++;
       }
       return cntS == cntT;
    }

};

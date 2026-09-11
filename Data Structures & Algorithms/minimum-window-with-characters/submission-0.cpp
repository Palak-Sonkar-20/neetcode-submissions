class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char , int> mp1;
        unordered_map<char , int> mp2;
        for(char ch: t){
            mp1[ch]++;
        }
        int slen = INT_MAX;
        int formed = 0;
        int l =0;
        int r=0;
        int start = 0;
        int required = mp1.size();
        
        while(r<s.length()){
            char c = s[r];
            mp2[c]++;
            if(mp1.count(c) && mp2[c]== mp1[c]) formed++;
            while(formed == required){
                if(r-l+1< slen){
                    slen = r-l+1;
                    start = l;
                }
                char removeChar= s[l];
                mp2[removeChar]--;
                if(mp1.count(removeChar)&& mp2[removeChar]<mp1[removeChar]){
                    formed--;
                }
                l++;
            }
            r++;
        }
        if(slen == INT_MAX){
            return "";
        }
        return s.substr(start, slen);        
    }
};

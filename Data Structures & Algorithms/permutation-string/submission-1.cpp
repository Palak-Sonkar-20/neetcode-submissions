class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.length() > s2.length())
            return false;

        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;

        for (char ch : s1) {
            mp1[ch]++;
        }

        int k = s1.length();

        for (int i = 0; i < k; i++) {
            mp2[s2[i]]++;
        }

        if (mp1 == mp2)
            return true;

        for (int right = k; right < s2.length(); right++) {

            char leftChar = s2[right - k];

            mp2[leftChar]--;

            if (mp2[leftChar] == 0) {
                mp2.erase(leftChar);
            }

            mp2[s2[right]]++;

            if (mp1 == mp2)
                return true;
        }

        return false;
    }
};
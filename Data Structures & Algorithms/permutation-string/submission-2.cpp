class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.length() > s2.length())
            return false;

        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;

        for (char c : s1) {
            mp1[c]++;
        }

        int k = s1.length();

        // First window
        for (int i = 0; i < k; i++) {
            mp2[s2[i]]++;
        }

        if (mp1 == mp2)
            return true;

        // Sliding window
        for (int j = k; j < s2.length(); j++) {

            // Remove leftmost character
            char lc = s2[j - k];

            mp2[lc]--;

            if (mp2[lc] == 0) {
                mp2.erase(lc);
            }

            // Add new character
            mp2[s2[j]]++;

            if (mp1 == mp2)
                return true;
        }

        return false;
    }
};
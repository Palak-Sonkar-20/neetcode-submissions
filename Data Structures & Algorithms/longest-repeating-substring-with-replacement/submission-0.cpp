class Solution {
public:
    int characterReplacement(std::string s, int k) {
        std::vector<int> count(26, 0);
        int l = 0;
        int maxCount = 0;
        int maxLength = 0;

        for (int r = 0; r < s.length(); r++) {
            // Update frequency of current character
            count[s[r] - 'A']++;
            
            // Track frequency of the most common character in the window
            maxCount = std::max(maxCount, count[s[r] - 'A']);

            // Current window size is (r - l + 1)
            // If replacements needed > k, shrink window from left
            while ((r - l + 1) - maxCount > k) {
                count[s[l] - 'A']--;
                l++;
            }

            // Update maximum valid length seen so far
            maxLength = std::max(maxLength, r - l + 1);
        }

        return maxLength;
    }
};
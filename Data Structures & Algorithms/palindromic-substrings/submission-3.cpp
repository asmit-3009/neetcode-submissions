class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); i = i + 1) {
            int low = i;
            int high = i;
            while (low >= 0 && high < s.size()) {
                if (s[low] == s[high]) {
                    count = count + 1;
                } else {
                    break;
                }
                low = low - 1;
                high = high + 1;
            }
            low = i;
            high = i + 1;
            while (low >= 0 && high < s.size()) {
                if (s[low] == s[high]) {
                    count = count + 1;
                } else {
                    break;
                }
                low = low - 1;
                high = high + 1;
            }
        }
        return count;
    }
};
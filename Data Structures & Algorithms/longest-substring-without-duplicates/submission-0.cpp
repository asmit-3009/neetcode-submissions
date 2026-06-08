class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char, int> lastSeen;  
        int maxLen = 0;
        int left = 0;
        
        for(int right = 0; right < n; right++){
            char c = s[right];
            
            if(lastSeen.count(c) && lastSeen[c] >= left){
                left = lastSeen[c] + 1; 
            }
            
            lastSeen[c] = right;  
            int len = right - left + 1;  
            maxLen = max(maxLen, len);
        }
        
        return maxLen;
    }
};
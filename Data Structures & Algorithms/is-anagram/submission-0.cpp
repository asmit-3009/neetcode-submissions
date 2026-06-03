class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        vector<int> cnt(26, 0);
        for(char c : s){
            cnt[c - 'a'] += 1;
        }

        for(char c : t){
            if(cnt[c - 'a'] == 0) return false;
            cnt[c - 'a'] -= 1;
        }
        return true;
    }
};

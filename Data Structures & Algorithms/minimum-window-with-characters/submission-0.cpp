class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hash;
        int m = t.length();
        int l = 0, r = 0, minLen = INT_MAX, s_ind = -1, cnt= 0;
        for(int i = 0; i < m; i++) hash[t[i]]++;
        while(r < s.length()){
            if(hash.find(s[r]) != hash.end() && hash[s[r]] > 0) cnt++;
            hash[s[r]]--;
            while(cnt == m){
                if(r - l + 1 < minLen){ 
                    minLen = r - l + 1;
                    s_ind = l;
                }
                hash[s[l]]++;
                if(hash.find(s[l]) != hash.end() && hash[s[l]] > 0) cnt--;
                l++;
            }
            r++;
        }
        return s_ind == -1 ? "" : s.substr(s_ind, minLen);
    }
};

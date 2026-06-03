class Solution {
private:
    bool is_anagram(string s, string t){
        if (s.length() != t.length()) {
            return false;
        }

        vector<int> count(26, 0);

        for (char c : s) {
            count[c - 'a'] += 1;
        }

        for (char c : t) {
            if (count[c - 'a'] == 0) {
                return false;
            }
            count[c - 'a'] -= 1;
        }

        return true;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<string> ds;
        int n = strs.size();
        vector<int> vis(n, 0);
        for(int i = 0; i < n; i++){
            if(vis[i] == 1) continue;
            ds.push_back(strs[i]);
            vis[i] = 1;
            for(int j = i + 1; j < n; j++){
                if(is_anagram(strs[i], strs[j])){
                    ds.push_back(strs[j]);
                    vis[j] = 1;
                }
            }
            ans.push_back(ds);
            ds.clear();
        }  
        return ans;
    }
};

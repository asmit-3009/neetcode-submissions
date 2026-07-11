class Solution {
private:
    bool isPal(int l, int r, string& s){
        while(l < r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
public:
    int countSubstrings(string s) {
        int n = s.length();
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(isPal(i, j, s)) ans++;
            }
        }
        return ans;
    }
};

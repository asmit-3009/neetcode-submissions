class Solution {
public:
    int f(int ind, int start, vector<int>& arr, vector<int>& dp){
        // ✅ Out of range
        if(ind < start) return 0;
        
        // ✅ Base case: first valid house
        if(ind == start) return arr[ind];
        
        // ✅ Already computed
        if(dp[ind] != -1) return dp[ind];
        
        // ✅ Rob current house
        int pick = arr[ind] + f(ind - 2, start, arr, dp);
        
        // ✅ Skip current house
        int not_pick = f(ind - 1, start, arr, dp);
        
        return dp[ind] = max(pick, not_pick);
    }
    
    int rob(vector<int>& arr) {
        int n = arr.size();
        
        // ✅ Edge case: 0 houses
        if(n == 0) return 0;
        
        // ✅ Edge case: 1 house (no circular conflict)
        if(n == 1) return arr[0];
        
        // ✅ Edge case: 2 houses (pick max)
        if(n == 2) return max(arr[0], arr[1]);
        
        // ✅ CASE 1: Exclude last house (rob 0 to n-2)
        vector<int> dp1(n, -1);
        int case1 = f(n - 2, 0, arr, dp1);
        
        // ✅ CASE 2: Exclude first house (rob 1 to n-1)
        vector<int> dp2(n, -1);
        int case2 = f(n - 1, 1, arr, dp2);
        
        // ✅ Return maximum
        return max(case1, case2);
    }
};
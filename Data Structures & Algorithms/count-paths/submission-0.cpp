/*class Solution {
private:
    int f(vector<vector<int>> &dp, int i, int j, int m, int n){
        if(i == (m - 1) && j == (n - 1)) return 1;
        if(i >= m || j >= n) return 0;
        if(dp[i][j] != -1) return dp[m][n];
        return dp[i][j] = f(dp,i + 1, j, m, n) + f(dp, i, j + 1, m, n);
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(dp, 0, 0, m, n);
    }
};
*/
class Solution {
private:
    int f(vector<vector<int>> &dp, int m, int n){
        if(m == 0 && n == 0) return 1;
        if(m < 0 || n < 0) return 0;    // ✅ Fixed: out of bounds check
        if(dp[m][n] != -1) return dp[m][n];
        return dp[m][n] = f(dp, m - 1, n) + f(dp, m, n - 1);
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(dp, m - 1, n - 1);  // ✅ Call with (m-1, n-1)
    }
};

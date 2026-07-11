class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxReach = 0;  // ✅ Maximum index we can reach
        
        for(int i = 0; i < n; i++){
            // ✅ If current position is unreachable, return false
            if(i > maxReach) return false;
            
            // ✅ Update the farthest position we can reach
            maxReach = max(maxReach, i + nums[i]);
            
            // ✅ Early termination if we can reach the end
            if(maxReach >= n - 1) return true;
        }
        
        return true;
    }
};
class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        int n = nums.size();
        for (auto num : nums) {
            cnt[num]++;
        }
        vector<vector<int>> freq(n + 1);
        for(auto& [e, c] : cnt){
            freq[c].push_back(e);
        }
        vector<int> res;
        for(int i = n; i > 0; i--){
            for(int e : freq[i]){
                res.push_back(e);
                if(res.size() >= k){
                    return res;
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    void solve(int idx, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
    if (idx >= nums.size()) {
        result.push_back(current);
        return;
    }
    current.push_back(nums[idx]);
    solve(idx + 1, nums, current, result);

    current.pop_back();
    solve(idx + 1, nums, current, result);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>current;
        vector<vector<int>>result;
        solve(0,nums,current,result);
        return result;
    }
};
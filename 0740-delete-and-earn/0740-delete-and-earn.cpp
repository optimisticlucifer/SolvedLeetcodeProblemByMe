class Solution {
public:
    unordered_map<int,int>m;
    int n;
    vector<int> dp;
    int solve(vector<int>& nums, int i, int last){
        if(nums[i]==last) return (m[nums[i]]*nums[i]);
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans = 0;
        
        // for getting indexes of nums[i]+1 and nums[i] 
        int ind = upper_bound(nums.begin(), nums.end(), nums[i]+1)-nums.begin();
        int ind2 = upper_bound(nums.begin(), nums.end(), nums[i])-nums.begin();
        
        int pick = (m[nums[i]]*nums[i]) + solve(nums, ind, last);
        int notpick = solve(nums, ind2, last);
        ans = max(pick, notpick);
        return dp[i] = ans;
    }
    
    int deleteAndEarn(vector<int>& nums) {
        // 2 2 3 3 3 4
        n = nums.size();
        dp.resize(n+1, -1);
        sort(nums.begin(),nums.end());
        for(auto i: nums) m[i]++;
        return solve(nums, 0, nums[n-1]);
    }
};
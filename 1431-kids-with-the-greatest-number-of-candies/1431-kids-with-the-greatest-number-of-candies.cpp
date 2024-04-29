class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        // int mx = *max_element(candies.begin(), candies.end());
        int mx = INT_MIN;
        for(auto it: candies){
            if(it>mx)
                mx = it;
        }
        int n = candies.size();
        vector<bool> ans(n, false);
        for(int i=0; i<n; i++){
            if(candies[i]+extraCandies>=mx)
                ans[i] = true;
        }
        return ans;
    }
};
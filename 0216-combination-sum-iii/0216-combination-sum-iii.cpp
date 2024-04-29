class Solution {
public:
    void f(int ind, int k, int n, vector<vector<int>>& vec, vector<int>& ds)
    {
        if(n==0 && ds.size()==k)
        {
            vec.push_back(ds);
            return ;
        }
        for(int i=ind; i<=n, i<=9; i++)
        {
            ds.push_back(i);
            f(i+1, k, n - i, vec, ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> vec;
        vector<int> ds;
        f(1, k, n, vec, ds);
        return vec;
    }
};
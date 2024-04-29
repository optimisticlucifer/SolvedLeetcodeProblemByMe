class Solution {
    vector<int> memo;
public:
    int dp(int index, int &size, vector<int>& flower) {
        if(index >= size) return 0;
        if(memo[index] != -1) return memo[index];
        int first = 0, second = 0;
        if(flower[index] == 0) {
            if(index != 0 and index != size - 1) {
                if(flower[index - 1] != 1 and flower[index + 1] != 1) {
                    first = 1 + dp(index + 2, size, flower);
                }
            }
            if(index == 0) {
                if(flower[index + 1] != 1)
                    first = 1 + dp(index + 2, size, flower);
            }
            if(index == size - 1) {
                if(flower[index - 1] != 1) {
                    first = 1 + dp(index + 2, size, flower);
                }
            }
        }
        second = dp(index + 1, size, flower);
        return memo[index] = max(first, second);
    }
    bool canPlaceFlowers(vector<int>& flower, int n) {
        if(n == 0) return true;
        int size = flower.size();
        if(size == 1) {
            if(flower[0] == 0) {
                if(n <= 1) return true;
            }
            return false;

        }
        memo.resize(size + 1, -1);
        if(dp(0, size, flower) >= n) {
            return true;
        }
        return false;
    }
};
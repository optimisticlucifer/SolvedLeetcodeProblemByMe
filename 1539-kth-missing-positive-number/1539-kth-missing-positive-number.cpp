class Solution {
public:
    int findKthPositive(vector<int>& vec, int k) {
        sort(vec.begin(), vec.end());

    // Step 2: Remove duplicates
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    int n = vec.size();
    int low = 0, high = n - 1;

    // Step 3: Apply binary search
    while (low <= high) {
        int mid = (low + high) / 2;
        int missing = vec[mid] - (mid + 1);
        if (missing < k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return k + high + 1;
        
    }
};
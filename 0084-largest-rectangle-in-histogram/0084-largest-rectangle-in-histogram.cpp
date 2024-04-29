class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size()==0) return 0;
        heights.push_back(0);// easy for removing if-branch
        const int n=heights.size();
        int maxA=0;
        vector<int> st={-1};
        for(int r=0; r<n; r++){
            while(st.size()>1 && heights[st.back()]>=heights[r]){
                const int m=st.back();
                st.pop_back();
                const int w=r-st.back()-1;
                const int area=heights[m]*w;
                maxA=max(maxA, area);
            }
            st.push_back(r);
        }
        return maxA;
    }
};
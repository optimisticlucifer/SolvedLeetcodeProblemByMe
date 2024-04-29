class Solution {
public:
    int trap(vector<int>& height) {
        int water_trapped = 0;
        int n = height.size();

        int max_right_index;
        int max_left_height = 0, max_right_height = 0;

        for(int i = 0; i < n; i++)
        {
            //find the max_right_height
            if(i == 0 || i > max_right_index)
            {
                max_right_height = 0;
                for (int j = i ; j < n; j++)
                {
                    if(height[j] >= max_right_height)
                    {
                        max_right_height = height[j];
                        max_right_index = j;
                    }
                }
            }
            //update the max_left_height
            if(height[i] >  max_left_height)
                max_left_height = height[i];
            //there is no water trapped at begin and end
            if(i != 0 && i != n - 1)
                water_trapped += min(max_right_height, max_left_height) - height[i];
        }
        return water_trapped;
        
    }
};
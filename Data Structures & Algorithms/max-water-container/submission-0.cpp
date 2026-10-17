class Solution {
public:
    int maxArea(vector<int>& heights) {
        int start = 0;
        int end = heights.size() - 1;
        int maximum = 0;

        while (start < end)
        {
            const bool start_smaller = heights[start] < heights[end];
            const int base = end - start;
            const int height = start_smaller ? heights[start] : heights[end];
            const int area = base * height;
            maximum = area > maximum ? area : maximum;
            
            if (start_smaller)
            {
                ++start;
            }
            else
            {
                --end;
            }
        }

        return maximum;
    }
};

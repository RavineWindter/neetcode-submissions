class Solution {
public:
    int trap(vector<int>& height) {
        int start = 0;
        int end = height.size() - 1;
        int max_start = 0;
        int max_end = 0;
        int area = 0;

        while (start < end)
        {
            max_start = height[start] > max_start ? height[start] : max_start;
            max_end = height[end] > max_end ? height[end] : max_end;

            if (max_start < max_end)
            {
                area += max_start - height[start];
                ++start;
            }
            else
            {
                area += max_end - height[end];
                --end;
            }
        }

        return area;
    }
};

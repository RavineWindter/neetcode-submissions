class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int index2 = numbers.size() - 1;
        int index1 = 0;

        while (index1 != index2)
        {
            const int sum = numbers[index1] + numbers[index2];
            if (sum == target)
            {
                return {index1 + 1, index2 + 1};
            }
            else if (sum < target)
            {
                ++index1;
            }
            else
            {
                --index2;
            }
        }

        return {};
    }
};

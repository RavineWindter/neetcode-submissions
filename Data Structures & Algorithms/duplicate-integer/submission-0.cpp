class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::set<int> values;
        for (const auto num : nums)
        {
            if (values.contains(num))
            {
                return true;
            }
            values.insert(num);
        }
        return false;
    }
};
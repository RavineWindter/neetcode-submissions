class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.length() - 1;

        while (start < end)
        {
            while (start < end && !std::isalnum(s[start]))
            {
                ++start;
            }
            while (start < end && !std::isalnum(s[end]))
            {
                --end;
            }
            if (start < end && std::toupper(s[start]) != std::toupper(s[end]))
            {
                return false;
            }
            ++start;
            --end;
        }
        return true;
    }
};

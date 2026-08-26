class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.length() - 1;

        while (start < end)
        {
            while (!std::isalnum(s[start]))
            {
                ++start;
            }
            while (!std::isalnum(s[end]))
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

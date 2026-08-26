char to_alphanumeric(char character)
{
    if ((character >= '0' && character <= '9') ||
        (character >= 'a' && character <= 'z'))
    {
        return character;
    }
    if (character >= 'A' && character <= 'Z')
    {
        constexpr char offset = -'A' + 'a';
        return character + offset;
    }
    return '#';
}

class Solution {
public:
    bool isPalindrome(string s) {
        std::size_t start = 0;
        std::size_t end = s.length() - 1;

        while (start < end)
        {
            char start_char = to_alphanumeric(s[start]);
            while (start < end-1 && start_char == '#')
            {
                ++start;
                start_char = to_alphanumeric(s[start]);
            }
            char end_char = to_alphanumeric(s[end]);
            while (start < end-1 && end_char == '#')
            {
                --end;
                end_char = to_alphanumeric(s[end]);
            }
            if (start_char != '#' && end_char != '#' && start_char != end_char)
            {
                return false;
            }
            ++start;
            --end;
        }
        return true;
    }
};

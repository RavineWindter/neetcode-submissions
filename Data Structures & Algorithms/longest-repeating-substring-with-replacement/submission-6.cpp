auto max_right(const string& s, int k) -> int
{
    const int N = s.size();
    int replacements = k;
    int start = 0;
    int end = 1;
    int longest = 0;

    while (end < N)
    {
        if (s[end] != s[start])
        {
            --replacements;
        }
        if (replacements < 0)
        {
            const char current = s[start];
            while ((start < end) && (s[start] == current))
            {
                ++start;
            }
            end = start + 1;
            replacements = k;
        }
        else
        {
            const int current_length = end - start + 1 + std::min(replacements, start);
            longest = std::max(longest, current_length);
            ++end;
        }
    }

    return longest;
}

auto max_left(const string& s, int k) -> int
{
    const int N = s.size();
    int replacements = k;
    int start = N - 1;
    int end = N - 2;
    int longest = 1;

    while (end >= 0)
    {
        if (s[end] != s[start])
        {
            --replacements;
        }
        if (replacements < 0)
        {
            const char current = s[start];
            while ((start > end) && (s[start] == current))
            {
                --start;
            }
            end = start - 1;
            replacements = k;
        }
        else
        {
            const int current_length = start - end + 1 + std::min(replacements, N - start - 1);
            longest = std::max(longest, current_length);
            --end;
        }
    }

    return longest;
}

class Solution {
public:
    int characterReplacement(string s, int k) {
        return std::max(max_right(s, k), max_left(s, k));
    }
};

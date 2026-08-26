class Solution {
public:
    bool isPalindrome(string s) {
        std::string clean;
        clean.reserve(s.size());

        for (const auto character : s)
        {
            if (std::isalnum(character))
            {
                clean.push_back(std::tolower(character));
            }
        }

        return std::equal(clean.begin(), clean.end(), clean.rbegin());
    }
};

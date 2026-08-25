class Solution {
public:

    string encode(vector<string>& strs) {
        std::size_t length = 0;
        for (const auto& str : strs)
        {
            length += str.size() + 1;
        }
        std::string result;
        result.reserve(length);
        for (const auto& str : strs)
        {
            result.push_back(static_cast<char>(std::ssize(str)));
            result.append(str);
        }
        return result;
    }

    vector<string> decode(string s) {
        std::vector<std::string> result;
        auto it = s.begin();
        while (it != s.end())
        {
            const std::size_t length = static_cast<std::size_t>(static_cast<std::uint8_t>(*it));
            std::string_view str(it+1, it+length+1);
            result.emplace_back(str);
            it += length + 1;
        }
        return result;
    }
};

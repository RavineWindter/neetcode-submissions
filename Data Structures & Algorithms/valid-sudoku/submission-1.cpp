#include <ranges>

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        constexpr int row_offset = 9*0;
        constexpr int collumn_offset = 9*1;
        constexpr int sub_box_offset = 9*2;
        
        std::vector<std::uint32_t> checks(3*9, 0);
        for (const int i : std::views::iota(0, std::ssize(board)))
        {
            for (const int j : std::views::iota(0, std::ssize(board[i])))
            {
                const auto value = board[i][j];
                if (value < '1' || value > '9')
                {
                    continue;
                }
                const std::uint32_t bit_mask = 1U << (board[i][j] - '0');
                const auto row = row_offset + i;
                const auto collumn = collumn_offset + j;
                const auto sub_box = sub_box_offset + (j/3)+(3*(i/3));

                if ((checks[row] & bit_mask) ||
                    (checks[collumn] & bit_mask) ||
                    (checks[sub_box] & bit_mask))
                {
                    return false;
                }

                checks[row] |= bit_mask;
                checks[collumn] |= bit_mask;
                checks[sub_box] |= bit_mask;
            }
        }

        return true;
    }
};

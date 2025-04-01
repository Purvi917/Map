class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows, cols, boxes;
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char num = board[i][j];

                if (num == '.') continue;  // Skip empty cells

                int boxIndex = (i / 3) * 3 + (j / 3); // Compute 3x3 sub-box index

                // Check for duplicates in row, column, or box
                if (rows[i].count(num) || cols[j].count(num) || boxes[boxIndex].count(num))
                    return false;

                // Insert the number into the respective row, column, and box
                rows[i].insert(num);
                cols[j].insert(num);
                boxes[boxIndex].insert(num);
            }
        }
        return true;
    }
};

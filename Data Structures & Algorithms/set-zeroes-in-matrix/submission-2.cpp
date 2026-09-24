class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool col0 = false; // Flag for the 0th column

        // Step 1: Mark rows and columns that need to be zeroed using first row/col
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) col0 = true;
            
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0; // Mark row i
                    matrix[0][j] = 0; // Mark col j
                }
            }
        }

        // Step 2: Traverse from bottom-right back to (1,1) using markers
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 1; --j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
            // Update 0th column based on col0 flag
            if (col0) {
                matrix[i][0] = 0;
            }
        }
    }
};
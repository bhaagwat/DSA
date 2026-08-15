class Solution {
public:

    void setZeroes(vector<vector<int>>& matrix) {

        int n = matrix.size(); // gives number of rows
        int m = matrix[0].size(); // gives number of columns

        bool firstColumnZero = false;

        // Mark rows and columns
        for (int i = 0; i < n; i++) {

            if (matrix[i][0] == 0)
                firstColumnZero = true;

            for (int j = 1; j < m; j++) {

                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set elements to zero
        for (int i = n - 1; i >= 0; i--) {

            for (int j = m - 1; j >= 1; j--) {

                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }

            if (firstColumnZero)
                matrix[i][0] = 0;
        }
    }
};
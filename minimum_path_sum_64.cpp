class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        if (!row)
        	return 0;
        int column = grid[0].size();
        if (!column)
        	return 0;
        int matrix[row][column];
        memset(matrix, 0, sizeof(matrix));
        matrix[0][0] = grid[0][0];
        int res = 0;
        for (int i = 1; i < column; i++)
        	matrix[0][i] = matrix[0][i-1] + grid[0][i];
        for (int i = 1; i < row; i++)
        	matrix[i][0] = matrix[i-1][0] + grid[i][0];
        for (int i = 1; i < row; i++)
        {
        	for (int j = 1; j < column; j++)
        	{
        		matrix[i][j] = std::min(matrix[i][j-1], matrix[i-1][j]) + grid[i][j];
        	}
        }
        return matrix[row-1][column-1];
    }
};
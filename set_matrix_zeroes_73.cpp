class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (!m)
        	return;
        int n = matrix[0].size();
        if (!n)
        	return;
        int row[m], column[n];
        memset(row, 0, sizeof(row));
        memset(column, 0, sizeof(column));

        for (int i = 0; i < m; i++)
        {
        	for (int j = 0; j < n; j++)
        	{
        		if (matrix[i][j] == 0)
        		{
        			if (!row[i])
        				row[i] = 1;
        			if (!column[j])
        				column[j] = 1;
        		}
        	}
        }

        for (int i = 0; i < m; i++)
        {
        	for (int j = 0; j < n; j++)
        	{
        		if (row[i] || column[j])
        			matrix[i][j] = 0;
        	}
        }
    }
};
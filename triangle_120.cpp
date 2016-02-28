class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        if (row == 0)
        	return 0;
        if (row == 1)
        	return triangle[0][0];
        vector<int> temp = triangle[row-1];
        for (int i = row-2; i >= 0; i--)
        {
        	for (int j = 0; j <= i; j++)
        	{
        		temp[j] = min(temp[j], temp[j+1]) + triangle[i][j];
        	}
        }
        return temp[0];
    }

    int minimumTotal_ii(vector<vector<int>>& triangle)
    {
    	int row = triangle.size();
        if (row == 0)
        	return 0;
        if (row == 1)
        	return triangle[0][0];
        for (int i = row-2; i >= 0; i--)
        {
        	for (int j = 0; j < i+1; j++)
        	{
        		triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
        	}
        }
        return triangle[0][0];
    }
};
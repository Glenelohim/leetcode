class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        if (row < 1)
        	return 0;
        int column = obstacleGrid[0].size();
        if (column < 1 || obstacleGrid[0][0])
        	return 0;
        int isCalculated[row+1][column+1] = {0};
        memset(isCalculated, 0, sizeof(isCalculated));
        for (int i = 1; i <= row; i++)
        {
        	for (int j = 1; j <= column; j++)
        	{
        		if (obstacleGrid[i-1][j-1])
        			isCalculated[i][j] = 0;
        		else
        			isCalculated[i][j] = isCalculated[i-1][j] + isCalculated[i][j-1];
        		isCalculated[1][1] = 1;
        	}
        }
        return isCalculated[row][column];
    }
};
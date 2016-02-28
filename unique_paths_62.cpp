class Solution {
public:
    int uniquePaths(int m, int n) {
    	if (m < 1 || n < 1)
    		return 0;
        int isCalculated[m+1][n+1] = {0};
        isCalculated[1][1] = 1;
        for (int i = 2; i <= n; i++)
        	isCalculated[1][i] = 1;
        for (int i = 2; i <= m; i++)
        	isCalculated[i][1] = 1;
        for (int i = 2; i <= m; i++)
        {
        	for (int j = 2; j <= n; j++)
        	{
        		if (isCalculated[i][j])
        			continue;
        		isCalculated[i][j] = isCalculated[i][j-1] + isCalculated[i-1][j];
        	}
        }
        return isCalculated[m][n];
    }
};
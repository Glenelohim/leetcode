class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > res;
        if (n == 0)
        	return res;
        vector<int> row_column;
        for (int i = 0; i < n; i++)
        	row_column.push_back(-1);
        for (int i = 0; i < n; i++)
        	res.push_back(row_column);
        long long nums = n * n;
        long long curs = 1;
        int direction = 0;
        int x = 0, y = 0;

        while (curs <= nums)
        {
        	switch(direction)
        	{
        		case 0://right
        		{
        			int j = y;
        			for (; j < n; j++)
        			{
        				if (res[x][j] != -1)
        					break;
        				res[x][j] = curs++;
        			}
        			y = j-1;
        			x++;
        			break;
        		}
        		case 1://down
        		{
        			int i = x;
        			for (; i < n; i++)
        			{
        				if (res[i][y] != -1)
        					break;
        				res[i][y] = curs++;
        			}
        			x = i-1;
        			y--;
        			break;
        		}
        		case 2://left
        		{
        			int j = y;
        			for (; j >= 0; j--)
        			{
        				if (res[x][j] != -1)
        					break;
        				res[x][j] = curs++;
        			}
        			y = j+1;
        			x--;
        			break;
        		}
        		case 3://up
        		{
        			int i = x;
        			for (; i >= 0; i--)
        			{
        				if (res[i][y] != -1)
        					break;
        				res[i][y] = curs++;
        			}
        			x = i+1;
        			y++;
        			break;
        		}
        	}
        	direction = (direction + 1) % 4;
        }
        return res;
    }
};
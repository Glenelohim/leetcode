class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int row = matrix.size();
        if (!row)
        	return res;
        if (row == 1)
        	return matrix[0];
        int column = matrix[0].size();
        int isVisited[row][column];
        memset(isVisited, 0, sizeof(isVisited));
        long long nums = row * column;
        long long curs = 0;
        int direction = 0;  //0 right 1 down 2 left 3 up
        int x = 0, y = 0;

        while (curs < nums)
        {
        	switch(direction)
        	{
        		case 0:
        		{
        			int i = y;
        			for (; i < column; i++)
        			{
        				if (isVisited[x][i])
        					break;
        				res.push_back(matrix[x][i]);
        				isVisited[x][i] = 1;
        				curs++;
        			}
        			y = i-1;
        			x++;
        			break;
        		}

        		case 1:
        		{
        			int i = x;
        			for (; i < row; i++)
        			{
        				if (isVisited[i][y])
        					break;
        				res.push_back(matrix[i][y]);
        				isVisited[i][y] = 1;
        				curs++;
        			}
        			x = i-1;
        			y--;
        			break;
        		}

        		case 2:
        		{
        			int i = y;
        			for (; i >= 0; i--)
        			{
        				if (isVisited[x][i])
        					break;
        				res.push_back(matrix[x][i]);
        				isVisited[x][i] = 1;
        				curs++;
        			}
        			y = i+1;
        			x--;
        			break;
        		}

        		case 3:
        		{
        			int i = x;
        			for (; i >= 0; i--)
        			{
        				if (isVisited[i][y])
        					break;
        				res.push_back(matrix[i][y]);
        				isVisited[i][y] = 1;
        				curs++;
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
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9, vector<int>(9, 0));
        vector<vector<int>> column(9, vector<int>(9, 0));
        vector<vector<int>> squal(9, vector<int>(9, 0));

        for (int i = 0; i < 9; i++)
        {
        	for (int j = 0; j < 9; j++)
        	{
        		if (board[i][j] == '.')
        			continue;
        		int index = board[i][j] - '0' - 1;

        		if (!row[i][index])
        			row[i][index] = 1;
        		else
        			return false;

        		if (!column[j][index])
        			column[j][index] = 1;
        		else
        			return false;

        		if (i <= 2)
        		{
        			if (j <= 2)
        			{
        				if (!squal[0][index])
        					squal[0][index] = 1;
        				else
        					return false;
        			}
        			else if (j <= 5)
        			{
        				if (!squal[1][index])
        					squal[1][index] = 1;
        				else
        					return false;
        			}
        			else
        			{
        				if (!squal[2][index])
        					squal[2][index] = 1;
        				else
        					return false;
        			}
        		}
        		else if (i <= 5)
        		{
        			if (j <= 2)
        			{
        				if (!squal[3][index])
        					squal[3][index] = 1;
        				else
        					return false;
        			}
        			else if (j <= 5)
        			{
        				if (!squal[4][index])
        					squal[4][index] = 1;
        				else
        					return false;
        			}
        			else
        			{
        				if (!squal[5][index])
        					squal[5][index] = 1;
        				else
        					return false;
        			}
        		}
        		else
        		{
        			if (j <= 2)
        			{
        				if (!squal[6][index])
        					squal[6][index] = 1;
        				else
        					return false;
        			}
        			else if (j <= 5)
        			{
        				if (!squal[7][index])
        					squal[7][index] = 1;
        				else
        					return false;
        			}
        			else
        			{
        				if (!squal[8][index])
        					squal[8][index] = 1;
        				else
        					return false;
        			}
        		}
        	}
        }
        return true;
    }
};

//other simple Solution
bool isValidSudoku(vector<vector<char> > &board) {
        // Note: The Solution object is instantiated only once.
	vector<vector<bool>> rows(9, vector<bool>(9,false));
	vector<vector<bool>> cols(9, vector<bool>(9,false));
	vector<vector<bool>> blocks(9, vector<bool>(9,false));

	for(int i = 0; i < 9; i++)
		for(int j = 0; j < 9; j++)
		{
			if(board[i][j] == '.')continue;
			int num = board[i][j] - '1';
			if(rows[i][num] || cols[j][num] || blocks[i - i%3 + j/3][num])
				return false;
			rows[i][num] = cols[j][num] = blocks[i - i%3 + j/3][num] = true;
		}
	return true;
}
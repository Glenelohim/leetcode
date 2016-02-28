class Solution {
public:
	bool search(vector<vector<char>>& board, string word, vector<vector<int>>& isVisited, int x, int y)
	{
		if ((x >= board.size()) || (y >= board[0].size()) || (x < 0) || (y < 0))
			return false;
		if (isVisited[x][y] || (board[x][y] != word[0]))
			return false;
		if (word.length() == 1)
			return true;
		word = word.substr(1);
		isVisited[x][y] = 1;
		bool res = search(board, word, isVisited, x-1, y) || search(board, word, isVisited, x+1, y) \
			|| search(board, word, isVisited, x, y-1) || search(board, word, isVisited, x, y+1);
		isVisited[x][y] = 0;
		return res;
	}


    bool exist(vector<vector<char>>& board, string word) {
        int word_length = word.length();
        int board_row = board.size();
        if (!word_length || !board_row)
        	return false;
        int board_column = board[0].size();
        if (!board_column)
        	return false;
        vector<vector<int>> isVisited(board_row, vector<int>(board_column, 0));

        for (int i = 0; i < board_row; i++)
        {
        	for (int j = 0; j < board_column; j++)
        	{
        		if (board[i][j] == word[0])
        		{
        			if (search(board, word, isVisited, i, j))
        				return true;
        		}
        	}
        }
        return false;
    }
};
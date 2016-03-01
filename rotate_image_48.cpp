class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (!n)
        	return;
        vector<vector<int> > temp = matrix;
        //new(i, j)=old(n-1-j, i);
        for (int i = 0; i < n; i++)
        {
        	for (int j = 0; j < n; j++)
        		matrix[i][j] = temp[n-1-j][i];
        }
    }
};
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if (numRows == 0)
        	return result;
        result.push_back({1});
        if (numRows == 1)
        	return result;
        result.push_back({1,1});
        if (numRows == 2)
        	return result;

        for (int i = 1; i < numRows - 1; i++)
        {
        	vector<int> temp;
        	temp.push_back(1);
        	for (int j = 0; j < result[i].size() - 1; j++)
        		temp.push_back(result[i][j] + result[i][j+1]);
        	temp.push_back(1);
        	result.push_back(temp);
        }
        return result;
    }
};
class Solution {
public:
    vector<int> getRow(int rowIndex) {  // O(k)space
        vector<int> result;
        result.push_back(1); //[1]
        if (rowIndex == 0)
        	return result;
        result.push_back(1); //[1,1]
        if (rowIndex == 1)
        	return result;
        for (int i = 2; i <= rowIndex; i++)
        {
        	for (int j = 0; j < result.size() - 1; j++)
        	{
        		result[j] += result[j + 1];
        	}
        	result.insert(result.begin(), 1);
        }
        return result;
    }
};
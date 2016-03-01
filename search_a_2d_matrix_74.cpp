class Solution {
public:
	bool binarySearch(vector<int>& vec, int target, int low, int high)
	{
		if (low > high)
			return false;
		int mid = (low + high) / 2;
		if (vec[mid] == target)
			return true;
		if (target > vec[mid])
			return binarySearch(vec, target, mid+1, high);
		return binarySearch(vec, target, low, mid-1);
	}

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if (!row)
        	return false;
        int column = matrix[0].size();
        if (!column)
        	return false;
        bool res = false;
        for (int i = 0; i < row; i++)
        {
        	if (target == matrix[i][0] || target == matrix[i][column-1])
        		return true;
        	if (target > matrix[i][0] && target < matrix[i][column-1])
        	{
        		res = binarySearch(matrix[i], target, 0, column-1);
        		if (res)
        			return true;
        	}
        	else if (target < matrix[i][0])
        		break;
        }
        return res;
    }
};
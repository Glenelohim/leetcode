class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if (1 == size || !size)
        	return 0;

        int min = INT_MAX, max = INT_MIN;
        for (int i = 0; i < size; i++)
        {
        	if (min > prices[i])
        	{
        		min = prices[i];
        	}
        	if (max < prices[i] - min)
        	{
        		max = prices[i] - min;
        	}
        }
        return max;
    }
};
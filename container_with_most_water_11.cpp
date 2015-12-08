class Solution {
public:
	//TLE..
    int maxArea(vector<int>& height) {
    	int len = height.size();
    	if (len <= 1)	return 0;
        
        int max = 0;
        for (int i = 0; i < len; i++)
        {
        	for (int j = 0; j < len; j++)
        	{
        		if (j == i || height[j] > height[i]) continue;
        		int area = height[j] * abs(j - i);
        		if (area > max) max = area;
        	}
        }
        return max;
    }

    //O(n)
    int maxArea(vector<int>& height) {
    	int len = height.size();
    	if (len <= 1)	return 0;
        
        int max = 0, temp = 0;
        int i = 0;
        len--;
        while (i != len)
        {
        	if (height[i] > height[len])
        	{
        		temp = height[len] * (len - i);
        		len--;
        	}
        	else
        	{
        		temp = height[i] * (len - i);
        		i++;
        	}
        	if (temp > max)
        		max = temp;
        }

        return max;
    }
};
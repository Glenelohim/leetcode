class Solution {
public:
	int int2BitNum(int n)
	{
		int res = 0;
		while (n / 10)
		{
			int temp = n % 10;
			res += temp * temp;
			n /= 10;
		}
		res += n * n;
		return res;
	}

    bool isHappy(int n) {
    	vector<int> resultItem;
    	int r1 = int2BitNum(n);
    	if (r1 == 1)
    		return true;
    	resultItem.push_back(r1);
    	n = r1;
    	while (1)
    	{
    		int temp = int2BitNum(n);
    		if (temp == 1)
    			return true;
    		vector<int>::iterator it = find(resultItem.begin(), resultItem.end(), temp);
    		if (it != resultItem.end())
    			return false;
    		resultItem.push_back(temp);
    		n = temp;
    	}
    }

    //awesome recursive solution
    bool isHappy(int n)
    {
    	int nextN = int2BitNum(n);
    	if (nextN == 1)
    		return true;
    	else if (nextN <= 9)
    		return false;
    	return isHappy(nextN);
    }
};
class Solution {
public:
    string addBinary(string a, string b) {
        int a_len = a.length();
        int b_len = b.length();
        if (!a_len && !b_len)
        	return "0";
        if (a_len < b_len)
        	return addBinary(b, a);
        int i = a_len - 1;
        int j = b_len - 1;
        int flag = 0;
        while (i >= 0)
        {
        	if (j >= 0)
        	{
        		int temp = (a[i] - '0') + (b[j] - '0') + flag;
        		if (temp >= 2)
        			flag = 1;
        		else
        			flag = 0;
        		a[i] = (temp % 2) + '0';
        	}
        	else
        	{
        		int temp = (a[i] - '0') + flag;
        		if (temp >= 2)
        			flag = 1;
        		else
        			flag = 0;
        		a[i] = (temp % 2) + '0';
        	}

        	i --;
        	j --;
        }
        if (flag)
        	a.insert(a.begin(), '1');
        return a;
    }
};
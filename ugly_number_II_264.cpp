class Solution {
public:
	//solve as hinted...
    int nthUglyNumber(int n) {
        queue<int> l1, l2, l3;
        l1.push(1);
        l2.push(2);
        l3.push(3);

        int res = 0;
        for (int i = 0; i < n; i++)
        {
        	res = min(min(l1.front(), l2.front()), l3.front());
        	if (temp == l1.front())
        		l1.pop();
        	if (temp == l2.front())
        		l2.pop();
        	if (temp == l3.front())
        		l3.pop();

        	l1.push(res*2);
        	l2.push(res*3);
        	l3.push(res*5);
        }
        return res;
    }
};
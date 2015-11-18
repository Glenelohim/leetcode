class Solution {
public:
    string convertToTitle(int n) {
    	string res;
    	if (n < 27)
    	{
    		res += 'A' + n - 1;
    		return res;
    	}
        std::stack<int> container;
        int pfix = n / 26;
        int afix = n % 26;
        container.push(afix);
        if (afix == 0)  // exact division, the pfix should minus 1
            pfix--;
        while (pfix > 26)
        {
        	int temp = pfix / 26;
        	afix = pfix % 26;
        	container.push(afix);
        	pfix = temp;
        	if (afix == 0)
        	    pfix--;
        }
        // pfix: 1-26, never 0
        res += 'A' + pfix - 1;
        while (!container.empty())
        {
        	if (container.top() == 0)
        		res += 'Z';
        	else
        		res += 'A' + container.top() - 1;
        	container.pop();
        }
        return res;
        
    }
};

//another awesome solution 
class Solution {
public:
    string convertToTitle(int n) {
        string ret = "";
        while (n != 0){
            ret = char((n - 1) % 26 + 'A') + ret;
            n = (n - 1) / 26;
        }
        return ret;
    }
};
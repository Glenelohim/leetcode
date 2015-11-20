class Solution {
public:
	/*
	//a TLE solution
	bool isPrime(int n)  //n > 2
	{
		for (int i = 2; i <= sqrt(n); i++)
			if (!(n % i))
				return false;
		return true;
	}
    int countPrimes(int n) {
        if (n <= 2)
        	return 0;
        int res = 1;
        for (int i = 3; i < n; i++)
        	if (isPrime(i))
        		res++;

        return res;
    }
    
    //fuck another TLE solution 
    int countPrimes(int n) {
        if (n < 3)
        	return 0;
        int notPrime[n] = {0};
        //all even numbers are not prime
        for (int i = 4; i < n; i += 2)
        	notPrime[i] = 1;
        //judge the odd number
        for (int j = 3; j <= sqrt(n); j += 2)
        {
        	if (!notPrime[j])
        		//odd*odd=odd,odd*even=even,even*even=even
        		//so, k=j*j,(j+2)*j,(j+4)*j...and all k are not prime
        		for (int k = j * j; k < n; k += 2 * j) 
        			notPrime[k] = 1;
        }

        int res = 0;
        for (int count = 2; count < n; count++)
        	if (!notPrime[count])
        		res++;

        return res;
    }

    */
};

class Solution {
public:
	//304ms
    int countPrimes(int n) {
    	if (n < 3)
    		return 0;
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i <= sqrt(n); i++)
        	if (isPrime[i])
        		for (int j = i * i; j < n; j += i)
        			isPrime[j] = false;
        int res = 0;
        for (int k = 2; k < n; k++)
        	if (isPrime[k])
        		res++;

        return res;
    }
};

class Solution {
public:
	//12ms but when the n is large enough, 
	//the runtime will be N/A
	//I dont know why this can be ac...
    int countPrimes(int n) {
        if(--n < 2) return 0;
        int m = (n + 1)/2, count = m, k, u = (sqrt(n) - 1)/2;
        bool notPrime[m] = {0};
    
        for(int i = 1; i <= u;i++)
            if(!notPrime[i])
              for(k = (i+ 1)*2*i; k < m;k += i*2 + 1)
                  if (!notPrime[k])
                  {
                      notPrime[k] = true;
                      count--;
                  }
        return count;
    }
};
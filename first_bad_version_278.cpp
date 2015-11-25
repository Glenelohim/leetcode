// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (n <= 1)
        	return 1;
        long i = 1;
        long j = n;
        while ((j - i) > 1)
        {
        	long temp = (i + j) / 2;  //overflow!!!
        	if (isBadVersion(temp))
        		j = temp;
        	else
        		i = temp;
        }
        return isBadVersion(i) ? i : j;
    }
};
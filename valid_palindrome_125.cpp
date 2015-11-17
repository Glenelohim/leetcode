class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.length();
        if (len == 0 || len == 1)
        	return true;

        for (int i = 0, j = len - 1; i <= j;)
        {
        	// first left alphanumeric character
        	if (s[i] < '0' || (s[i] > '9' && s[i] < 'A') || s[i] > 'z' || (s[i] > 'Z' && s[i] < 'a'))
        	{
        		i++;
        		continue;
        	}
        	// first right alphanumeric character
        	if (s[j] < '0' || (s[j] > '9' && s[j] < 'A') || s[j] > 'z' || (s[j] > 'Z' && s[j] < 'a'))
        	{
        		j--;
        		continue;
        	}
        	//0-9
        	if (s[i] >= '0' && s[i] <= '9' && s[i] == s[j])
        	{
        		i++;
        		j--;
        	}
        	else if (s[i] == s[j] || (s[i] - s[j]) == 32 || (s[i] - s[j]) == -32)
        	{
        		i++;
        		j--;
        	}
        	else
        		return false;
        }
        return true;
    }
};

//another awesome solution using system function
//however, the runtime is same with before, 16ms
bool isPalindrome(string s) {
    int l=0, r=s.size()-1;
    while (l<r) {
        while (l<r && !isalnum(s[l]))
            l++;
        while (l<r && !isalnum(s[r]))
            r--;
        if (tolower(s[l])!=tolower(s[r]))
            return false;
        l++;
        r--;
    }
    return true;
}
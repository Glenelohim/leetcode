class Solution {
public:
    string getHint(string secret, string guess) {
        int len = secret.length();
        if (!len) return "0A0B";

        int arra[10] = {0};
        for (int i = 0; i < len; i++)
        	arra[secret[i]-'0']++;

        int countA = 0, countB = 0;
        for (int i = 0; i < len; i++) //count A
        	if (secret[i] == guess[i])
        	{
        		countA++;
        		arra[guess[i]-'0']--;
        	}

        for (int i = 0; i < len; i++)  //count B
        {
        	if (secret[i] == guess[i])
        		continue;
        	if (arra[guess[i]-'0'])
        	{
        		countB++;
        		arra[guess[i]-'0']--;
        	}
        }
        return to_string(countA)+"A"+to_string(countB)+"B";
    }
};
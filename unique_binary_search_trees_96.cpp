class Solution {
public:
	//main thought: dp[1...3] == dp[2...4] == dp[i...i+2]...
    int numTrees(int n) {
        if (n == 0 || n == 1)
        	return 1;
        int dp[n+1];
        memset(dp, 0, sizeof(dp));
        dp[0] = dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
        	for (int j = 1; j <= i; j++)
        	{
        		dp[i] += (dp[j-1] * dp[i-j]);
        	}
        }
        return dp[n];
    }
};
/*
动态规划4步骤：
	1. 将原来的问题拆为子问题
	2. 确认状态
	3. 确认边界状态
	4. 状态转义方程
*/

// 爬楼梯
int climbStairs(int n) {
	if(n==1) {
		return 1;
	}
	int dp[] = new int[n+1];
	dp[1] = 1;
	dp[2] = 2;
	for(int i=3; i<=n; i++)
		dp[i] = dp[i-1] + dp[i-2];
	return dp[n];
}

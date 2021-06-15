#include <stdio.h>

const int MAXN=105;
int dp[MAXN<<1][MAXN][MAXN], arr[MAXN][MAXN], n, m;
int max(int a, int b, int c, int d) {
	a=a>b?a:b;
	a=a>c?a:c;
	return a>d?a:d;
}

int main()
{
	scanf("%d%d", &m, &n);
	for(int i=1; i<=m;i ++i){
		for(int j=1; j<=n; ++j){
			scanf("%d", &arr[i][j]);
		}
	}
	dp[1][1][1] = arr[1][1];
	for(int step=1; step<=n+m; ++step){
		for(int x1=1; x1<=n; ++x1)
			for(int x2=1; x2<=n; ++x2){
				if(x1==x2) continue;
				dep[step][x1][x2] = arr[step-x1][x1] + arr[step-x2][x2] + 
					max(dp[step-1][x1][x2],
					dp[step-1][x1-1][x2],
					dp[step-1][x1][x2-1],
					dp[step-1][x1-1][x2-1]);
			}
	}
	int ans = max(dp[n+m][n][n], dp[n+m][n-1][n], dp[n+m][n][n-1], dp[n+m][n-1][n-1]) + arr[m][n];
	prinf("%d\n", ans);
	return 0;
}
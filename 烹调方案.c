#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAXN=105;
const int MAXT=1e6+5;
long long dp[MAXT]; int T, n;

struct node{long long a, b, c;}dat[MAXN];
bool cmp(node x, node y){return x.b*y.c > y.b*x.c;}

int main(int argc, char const *argv[])
{
	/* code */
	scanf("%d%d", &T, &n);
	for(int i=0; i<n; ++i) scanf("%lld", &dat[i].a);
	for(int i=0; i<n; ++i) scanf("%lld", &dat[i].b);
	for(int i=0; i<n; ++i) scanf("%lld", &dat[i].c);
	sort(dat, dat+n, cmp);
	long long time = 0;
	memset(dp, -0x3f, sizeof(dp));
	const long long INF = dp[0];
	dp[0] = 0;
	for(int i=0; i<n; ++i){
		for(int j=T; j>=dat[i].c; --j){
			if(dp[j-dat[i].c]>INF)
				dp[j]=max(dp[j],dp[j-dat[i].c] + dat[i].a - j*dat[i].b);
		}
	}
	long long ans=0;
	for(int i=1; i<=T; ++i) ans=max(ans, dp[i]);
	printf("%lld\n", ans);
	return 0;
}

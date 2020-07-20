/*input
6
7 6 8 6 1 1
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 402;
const long long int inf = 1e18;
long long int dp[N][N],sum[N][N];

int main()
{
	int n;cin>>n;
	vector<long long int> a(n+1,0);
	for(int i=1;i<=n;i++) cin>>a[i];

	vector<long long int> pf(n+1);
	for(int i=1;i<=n;i++) pf[i]=pf[i-1]+a[i];

	for(int i=1;i<=n;i++) for(int j=i;j<=n;j++) sum[i][j]=pf[j]-pf[i-1];
	for(int len=1;len<=n;len++)
	{
		for(int i=1;i<=n-len+1;i++)
		{
			int j = i+len-1;
			if(len==1) dp[i][j]=0;
			else
			{
				dp[i][j]=inf;
				for(int k=i;k<j;k++) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j] + sum[i][k]+sum[k+1][j]);
			}

			// cout<<i<<" "<<j<<" "<<dp[i][j]<<"\n";
		}
	}

	cout<<dp[1][n]<<"\n";

	return 0;
}

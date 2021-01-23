/*input
6
2 4 4 9 4 9

*/
#include<bits/stdc++.h>
using namespace std;

const int K = 20,N = 10005;

int dp[N][K];

int query(int L,int R)
{
	int k = log2(R-L+1);
	return min(dp[L][k],dp[R-(1<<k)+1][k]);
}

int main()
{
	int n;cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];

	for(int i=0;i<n;i++) dp[i][0] = a[i];
	for(int k=1;k<K;k++)
	{
		for(int i=0; (i+(1<<k))<=n; i++)
		{
			dp[i][k] = min(dp[i][k-1],dp[i+(1<<(k-1))][k-1]);
			// cout<<i<<" "<<k<<" "<<dp[i][k]<<"\n";
		} 
	} 

	long long int ans = 0;
	for(int i=0;i<n;i++) for(int j=i;j<n;j++) ans=max(ans,(long long int)query(i,j)*(long long int)(j-i+1));
	cout<<ans<<"\n";
	return 0;
}

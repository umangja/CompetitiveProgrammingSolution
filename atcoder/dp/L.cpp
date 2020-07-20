/*input
10
1000000000 1 1000000000 1 1000000000 1 1000000000 1 1000000000 1
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	const int mod = 1e9+7;
	int n;cin>>n;
 
	vector<long long int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
 
	vector<long long int> pf(n);
	pf[0]=a[0];
	for(int i=1;i<n;i++) pf[i]=pf[i-1]+a[i];
	
	vector<vector<long long int>> dp(n,vector<long long int> (n,0));
	vector<vector<long long int>> sum(n,vector<long long int> (n,0));
 
	for(int i=0;i<n;i++) for(int j=i;j<n;j++) sum[i][j] = pf[j]-(i-1>=0?pf[i-1]:0);
	for(int len=1;len<=n;len++)
	{
		for(int i=0;i<=n-len;i++)
		{
			int j = i+len-1;
			if(len==1) dp[i][j] = a[i];
			else dp[i][j] = max( sum[i][j]-dp[i+1][j],sum[i][j]-dp[i][j-1]);
		}
	}
 
	cout<<2*dp[0][n-1]-sum[0][n-1];
 
	return 0;
}

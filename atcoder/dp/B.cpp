/*input
5 3
10 30 40 50 20
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;cin>>n>>k;
	vector<int> h(n+1);
	for(int i=1;i<=n;i++) cin>>h[i];
	vector<int> dp(n+1,1e9);
	dp[1]=0;
	for(int i=2;i<=n;i++) for(int j=1;j<=k;j++) if(i-j>=1) dp[i]=min(dp[i],dp[i-j]+abs(h[i]-h[i-j]));
	// for(int i=1;i<=n;i++) cout<<dp[i]<<" ";
	cout<<dp[n]<<"\n";
	return 0;
}

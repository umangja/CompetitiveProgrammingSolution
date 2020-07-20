/*input
5
0.42 0.01 0.42 0.99 0.42
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;cin>>n;
	vector<double> prob(n+1);
	for(int i=1;i<=n;i++) cin>>prob[i];

	vector<vector<double>> dp(n+1,vector<double> (n+1,(double)0));
	dp[0][0]=1;
	for(int i=1;i<=n;i++) for(int j=0;j<=i;j++) dp[i][j] = dp[i-1][j]*(1-prob[i])+(j-1>=0?dp[i-1][j-1]*prob[i]:0);
	double ans = 0;
	for(int j=n/2+1;j<=n;j++) ans+=dp[n][j];
	cout<<setprecision(20)<<ans<<"\n";
	return 0;
}

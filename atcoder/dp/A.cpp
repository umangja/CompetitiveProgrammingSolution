/*input
6
30 10 60 10 60 50
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;cin>>n;
	vector<int> h(n+1);
	for(int i=1;i<=n;i++) cin>>h[i];

	vector<int> dp(n+1,0);
	for(int i=2;i<=n;i++)
	{
		if(i==2) dp[i]=abs(h[2]-h[1]);
		else dp[i] = min(dp[i-1]+abs(h[i]-h[i-1]),dp[i-2]+abs(h[i]-h[i-2]));
	}
	cout<<dp[n]<<"\n";
	return 0;
}

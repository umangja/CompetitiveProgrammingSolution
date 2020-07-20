/*input
abracadabra
avadakedavra
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s,r;cin>>s>>r;
	int n = (int)s.size(),m = (int)r.size();

	vector<vector<int>> dp(n+1,vector<int> (m+1,0));
	dp[0][0]=0;

	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(s[i-1]==r[j-1]) dp[i][j]=dp[i-1][j-1]+1; else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

	string ans="";
	int i=n,j=m;
	while(i>0 && j>0 )
	{
		if(s[i-1]==r[j-1])
		{
			ans+=s[i-1];
			i--;
			j--;
		}
		else if(dp[i][j]==dp[i-1][j]) i--;
		else j--;
	}
	reverse(ans.begin(), ans.end());
	cout<<ans<<"\n";
	return 0;
}

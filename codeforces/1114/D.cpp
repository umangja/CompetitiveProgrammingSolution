/*input
4
5 2 2 1
*/


//assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
int dp[5000][5000][2];

int solve()
{
	// cout<<"YES";
	int n;cin>>n;
	std::vector<int> a(n);
	rep(i,0,n)
		cin>>a[i];

	// cout<<dp[1][2][0];

	rep(l,1,n+1)
	{
		rep(i,0,n-l+1)
		{
			int j = i+l-1;
			rep(c,0,2)
			{
				int col;
				if(c)
					col = a[j];
				else
					col = a[i];

				if(i==j)
					dp[i][j][c]=0;
				else if(c)
					dp[i][j][c] = min(dp[i][j-1][0]+int(a[i]!=col),dp[i][j-1][1]+int(a[j-1]!=col));
				else if(!c)
					dp[i][j][c] = min(dp[i+1][j][0]+int(a[i+1]!=col),dp[i+1][j][1]+int(a[j]!=col));
					
				// cout<<i<<" "<<j<<" "<<c<<" "<<dp[i][j][c]<<"\n";
			}
		}
	}

	cout<<min(dp[0][n-1][0],dp[0][n-1][1]);
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t=1;
	//cin>>t;
	while(t--)
		solve();
}
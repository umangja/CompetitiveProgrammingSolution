/*input
10 1 1
11 7 20 15 19 14 2 4 13 14
8
11

72+25+
*/
#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
long long int dp[202][202][202];
int main()
{
	int T=1;
	while(T--)
	{
		int R,B,G;cin>>R>>B>>G;
		vector< vector<long long int> > a(3,vector<long long int> ());
		a[0].resize(R);
		for(int i=0;i<R;i++)
		{
			long long int x;cin>>x;
			a[0][i]=x;
		}

		a[1].resize(B);
		for(int i=0;i<B;i++)
		{
			long long int x;cin>>x;
			a[1][i]=x;
		}

		a[2].resize(G);
		for(int i=0;i<G;i++)
		{
			long long int x;cin>>x;
			a[2][i]=x;
		}

		for(int i=0;i<3;i++) sort(a[i].begin(), a[i].end());

		for(int i=0;i<=R;i++)
		{
			for(int j=0;j<=B;j++)
			{
				for(int k=0;k<=G;k++)
				{
					dp[i][j][k] = max({
						(i-1>=0 && j-1>=0?dp[i-1][j-1][k]+a[0][i-1]*a[1][j-1]:0),
						(i-1>=0 && k-1>=0?dp[i-1][j][k-1]+a[0][i-1]*a[2][k-1]:0),
						(j-1>=0 && k-1>=0?dp[i][j-1][k-1]+a[1][j-1]*a[2][k-1]:0)});
					// cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<"\n";
				}
			}
		} 

		cout<<dp[R][B][G]<<"\n";
	}
	return 0;
}

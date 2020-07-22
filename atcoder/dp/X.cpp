/*input
3
2 2 20
2 1 30
3 1 40
*/
#include<bits/stdc++.h>
using namespace std;
struct block
{
	int W,S;
	long int Val;
	block(int W=0,int S=0,long int V=0) : W(W),S(S),Val(V)  {};

	bool operator< (const block &oth)
	{
		return W+S<oth.W+oth.S;
	}

};

const int WMax = 2e4+5,NMax = 1e3+5;
long int dp[NMax][WMax];

int main()
{
	int n;cin>>n;
	vector<block> blocks(n);
	for(int i=0;i<n;i++) cin>>blocks[i].W>>blocks[i].S>>blocks[i].Val;
	sort(blocks.begin(), blocks.end());

	memset(dp,0l,sizeof dp);
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<WMax;j++)
		{
			if(i!=0)
			{
				dp[i][j] = dp[i-1][j];
				if(j>=blocks[i].W && j-blocks[i].W<=blocks[i].S) dp[i][j]=max(dp[i][j],dp[i-1][j-blocks[i].W] + blocks[i].Val);
			} 
			else if(j==blocks[i].W) dp[i][j]=max(dp[i][j],blocks[i].Val);
		}
	}
	cout<<"\n";
	long int ans=0;
	for(int j=0;j<WMax;j++) ans=max(ans,dp[n-1][j]);
	cout<<ans<<"\n";
	return 0;
}

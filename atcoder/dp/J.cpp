/*input
2
0 0 2 3 3 2 3 2 1 3
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 305;
double dp[N][N][N];
int main()
{
	int n;cin>>n;
	vector<int> cnt(4,0);
	for(int i=1;i<=n;i++) 
	{
		int x;cin>>x;
		cnt[x]++;
	}

	dp[0][0][0] = 0;
	for(int c=0;c<=n;c++) 
	{
		for(int b=0;b<=n;b++)
		{
			for(int a=0;a<=n;a++)
			{
				dp[a][b][c]=0;
				if(a+b+c==0) continue;
				if(a>0) dp[a][b][c] += ((double)a)*(dp[a-1][b][c]);
				if(b>0) dp[a][b][c] += ((double)b)*(dp[a+1][b-1][c]);
				if(c>0) dp[a][b][c] += ((double)c)*(dp[a][b+1][c-1]);
				dp[a][b][c]+=(double)n;
				dp[a][b][c]/=(double)(a+b+c);
			}
		}
	}
	// cout<<cnt[1]<<" "<<cnt[2]<<" "<<cnt[3]<<"\n";
	cout<<setprecision(15)<<dp[cnt[1]][cnt[2]][cnt[3]]<<"\n";

	return 0;
}

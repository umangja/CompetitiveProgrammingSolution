/*input
5 5
1 1 1 1 1
2 2 1 2 2



*/
#include<bits/stdc++.h>
using namespace std;
const int NMax = 1005;
int dp[NMax][NMax];
#define ll int
#define pb push_back
int main()
{
	int N,M;cin>>N>>M;
	vector<long long int> A(N),B(M);
	for(int i=0;i<N;i++) cin>>A[i];
	for(int i=0;i<M;i++) cin>>B[i];

	N++,M++;
	A.push_back(1e9+11);
	B.push_back(1e9+11);

	for(int i=1;i<=N;i++) dp[i][0] = i;
	for(int j=1;j<=M;j++) dp[0][j] = j;

	dp[0][0]=0;

	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			if(A[i-1]==B[j-1])  dp[i][j] = dp[i-1][j-1];
			else
			{
				dp[i][j] = 1e5;
				dp[i][j] = min({dp[i-1][j-1]+1,dp[i-1][j]+1,dp[i][j-1]+1});
			}

			// cout<<i<<" "<<j<<" "<<dp[i][j]<<"\n";  
		}
	}
	cout<<dp[N][M]<<"\n";
	return 0;
}

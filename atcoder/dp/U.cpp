/*input
16
0 5 -4 -5 -8 -4 7 2 -4 0 7 0 2 -3 7 7
5 0 8 -9 3 5 2 -7 2 -7 0 -1 -4 1 -1 9
-4 8 0 -9 8 9 3 1 4 9 6 6 -6 1 8 9
-5 -9 -9 0 -7 6 4 -1 9 -3 -5 0 1 2 -4 1
-8 3 8 -7 0 -5 -9 9 1 -9 -6 -3 -8 3 4 3
-4 5 9 6 -5 0 -6 1 -2 2 0 -5 -2 3 1 2
7 2 3 4 -9 -6 0 -2 -2 -9 -3 9 -2 9 2 -5
2 -7 1 -1 9 1 -2 0 -6 0 -6 6 4 -1 -7 8
-4 2 4 9 1 -2 -2 -6 0 8 -6 -2 -4 8 7 7
0 -7 9 -3 -9 2 -9 0 8 0 0 1 -3 3 -6 -6
7 0 6 -5 -6 0 -3 -6 -6 0 0 5 7 -1 -5 3
0 -1 6 0 -3 -5 9 6 -2 1 5 0 -2 7 -8 0
2 -4 -6 1 -8 -2 -2 4 -4 -3 7 -2 0 -9 7 1
-3 1 1 2 3 3 9 -1 8 3 -1 7 -9 0 -6 -8
7 -1 8 -4 4 1 2 -7 7 -6 -5 -8 7 -6 0 -9
7 9 9 1 3 2 -5 8 7 -6 3 0 1 -8 -9 0
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 17;
int g[N][N];
long int prof[1<<N];
long int dp[1<<N];

int bit(int mask,int b)
{
	return (mask>>b)&1;
}

int main()
{
	int n;cin>>n;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>g[i][j];
	
	int MASK = (1<<n);
	for(int mask=0;mask<MASK;mask++) for(int a=0;a<n;a++) for(int b=a+1;b<n;b++) if(bit(mask,a) && bit(mask,b) ) prof[mask]+=(long int)g[a][b];

	// for(int mask=0;mask<MASK;mask++) cout<<prof[mask]<<"\n";

	dp[0]=prof[0];
	for(int curMask=1;curMask<MASK;curMask++)
	{
		dp[curMask]=prof[curMask];
		for(int mask = (curMask-1)&curMask;mask>0;mask=(mask-1)&curMask)
		{
			assert(mask<curMask);
			dp[curMask]=max(dp[curMask],dp[mask]+prof[curMask^mask]);
			// cout<<mask<<"\n";
		}

		// cout<<curMask<<" "<<dp[curMask]<<"\n";

	}

	cout<<dp[MASK-1]<<"\n";




	return 0;
}

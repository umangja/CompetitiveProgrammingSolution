/*input
2 7
2 3
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N,K;cin>>N>>K;
	vector<int> a(N);
	for(int i=0;i<N;i++) cin>>a[i];
	vector<int> dp(K+1);
	dp[0]=0;
	for(int i=1;i<=K;i++)
	{
		int ls = 0;
		for(int j=0;j<N;j++)
		{
			if(i-a[j]>=0 && dp[i-a[j]]==0) 
			{
				ls=1;
				break;
			} 
		} 
		dp[i]=ls;
	}

	cout<<(dp[K]?"First":"Second");
	return 0;
}

/*input
4 100000
100000 100000 100000 100000
*/
#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int main()
{
	int N,K;cin>>N>>K;
	vector<int> a(N+1);
	for(int i=1;i<=N;i++) cin>>a[i];

	vector<int> dp2(K+1,0);
	vector<int> pf(K+1,1);

	for(int i=1;i<=N;i++)
	{
		for(int j=0;j<=K;j++)
		{
			// dp2[j] = dp1[j-a[i]] .... dp1[j];
			dp2[j] = pf[j] - (j-a[i]-1>=0?pf[j-a[i]-1]:0);
			dp2[j]%=mod;
			if(dp2[j]<0) dp2[j]+=mod;
		}

		for(int j=0;j<=K;j++) pf[j]=((j-1>=0?pf[j-1]:0)+dp2[j])%mod;
	}

	cout<<dp2[K]<<"\n";

	return 0;
}

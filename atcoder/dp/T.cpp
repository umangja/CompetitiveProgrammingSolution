/*input
20
>>>><>>><>><>>><<>>
*/
#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7,N = 3005;
int dp[N][N]; // 
int pf[N];
int main()
{
	int n;cin>>n;
	string s;cin>>s;

	dp[1][1]=1;
	for(int last=1;last<=n;last++) pf[last]=1;
	for(int len=2;len<=n;len++)
	{
		for(int last=1;last<=len;last++)
		{

			if(s[len-2]=='<') dp[len][last]=pf[last-1];
			else dp[len][last]=((pf[n]-pf[last-1])%mod+mod)%mod;

			// for(int sl=1;sl<=len;sl++)
			// {
			// 	int cpy = sl;
			// 	if(cpy>=last) cpy++;
			// 	if(s[len-2]=='<' && cpy<last) dp[len][last]+=dp[len-1][sl];
			// 	if(s[len-2]=='>' && cpy>last) dp[len][last]+=dp[len-1][sl];
			// }
		}
		for(int last=1;last<=n;last++) pf[last]=(pf[last-1]+dp[len][last])%mod;

	}

	int ans = 0;
	for(int last=1;last<=n;last++) ans+=dp[n][last],ans%=mod;
	cout<<ans<<"\n";

	return 0;
}

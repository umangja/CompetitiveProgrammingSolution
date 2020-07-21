/*input
100
1
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+5,N2 = 101,mod=1e9+7;
int dp[2][N2][N];
int D;

int fun(int pos,int f,int sum,string &s) //f==0 prefix equal
{
	if(pos==(int)s.size()) return (sum==0);
	if(dp[f][sum][pos]!=-1) return dp[f][sum][pos];

	int L = 9;
	if(!f) L = s[pos]-'0';

	int ans=0;
	for(int d=0;d<=L;d++)
	{
		int nd = 1;
		if(f==0 && d==L) nd=0;

		int nsum = (sum+d)%D;
		ans+=fun(pos+1,nd,nsum,s);
		ans%=mod; 
	}

	return dp[f][sum][pos]=ans;

}	

int main()
{
	memset(dp,-1,sizeof dp);
	string s;cin>>s;
	cin>>D;
	int ans = fun(0,0,0,s)-1;
	ans%=mod;
	if(ans<0) ans+=mod; 
	cout<<ans<<"\n";

	return 0;
}

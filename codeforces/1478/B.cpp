/*input
2
3 9
24 25 27
10 7
51 52 53 54 55 56 57 58 59 60

*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long int

const ll N = 1000;
vector<vector<ll>> dp(N,vector<ll> (10,0));

ll check(ll n,ll d){
	while(n>0){
		ll dd = n%10;
		n/=10;
		if(dd==d) return 1;
	}
	return 0;
}

int main()
{
	int T = 1;  
	cin>>T;

	for(ll d=1;d<10;d++){
		for(ll i=1;i<N;i++){
			if(check(i,d)==1) dp[i][d] = 1;
			else {
				for(int j=1;j<i && dp[i][d]==0;j++) if(dp[j][d]==1 && dp[i-j][d]==1) dp[i][d]=1;
			} 
		}
	}


	while(T--)
	{
		ll q,d;cin>>q>>d;
		while(q--){
			ll n;cin>>n;
			if(n>=N) cout<<"Yes\n";
			else cout<<(dp[n][d]==1?"Yes\n":"No\n");
		}
	}
	return 0;
}

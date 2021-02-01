/*input
4 40 6
92 21 82 46
3 56
1 72
4 28
1 97
2 49
2 88


*/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define ll long long int 

const ll mod = 1e9+7;

ll n,K,q;
vector<ll> a;

int main() {
    cin>>n>>K>>q;
    K++;
    
	a.assign(n,0);
	for(int i=0;i<n;i++) cin>>a[i];
	
	vector<ll> cnt(n,0);
	vector<vector<ll>> dp(n,vector<ll> (K+1,0));
	for(int k=1;k<=K;k++){
		for(int i=0;i<n;i++){
			if(k==1) dp[i][k]=1;
			else {
				dp[i][k] = 0;
				if(i+1<n)  dp[i][k] += dp[i+1][k-1];
				if(i-1>=0) dp[i][k] += dp[i-1][k-1];

				if(dp[i][k]>=mod) dp[i][k]-=mod;

			}
			// cout<<i+1<<" "<<k<<" "<<dp[i][k]<<"\n";
		}
	}

	vector<vector<ll>> dp2(n,vector<ll> (K+1,0));

	for(int k=K;k>=1;k--){
		for(int i=0;i<n;i++){
			if(k==K) dp2[i][k] = 1;
			
			cnt[i] += (dp[i][k] * dp2[i][k])%mod;
			if(cnt[i]>=mod) cnt[i]-=mod;

			if(i+1<n){
				dp2[i+1][k-1] += dp2[i][k];
				if( dp2[i+1][k-1]>=mod) dp2[i+1][k-1]-=mod;
			}  
			if(i-1>=0){
				dp2[i-1][k-1] += dp2[i][k];
				if( dp2[i-1][k-1]>=mod) dp2[i-1][k-1]-=mod;
			} 

		}
	}


	// for(int i=0;i<n;i++) cout<<cnt[i]<<" "; cout<<"\n";
	
	ll sum = 0;
	for(int i=0;i<n;i++){
		sum += (a[i]*cnt[i])%mod;
		if(sum>=mod) sum-=mod;
	} 

	// cout<<sum<<"\n";
	
	while(q--){
	    int x,y;cin>>x>>y;
	    x--;
	   
	   	sum -= (a[x]*cnt[x])%mod;

	   	if(sum<0) sum+=mod;

	   	a[x] = y;

	   	sum += (a[x]*cnt[x])%mod;

	   	if(sum>=mod) sum-=mod;
	    
	    cout<<sum<<"\n";
	    
	}
	
	return 0;
}
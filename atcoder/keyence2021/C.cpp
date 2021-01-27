/*input
3 3 5
2 3 D
1 3 D
2 1 D
1 2 X
3 1 R




*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

const ll mod = 998244353,N = 5005;
ll H,W,K;
vector<vector<char>> mat(N,vector<char> (N,'.'));
vector<vector<ll>>  dp(N,vector<ll> (N,-1)),row(N,vector<ll> (N,0)),col(N,vector<ll> (N,0));
vector<ll> power3(N,0);


int main()
{
	cin>>H>>W>>K;
	for(int i=0;i<K;i++){
		ll x,y;cin>>x>>y;
		x--,y--;
		char c;cin>>c;
		mat[x][y] = c;
	}

	for(ll x=0;x<H;x++){
		for(ll y=W-1;y>=0;y--){
			row[x][y] = (mat[x][y]=='.') + (y!=W-1?row[x][y+1]:0);
		}
	}

	for(ll y=0;y<W;y++){
		for(ll x=H-1;x>=0;x--){
			col[x][y] = (mat[x][y]=='.') + (x!=H-1?col[x+1][y]:0);
		}
	}

	power3[0]=1;
	for(ll i =1;i<N;i++){
		power3[i] = (power3[i-1]*3)%mod;
	}


	for(ll x=H-1;x>=0;x--)
	{
		for(ll y=W-1;y>=0;y--)
		{

			if(x==H-1 && y==W-1) { dp[x][y] = ((mat[x][y]=='.')?3:1); continue; }

			ll ans = 0;
			if(mat[x][y]=='R'){
				if(y+1<W){
					ans = (ans + (dp[x][y+1] * power3[col[x][y]])%mod);
				} 
			}
			else if(mat[x][y]=='D'){
				if(x+1<H){
					ans = (ans + (dp[x+1][y] * power3[row[x][y]])%mod);
				} 
			}
			else if(mat[x][y]=='X'){
				if(y+1<W){
					ans = (ans + (dp[x][y+1] * power3[col[x][y]])%mod);
				} 
				if(x+1<H){
					ans = (ans + (dp[x+1][y] * power3[row[x][y]])%mod);
					if(ans>=mod) ans-=mod;
				} 
			}
			else{
				if(y+1<W){
					ll val = (dp[x][y+1] * power3[col[x+1][y]])%mod;
					val*=2;
					if(val>=mod) val-=mod;
					ans +=val; 
				} 
				if(x+1<H){
					ll val = 2*(dp[x+1][y] * power3[row[x][y+1]])%mod;
					if(val>=mod) val-=mod;
					ans+=val;
					if(ans>=mod) ans-=mod;
				} 
			}
			dp[x][y]=ans;
		}
	}
	cout<<dp[0][0]<<"\n";

	return 0;
}

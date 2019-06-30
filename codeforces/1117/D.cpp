/*input
4 2
*/


//assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
#include<bits/stdc++.h>
using namespace std;
#define ll          long long
#define pb          push_back
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define vs			vector< string >
#define vvi         vector< vector< ll > >
#define all(it,a)   for(auto it=(a).begin();it!=(a).end();it++) 
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define inf         1000000007
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define repr(i,a,b) for(ll int i=a;i>b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define mp          make_pair
#define graph(n)    adj(n,vector< ll > () )

ll n,m;
const ll M = 101;
const ll MOD = 1e9+7;
vvi v(M,vector< ll > (M));

void mul(vvi &a,vvi &b)
{
	vvi ans(m,vector< ll > (m));
	rep(i,0,m)
	{
		rep(j,0,m)
		{
			ans[i][j]=0;
			rep(k,0,m)
				ans[i][j]=(ans[i][j]%MOD+((a[i][k]%MOD)*(b[k][j]%MOD))%MOD)%MOD;
		}
	}

	rep(i,0,m)
		rep(j,0,m)
			v[i][j]=ans[i][j];
}


ll power(ll y)
{
	vvi cpy(m,vector< ll > (m));

	rep(i,0,m)
		rep(j,0,m)
			cpy[i][j]=v[i][j];

	if(y==0)
		return v[0][0]%MOD;

	if(y!=1)
	{
		power(y/2);
		mul(v,v);
		if(y%2==1)
			mul(v,cpy);
	}

	ll s=0;
	rep(j,0,m)
		s=(s%MOD+v[0][j]%MOD)%MOD;
	return s;
}

ll f(ll n)
{
	rep(i,0,M)
	{
		rep(j,0,M)
		{
			if((i==0 && j==0) || (i==0 && j==m-1) || i-1==j)
				v[i][j]=1;
			else
				v[i][j]=0;			
		}
	}

	return power(n-m+1);
}

int solve()
{
	cin>>n>>m;
	if(n<m)
		cout<<"1";
	else
		cout<<f(n);



	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll t=1;
	//cin>>t;
	while(t--)
		solve();
}
/*input
7 5
3 2 5 4
0
3 2 1 5
1 1
2 6 7


*/


//assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
#include<bits/stdc++.h>
using namespace std;
#define ll          long long
#define pb          push_back
#define pii         pair<ll int,ll int>
#define vpii        vector< pii >
#define vi          vector<ll int>
#define vs			vector< string >
#define vvi         vector< vector< ll > >
#define inf			1e18
#define all(it,a)   for(auto it=(a).begin();it!=(a).end();it++) 
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define repr(i,a,b) for(ll int i=a;i>b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define mp          make_pair
#define graph(n)    adj(n,vector< ll > () )
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll N =5e5+5;
vpii subsets(N);
vi siz(N,1);

void init()
{
	rep(i,0,N)
		subsets[i]=mp(i,0);
}

ll find_parent(ll x)
{
	if(subsets[x].F!=x)
		return subsets[x].F=find_parent(subsets[x].F);
	return x;
}

void merge(ll x,ll y)
{
	ll x_p = find_parent(x);
	ll y_p = find_parent(y);

	if(x_p==y_p)
		return;

	if(subsets[x_p].S<subsets[y_p].S)
	{
		subsets[x_p].F=y_p;
		siz[y_p]+=siz[x_p];		
	}
	else if(subsets[x_p].S>subsets[y_p].S)
	{
		subsets[y_p].F=x_p;
		siz[x_p]+=siz[y_p];		
	}
	else
	{
		subsets[x_p].F=y_p;
		subsets[y_p].S++;
		siz[y_p]+=siz[x_p];		
	}

	return;
}

int solve()
{
	init();
	ll n,m;cin>>n>>m;
	rep(i,0,m)
	{
		ll k,f;cin>>k;
		if(k>=1)
			cin>>f;
		rep(j,0,k-1)
		{
			ll x;cin>>x;
			merge(x,f);
		}
	}

	rep(i,1,n+1)
	{
		cout<<siz[find_parent(i)]<<" ";
	}
	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll t=1;
	//cin>>t;
	while(t--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}
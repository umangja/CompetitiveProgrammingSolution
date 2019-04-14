/*input
12
8 7
2 3
3 4
4 5
5 2
6 7
7 8
8 6
1 0
2 1
1 2
3 3
1 2
2 3
1 3
3 2
2 3
3 1
4 4
1 2
2 3
3 4
4 1
4 4
1 2
2 3
3 1
4 1
6 9
1 4
1 5
1 6
2 4
2 5
2 6
3 4
3 5
3 6
100000 0
1000 5
55 56
56 57
57 58
58 59
59 55
11 11
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
10 11
11 1
10 12
1 2
2 3
3 4
4 1
1 5
5 6
6 7
7 1
1 8
8 9
9 10
10 1

*/


//assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
#include<bits/stdc++.h>
using namespace std;
#define ll          long long
#define pb          push_back
#define	endl		'\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define is_empty(v) v.empty()
#define vs			vector< string >
#define vvi			vector< vector< ll,ll > >
#define all(it,a)   for(auto it=(a).begin();it!=(a).end();it++) 
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define inf         1000000007
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define repr(i,a,b) for(ll int i=a;i>b;i--)
#define reprr(i,a,b) for(ll int i=a;i>=b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define sum(v)      accumulate(v.begin(),v.end(),(ll)0)
//map <long long int,long long int> ma;
//set <long long int, greater <long long int> > s;
const ll N = 3*1e5+5;
const ll mod = 998244353;
vector< vector< ll > > adj(N,vector< ll > ());
vi c(N);
ll a=0,b=0;
ll f=1;
vi p(N);
void init(ll n)
{
	rep(i,0,n+1)
	{
		c[i]=-1;
		adj[i].clear();
	}
}

void DFS(ll root,ll col)
{
	c[root]=col;
	if(col==0)
		a++;
	else if(col==1)
		b++;
	rep(i,0,sz(adj[root]))
	{
		ll ch = adj[root][i];
		if(c[ch]==-1)
		{
			DFS(ch,col^1);
		}
		else 
		{
			if(c[ch]==col)
			{
				f=0;
			}
		}
	}

}


int solve()
{
	ll n,m;cin>>n>>m;
	init(n);
	rep(i,0,m)
	{
		ll x,y;cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	ll ans=1;
	rep(i,1,n+1)
	{
		if(c[i]==-1)
		{
			// cout<<i<<" ";
			a=0;b=0,f=1;
			DFS(i,0);
			if(f)
			{
				ans=((ans%mod)*((p[a]+p[b])%mod))%mod;
			}
			else
			{
				cout<<0<<"\n";return 0;
			}
			
		}
	}

	cout<<ans<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll t=1;
	cin>>t;
	p[0]=1;
	rep(i,1,N)
	{
		p[i]=(p[i-1]*2)%mod;
	}
	while(t--)
		solve();
}
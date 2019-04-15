/*input
123 45 67


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

const ll mod = 998244353;
const ll N = 2005;
ll c[N][N];	
vi f(N);
ll p(ll x,ll y)
{
	if(x==1 || y==0)
		return 1;
	if(x==0)
		return 0;

	if(y%2==0)
		return p((x*x)%mod,y/2);
	else
		return (x*(p((x*x)%mod,(y-1)/2)%mod))%mod;
}

void ncr()
{
	rep(i,0,N)
	{
		rep(j,0,i+1)
		{
			if(j==0 || i==j)
				c[i][j]=1;
			else
				c[i][j] = (c[i-1][j-1]+c[i-1][j])%mod;
		}
	}
}

int solve()
{
	ll n,m,k;cin>>n>>m>>k;
	ncr();

	cout<< (((c[n-1][k]*m)%mod)*p(m-1,k))%mod;
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
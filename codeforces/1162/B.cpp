/*input
3 2
1 3
2 4
5 10
3 1
3 6
4 8


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

const ll N = 52;
vector< vector< ll > > a(N,vector< ll > (N) ),b(N,vector< ll > (N) );

void s(ll i,ll j)
{
	swap(a[i][j],b[i][j]);
}
ll f=0;
int solve()
{
	ll n,m;cin>>n>>m;
	
	rep(i,0,n)
	rep(j,0,m)
	cin>>a[i][j];

	rep(i,0,n)
	rep(j,0,m)
	cin>>b[i][j];

	rep(i,0,n)
	{
		rep(j,0,m)
		{
			if(a[i][j]>b[i][j])
				s(i,j);
		}
	}


	rep(i,0,n)
	{
		rep(j,0,m)
		{
			if( j<m-1 && !((j<m-1 && a[i][j]<a[i][j+1] && b[i][j]<b[i][j+1])))
				f=1;

			if(i<n-1 && !((i<n-1 && a[i][j]<a[i+1][j] && b[i][j]<b[i+1][j])))
				f=1;


			if(f)
			{
				cout<<"Impossible";
				return 0;
			}
		}
	}

	cout<<"Possible";

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
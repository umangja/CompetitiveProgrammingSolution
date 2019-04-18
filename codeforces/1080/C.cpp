/*input
5
2 2
1 1 2 2
1 1 2 2
3 4
2 2 3 2
3 1 4 3
1 5
1 1 5 1
3 1 5 1
4 4
1 1 4 2
1 3 4 4
3 4
1 2 4 2
2 1 3 3

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

ll f(ll a,ll b)
{
	return (a/2)*(b/2)+((a+1)/2)*((b+1)/2);
}

ll W(ll a,ll b,ll c,ll d)
{
	return f(c,d)-f(c,b-1)-f(a-1,d)+f(a-1,b-1);
}

ll B(ll a,ll b,ll c,ll d)
{
	return (c-a+1)*(d-b+1)-W(a,b,c,d);
}

int solve()
{
	ll n,m;cin>>n>>m;
	ll white = f(n,m);
	ll black = n*m-white;
	// cout<<white<<" "<<black<<"\n";

	vi a(4),b(4);
	rep(i,0,4)
	cin>>a[i];

	rep(i,0,4)
	cin>>b[i];

	ll t = B(a[0],a[1],a[2],a[3]);
	white+=t;
	black-=t;
	// cout<<white<<" "<<black<<"\n";

	t = W(b[0],b[1],b[2],b[3]);
	black+=t;
	white-=t;
	// cout<<white<<" "<<black<<"\n";

	vi c(4);
	rep(i,0,4)
	{
		if(i<2)
			c[i]=max(a[i],b[i]);
		else
			c[i]=min(a[i],b[i]);
	}

	if(c[0]<=c[2] && c[1]<=c[3])
	{
		t = B(c[0],c[1],c[2],c[3]);
		black+=t;
		white-=t;
	}

	cout<<white<<" "<<black<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll t=1;
	cin>>t;
	while(t--)
		solve();
}
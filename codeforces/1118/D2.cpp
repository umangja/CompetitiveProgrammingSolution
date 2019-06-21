/*input
100 550
12 7 8 16 13 6 12 6 10 12 13 10 6 12 9 8 5 13 7 13 5 14 10 13 9 6 14 14 6 11 13 13 8 3 8 13 12 8 13 8 14 10 15 8 12 8 10 13 13 13 7 8 12 9 7 10 16 10 10 4 9 9 11 8 8 13 8 15 11 8 9 6 6 16 12 11 9 8 10 9 12 8 11 9 8 10 7 13 6 13 10 9 15 9 3 11 5 17 7 13





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
ll n,m;
vi a(2e5+5,0);

ll fun(ll mid)
{
	ll ans=0;
	ll k=0,i=0;
	ll day=1;
	while(i<n)
	{
		k = (day-1)/mid;
		ans+=max((ll)0,a[i]-k);
		if(ans>=m)
			return 1;

		i++;
		day++;
	}

	return 0;

}
int solve()
{
	cin>>n>>m;
	ll s=0;
	rep(i,0,n)
	{
		cin>>a[i];
		s+=a[i];
	}

	if(m>s)
	{
		cout<<"-1";
		return 0;
	}

	sort(a.begin(), a.end(),greater<  > () ); 

	ll low=1,high=n+1;
	while(low<high)
	{
		ll mid = low+(high-low)/2;
		if(fun(mid))
			high=mid;
		else
			low=mid+1;
	}

	cout<<low;
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
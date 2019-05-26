/*input
898207
99745 99746 99748 99752 99760 99776 99808 99872 100000



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


int solve()
{
	ll v;cin>>v;
	vi a(9);
	ll mini = 1e7;
	rep(i,0,9)
	{
		cin>>a[i];
		mini=min(mini,a[i]);
	}

	vi b;
	ll max_d = v/mini;

	if(max_d==0)
	{
		cout<<"-1";return 0;
	}

	rep(i,0,9)
	{
		if(v/a[i]==max_d)
			b.pb(i);
	}

	ll di = *min_element(b.begin(), b.end());

	string ans="";
	rep(i,0,max_d)
		ans+=('0'+(di+1));
	// vi c;
	v-=max_d*a[di];
	ll index=0;
	for(ll i=8;i>=di;i--)
	{
		while(index<max_d)
		{
			if(v+a[di]-a[i]>=0)
			{
				ans[index]='0'+i+1;
				v = v+a[di]-a[i];
				index++;
			}
			else
				break;
		}
	}

	cout<<ans;


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
/*input
3
8
1 0
4 1
2 0
4 1
5 1
6 1
3 0
2 0
4
1 1
1 1
2 1
2 1
9
2 0
2 0
4 1
4 1
4 1
7 0
7 1
7 0
7 1

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

bool cmp(pair< ll,ll > a,pair< ll,ll > b)
{
	if(a.S==b.S)
		return b.F<a.F;
	return b.S<a.S;
}

int solve()
{
	ll n;cin>>n;
	vector< pair< ll,ll > > fq(n+1);
	rep(i,0,n+1)
		fq[i]=mp(0,0);

	rep(i,1,n+1)
	{
		ll x,y;cin>>x>>y;
		fq[x].F++;
		if(y==1)
			fq[x].S++;
	}

	// rep(i,0,n+1)
		// cout<<fq[i].F<<" "<<fq[i].S<<"\n";

	// sort(fq.begin(), fq.end());
	// reverse(fq.begin(), fq.end());

	// rep(i,0,n+1)
		// cout<<fq[i].F<<" "<<fq[i].S<<"\n";


	// ll ans1 = fq[0].S,ans2 = fq[0].F;
	// ll last = fq[0].S;

	priority_queue< pair< ll,ll > > q;
	rep(i,0,n+1)
		q.push(fq[i]);

	// all(it,q)
	// 	cout<<it->F<<" "it->S<<"\n";

	// cout<<"ok\n";

	ll ans1 = 0,ans2=0,last=1e18;

	while(sz(q)>0)
	{
		pair< ll,ll > p = q.top();
		q.pop();

		if(p.F==0)
			break;
		if(p.F>=last)
		{
			p.F = last-1;
			if(p.F<0)
				p.F=0;
			q.push(mp(p.F,p.S));
		}
		else
		{
			last=p.F;

			ans1+=p.F;
			ans2+=min(p.S,p.F);
		}
	}
	// rep(i,1,n+1)
	// {
	// 	ll freq = fq[i].S;

	// 	if(freq>=last)
	// 		last--;

	// 	last = min(last,freq);
	// 	last = max((ll)0,last);

	// 	ans1 += last;

	// 	ans2 += min(fq[i].F,last);
	// }

	cout<<ans1<<" "<<ans2<<"\n";
	return 0;
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
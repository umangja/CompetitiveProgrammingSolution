/*input

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
#define inf			(ll)1e18
#define all(it,a)   for(auto it=(a).begin();it!=(a).end();it++) 
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define repr(i,a,b) for(ll int i=a;i>b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define mp          make_pair
#define whatis(x)   cout << #x << " is " << x << "\n";
#define graph(n)    adj(n,vector< ll > () )
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int solve()
{
	ll n,m;cin>>n>>m;
	vi x(n);
	vi ans;
	ll ansd=0;


	set<ll> oc;
	rep(i,0,n) cin>>x[i],oc.insert(x[i]);
	sort(x.begin(), x.end());

	vi l(n),r(n);
	l=x;
	r=x;

	set<ll> con;
	rep(i,0,n) con.insert(i);
	ll dis=1;

	ll cnt=0;
	ll k=0;
	while(cnt<m)
	{
		set<ll> rem;
		all(it,con)
		{
			k++;
			ll p = *it;
			if(p!=0 && p!=(n-1))
			{
				if(x[p]+dis>=x[p+1] && x[p]-dis<=x[p-1])
				{
					rem.insert(p);
					continue;
				}
			}

			if((p!=0 && x[p]-dis>r[p-1]) || p==0 ) ans.pb(x[p]-dis),l[p]=x[p]-dis,cnt++,ansd+=dis;
			if(cnt>=m) break;

			if((p!=n-1 && x[p]+dis<l[p+1]) || p==n-1) ans.pb(x[p]+dis),r[p]=x[p]+dis,cnt++,ansd+=dis;
			if(cnt>=m) break;
		}

		dis++;
		all(it,rem) con.erase(*it);
	}
	
	// whatis(k);

	cout<<ansd<<"\n";
	sort(ans.begin(), ans.end());
	rep(llll,0,m) cout<<ans[llll]<<" ";

	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll test_cases=1;
	//cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}
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
	ll n;cin>>n;
	vi cnt(4,0);
	string s;cin>>s;
	ll ansl=-1,ansr = -1;

	map<char,ll> m;
	m['L'] = 0;
	m['R'] = 1;
	m['U'] = 2;
	m['D'] = 3;

	set< pii > st;
	st.insert(mp(0,0));
	map< pii , ll > idx;
	idx[mp(0,0)] = -1;

	rep(i,0,n)
	{
		cnt[m[s[i]]]++;
		pii p = mp(cnt[0] - cnt[1],cnt[2]-cnt[3]);
		// cout<<p.F<<" "<<p.S<<"\n";
		if(st.find(p)!=st.end())
		{
			ll last = idx[p];
			// whatis(last);
			// whatis(i);
			if(i-last<ansr-ansl+1 || ansl==-1)
			{
				ansr = i;
				ansl = last+1;
			}
		}
		st.insert(p);
		idx[p]=i;
	}

	if(ansl==-1) cout<<"-1\n";
	else cout<<ansl+1<<" "<<ansr+1<<"\n";

	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll test_cases=1;
	cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}
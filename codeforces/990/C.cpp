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
	vs a(n);
	ll r=0;
	map<ll,ll> r1,r2;
	rep(i,0,n) cin>>a[i];
	rep(i,0,n)
	{
		stack<char> st;
		string s   = a[i];
		rep(j,0,sz(s))
		{
			char c =  s[j];
			if(sz(st)==0) st.push(c);
			else
			{
				if(c==')' && st.top()=='(') st.pop();
				else st.push(c);
			}
		}

		if(sz(st)==0) r++;
		else
		{
			ll f=0;
			
			ll siz = sz(st);

			char c = st.top();
			st.pop();

			while(sz(st)!=0)
			{
				if(st.top()!=c)
				{
					f=1;
					break;
				} 
				st.pop();
			}

			if(f==0 && c=='(') r1[siz]++;
			else if(f==0 && c==')') r2[siz]++;
		}

	}

	ll ans = r*r;
	all(it,r1) ans+=(it->S)*r2[it->F];

	cout<<ans<<"\n";
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
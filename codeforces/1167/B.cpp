/*input
368
672
64
128
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
#define inf			1e18
#define all(it,a)   for(auto it=(a).begin();it!=(a).end();it++) 
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define repr(i,a,b) for(ll int i=a;i>b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define mp          make_pair
#define graph(n)    adj(n,vector< ll > () )
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vi a = {4,8,15,16,23,42};
set< ll > s={4,8,15,16,23,42};
ll ans;

ll query(ll i,ll j)
{
	cout<<"? "<<i<<" "<<j<<"\n";
	cout.flush();
	cin>>ans;
	return ans;
}

int solve()
{
	vi v(4);
	rep(i,0,4)
		v[i]=query(1,i+2);

	rep(i,0,6)
	{
		ll f=1;
		ll j=0;
		for(;j<4;j++)
		{
			if(v[j]%a[i]!=0 || find(a.begin(), a.end(),v[j]/a[i])==a.end())
				f=0;
		}

		if(f)
		{
			ll a1=a[i],a2=v[0]/a1,a3=v[1]/a1,a4=v[2]/a1,a5=v[3]/a1;
			s.erase(a1);
			s.erase(a2);
			s.erase(a3);
			s.erase(a4);
			s.erase(a5);
			ll a6 = *s.begin();

			cout<<"! "<<a1<<" "<<a2<<" "<<a3<<" "<<a4<<" "<<a5<<" "<<a6<<"\n";
			cout.flush();
			exit(0);
		}
	}
	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

	// ios_base::sync_with_stdio(false);
	// cin.tie(0);
	// cout.tie(0);

	ll t=1;
	//cin>>t;
	while(t--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}
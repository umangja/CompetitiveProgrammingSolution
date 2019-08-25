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
	vi a(n);
	rep(i,0,n) cin>>a[i];

	ll l=-1,r=-1;
	ll mr=0;
	rep(i,0,n-1)
	{
		if(a[i+1]<a[i])
		{
			if(l!=-1)
			{
				mr=1;
				break;
			} 

			ll j=i;
			l=j;
			while(j<n-1 && a[j+1]<=a[j]) j++;
			r=j;
			i=j;
		}
	}

	if(mr) cout<<"no\n";
	else
	{
		// cout<<l<<" "<<r<<"\n";
		if(l!=-1) reverse(a.begin()+l,a.begin()+r+1);
		else l=0,r=0;
		if(is_sorted(a.begin(), a.end())) cout<<"yes\n"<<l+1<<" "<<r+1<<"\n";
		else cout<<"no\n";
	}
	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll test_cases=1;
// 	cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
// 	cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int solve()
{

	ll n;
	cin>>n;
	if(n==2)
	{
		cout<<1<<"\n";
		return 0;
	}
	set<ll> ft;

	for(ll i=1;i*i<=n;i++)
	{
		if(n%i==1 ) ft.insert(i),ft.insert(n/i);
		if(n%i==0)
		{
			ll lt = n;
			while( i>1 && (lt%i)==0 ) lt/=i;
			if(lt%i==1) ft.insert(i);

			lt = n;
			while((n/i)>1 && (lt%(n/i))==0) lt/=(n/i);
			if(lt%(n/i)==1) ft.insert(n/i);
		} 
	}

	ll ans = sz(ft)+1;

	// ll ans_temp=0;
	// rep(k,2,n+1)
	// {
	// 	ll dup = n;
	// 	while(dup%k==0) dup/=k;
	// 	while(dup>k && dup>1) dup-=k;
	// 	if(dup==1)
	// 	{
	// 		// whatis(k);
	// 		ans_temp++;
	// 	} 
	// }

	// cout<<ans_temp<<"\n";

	// all(it,ft) cout<<*it<<"\n";

	// assert(ans_temp==ans);

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